#include "package.h"
#include <boost/filesystem.hpp>
#include <fstream>
#include <errno.h>
#include <limits.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>



#define LIBDPKG_VOLATILE_API 1
#define DEBMAGIC		"debian-binary"
#define ARCHIVEVERSION		"2.0"
#define OLDARCHIVEVERSION	"0.939000"
#define ADMINMEMBER		"control.tar"
#define DATAMEMBER		"data.tar"
#define BUILDCONTROLDIR		"DEBIAN"

//#include <dpkg/i18n.h>
#include <dpkg/c-ctype.h>
#include <dpkg/dpkg.h>
#include <dpkg/dpkg-db.h>
#include <dpkg/path.h>
#include <dpkg/treewalk.h>
#include <dpkg/varbuf.h>
#include <dpkg/fdio.h>
#include <dpkg/buffer.h>
#include <dpkg/subproc.h>
#include <dpkg/command.h>
#include <dpkg/compress.h>
#include <dpkg/ar.h>
#include <dpkg/options.h>
#include <dpkg/options.h>
//#define TAR "t.tar"



Pakage::Pakage(string name, string version, string description)
{
	this->name = name;
	this->version = version;
	this->descr = description;
}



int Pakage::create_control(string path_dir_root)
{
	string path_dir_dpkg = path_dir_root;
	path_dir_dpkg += "/build_dpkg";
	path_dir_dpkg += "/"+ name +"/DPKG/DEBIAN";	
	
	boost::filesystem::create_directories(path_dir_dpkg.c_str());
	string file_control = path_dir_dpkg+"/control";
	
	// удаляем файл если есть
	if(boost::filesystem::exists(file_control.c_str()))
	{
		boost::filesystem::remove(file_control.c_str());
	} 	
	
	// создаём файл control
	
	ofstream ofs(file_control.c_str());
	
	ofs << "Package: " << name << "\n";
	ofs << "Architecture: " << arch << "\n";
	ofs << "Version: " << version  << "\n";
 	ofs << "Provides: " << name << "\n";
 	if(!replaces.empty())
 	{
 	ofs << "Replaces: " << replaces << "\n";
 	}
	
	ofs << "Maintainer: " << maintainer << "\n";
	ofs << "Section: " << section << "\n";
	ofs << "Depends: ";
	int depc = depends.size();

	
	for(int i = 0; i < depc; i++ )
	{
		if(i > 0)
		{
	 	ofs << ", ";
		}
		ofs <<  depends[i].get_name();
		ofs <<  "(>=" << depends[i].get_version() << ") ";
	}
	ofs <<  "\n";
	ofs << "Installed-Size: " << size << "\n";
	ofs << "Description: " << size << "\n";	 
	ofs.close();
	return 0;
}
void Pakage::add_depends(Pakage pkg)
{
	this->depends.push_back(pkg);
}


struct file_info {
  struct file_info *next;
  char *fn;
};

static struct file_info *
file_info_new(const char *filename)
{
  struct file_info *fi;

  fi = m_malloc(sizeof(*fi));
  fi->fn = m_strdup(filename);
  fi->next = NULL;

  return fi;
}

static void
file_info_free(struct file_info *fi)
{
  free(fi->fn);
  free(fi);
}

static struct file_info *
file_info_find_name(struct file_info *list, const char *filename)
{
  struct file_info *node;

  for (node = list; node; node = node->next)
    if (strcmp(node->fn, filename) == 0)
      return node;

  return NULL;
}

/**
 * Add a new file_info struct to a single linked list of file_info structs.
 *
 * We perform a slight optimization to work around a ‘feature’ in tar: tar
 * always recurses into subdirectories if you list a subdirectory. So if an
 * entry is added and the previous entry in the list is its subdirectory we
 * remove the subdirectory.
 *
 * After a file_info struct is added to a list it may no longer be freed, we
 * assume full responsibility for its memory.
 */
static void
file_info_list_append(struct file_info **head, struct file_info **tail,
                      struct file_info *fi)
{
  if (*head == NULL)
    *head = *tail = fi;
  else
    *tail = (*tail)->next =fi;
}

/**
 * Free the memory for all entries in a list of file_info structs.
 */
static void
file_info_list_free(struct file_info *fi)
{
  while (fi) {
    struct file_info *fl;

    fl=fi; fi=fi->next;
    file_info_free(fl);
  }
}



static void
control_treewalk_feed(const char *dir, int fd_out)
{
  struct treeroot *tree;
  struct treenode *node;

  tree = treewalk_open(dir, TREEWALK_NONE, NULL);
  for (node = treewalk_node(tree); node; node = treewalk_next(tree)) {
    char *nodename;

    nodename = str_fmt("./%s", treenode_get_virtname(node));
    	if (fd_write(fd_out, nodename, strlen(nodename) + 1) < 0) {
     		printf("failed to write filename to tar pipe (%s)", "control member");
	}
    free(nodename);
  }
  treewalk_close(tree);
}


struct compress_params compress_params_deb0 = {
  .type = COMPRESSOR_TYPE_GZIP,
  .strategy = COMPRESSOR_STRATEGY_NONE,
  .level = -1,
  .threads_max = -1,
};

struct tar_pack_options {
  intmax_t timestamp;
  const char *mode;
  bool root_owner_group;
};
 
 
typedef void filenames_feed_func(const char *dir, int fd_out);


void m_dup2_m(int oldfd, int newfd) {
  const char *const stdstrings[]= { "in", "out", "err" };

	printf("to dup for fd %d",newfd);

  if (dup2(oldfd,newfd) == newfd) return;



  onerr_abort++;
  if (newfd < 3) printf("failed to dup for std%s",stdstrings[newfd]);
  	printf("failed to dup for fd %d",newfd);
}

/**
 * Pack the contents of a directory into a tarball.
 */
static void
tarball_pack(const char *dir, filenames_feed_func *tar_filenames_feeder,
             struct tar_pack_options *options,
             struct compress_params *tar_compress_params, int fd_out)
{
  int pipe_filenames[2], pipe_tarball[2];
  pid_t pid_tar, pid_comp;

  /* Fork off a tar. We will feed it a list of filenames on stdin later. */
  m_pipe(pipe_filenames);
  m_pipe(pipe_tarball);
  pid_tar = subproc_fork();
  /*
  if (pid_tar == 0) {
    struct command cmd;
    char mtime[50];

    //m_dup2_m(pipe_filenames[0], 0);
    
    close(pipe_filenames[0]);
    close(pipe_filenames[1]);

    
    //m_dup2_m(pipe_tarball[1], 1);

    
    close(pipe_tarball[0]);
    close(pipe_tarball[1]);




	if (chdir(dir)) {
	      printf("failed to chdir to '%.255s'", dir);
	}

    snprintf(mtime, sizeof(mtime), "@%jd", options->timestamp);

    command_init(&cmd, TAR, "tar -cf");
    command_add_args(&cmd, "tar", "-cf", "-", "--format=gnu",
                           "--mtime", mtime, "--clamp-mtime", NULL);


                            
                      
    
    if (options->mode)
      command_add_args(&cmd, "--mode", options->mode, NULL);
    if (options->root_owner_group)
      command_add_args(&cmd, "--owner", "root:0", "--group", "root:0", NULL);
    command_add_args(&cmd, "--null", "--no-unquote", "--no-recursion",
                           "-T", "-", NULL);

	command_exec(&cmd);
    printf("command_exec dir %s mtime %d \n",dir, mtime);   
                          
    
  }
  */
  close(pipe_filenames[0]);
  close(pipe_tarball[1]);

  /* Of course we should not forget to compress the archive as well. */
  pid_comp = subproc_fork();
  if (pid_comp == 0) {
    close(pipe_filenames[1]);
    compress_filter(tar_compress_params, pipe_tarball[0], fd_out,"compressing tar member");
    exit(0);
  }
  close(pipe_tarball[0]);

  /* All the pipes are set, now lets start feeding filenames to tar. */
  tar_filenames_feeder(dir, pipe_filenames[1]);

  /* All done, clean up wait for tar and <compress> to finish their job. */
  close(pipe_filenames[1]);
  subproc_reap(pid_comp, "<compress> from tar -cf", 0);
  subproc_reap(pid_tar, "tar -cf", 0);
}

static void
check_conffiles(const char *ctrldir, const char *rootdir)
{
  FILE *cf;
  struct varbuf controlfile; // = VARBUF_INIT;
  char conffilenamebuf[MAXCONFFILENAME + 1];
  struct file_info *conffiles_head = NULL;
  struct file_info *conffiles_tail = NULL;

  varbuf_printf(&controlfile, "%s/%s", ctrldir, CONFFILESFILE);

  cf = fopen(controlfile.buf, "r");
  if (cf == NULL) {
    if (errno == ENOENT) {
      varbuf_destroy(&controlfile);
      return;
    }

    printf("error opening conffiles file");
  }

  while (fgets(conffilenamebuf, MAXCONFFILENAME + 1, cf)) {
    struct stat controlstab;
    char *conffilename = conffilenamebuf;
    int n;
    bool remove_on_upgrade = false;

    n = strlen(conffilename);
    if (!n)
      printf("empty string from fgets reading conffiles");

    if (conffilename[n - 1] != '\n')
      printf("conffile name '%s' is too long, or missing final newline", conffilename);

    conffilename[--n] = '\0';

    if (c_isspace(conffilename[0])) {
      /* The conffiles lines cannot start with whitespace; by handling this
       * case now, we simplify the remaining code. Move past the whitespace
       * to give a better error. */
      while (c_isspace(conffilename[0]))
        conffilename++;
      if (conffilename[0] == '\0')
          printf("empty and whitespace-only lines are not allowed in "
                   "conffiles");
      printf("line with conffile filename '%s' has leading white spaces", conffilename);
    }

    if (conffilename[0] != '/') {
      char *flag = conffilename;
      char *flag_end = strchr(flag, ' ');

      if (flag_end) {
        conffilename = flag_end + 1;
        n -= conffilename - flag;
      }

      /* If no flag separator is found, assume a missing leading slash. */
      if (flag_end == NULL || (conffilename[0] && conffilename[0] != '/'))
        printf("conffile name '%s' is not an absolute pathname", conffilename);

      flag_end[0] = '\0';

      /* Otherwise assume a missing filename after the flag separator. */
      if (conffilename[0] == '\0')
        printf("conffile name missing after flag '%s'", flag);

      if (strcmp(flag, "remove-on-upgrade") == 0)
        remove_on_upgrade = true;
      else
        printf("unknown flag '%s' for conffile '%s'", flag, conffilename);
    }

    varbuf_reset(&controlfile);
    varbuf_printf(&controlfile, "%s%s", rootdir, conffilename);
    if (lstat(controlfile.buf, &controlstab)) {
      if (errno == ENOENT) {
        if ((n > 1) && c_isspace(conffilename[n - 1]))
          printf("conffile filename '%s' contains trailing white spaces", conffilename);
        if (!remove_on_upgrade)
          printf("conffile '%.250s' does not appear in package", conffilename);
      } else
        printf("conffile '%.250s' is not stattable", conffilename);
    } else if (remove_on_upgrade) {
        printf("conffile '%s' is present but is requested to be removed", conffilename);
    } else if (!S_ISREG(controlstab.st_mode)) {
      printf("conffile '%s' is not a plain file", conffilename);
    }

    if (file_info_find_name(conffiles_head, conffilename)) {
      printf("conffile name '%s' is duplicated", conffilename);
    } else {
      struct file_info *conffile;

      conffile = file_info_new(conffilename);
      file_info_list_append(&conffiles_head, &conffiles_tail, conffile);
    }
  }

  file_info_list_free(conffiles_head);
  varbuf_destroy(&controlfile);

  if (ferror(cf))
    printf("error reading conffiles file");
  fclose(cf);
}

static const char *const maintainerscripts[] = {
  PREINSTFILE,
  POSTINSTFILE,
  PRERMFILE,
  POSTRMFILE,
  MAINTSCRIPT_FILE_CONFIG,
  NULL,
};

/**
 * Check control directory and file permissions.
 */
static void
check_file_perms(const char *ctrldir)
{
  struct varbuf path; // = VARBUF_INIT;
  const char *const *mscriptp;
  struct stat mscriptstab;

  varbuf_printf(&path, "%s/", ctrldir);
  if (lstat(path.buf, &mscriptstab))
    printf("unable to stat control directory");
  if (!S_ISDIR(mscriptstab.st_mode))
    printf("control directory is not a directory");
  if ((mscriptstab.st_mode & 07757) != 0755)
    printf("control directory has bad permissions %03lo (must be >=0755 and <=0775)",
           (unsigned long)(mscriptstab.st_mode & 07777));

  for (mscriptp = maintainerscripts; *mscriptp; mscriptp++) {
    varbuf_reset(&path);
    varbuf_printf(&path, "%s/%s", ctrldir, *mscriptp);
    if (!lstat(path.buf, &mscriptstab)) {
      if (S_ISLNK(mscriptstab.st_mode))
        continue;
      if (!S_ISREG(mscriptstab.st_mode))
        printf("maintainer script '%.50s' is not a plain file or symlink", *mscriptp);
      if ((mscriptstab.st_mode & 07557) != 0555)
        printf("maintainer script '%.50s' has bad permissions %03lo (must be >=0555 and <=0775)",               *mscriptp, (unsigned long)(mscriptstab.st_mode & 07777));
    } else if (errno != ENOENT) {
      printf("maintainer script '%.50s' is not stattable", *mscriptp);
    }
  }

  varbuf_destroy(&path);
}




static char *
gen_dest_pathname_from_pkg(const char *dir, struct pkginfo *pkg)
{
  return str_fmt("%s/%s_%s_%s%s", dir, pkg->set->name,
                 versiondescribe(&pkg->available.version, vdew_never),
                 pkg->available.arch->name, DEBEXT);
}


static char *
gen_dest_pathname(const char *dir, const char *dest)
{
  if (dest) {
    struct stat dest_stab;

    if (stat(dest, &dest_stab)) {
      if (errno != ENOENT)
        printf("unable to check for existence of archive '%.250s'", dest);
    } else if (S_ISDIR(dest_stab.st_mode)) {
      /* Need to compute the destination name from the package control file. */
      return NULL;
    }

    return m_strdup(dest);
  } else {
    char *pathname;

    pathname = m_malloc(strlen(dir) + sizeof(DEBEXT));
    strcpy(pathname, dir);
    path_trim_slash_slashdot(pathname);
    strcat(pathname, DEBEXT);

    return pathname;
  }
}

#include <dpkg/parsedump.h>
//#define VARBUF_OBJECT (struct varbuf)VARBUF_INIT
static enum parsedbtype
parse_get_type(struct parsedb_state *ps, enum parsedbflags flags)
{
  if (flags & pdb_recordavailable) {
    if (flags & pdb_single_stanza)
      return pdb_file_control;
    else
      return pdb_file_available;
  } else {
    if (flags & pdb_single_stanza)
      return pdb_file_update;
    else
      return pdb_file_status;
  }
}


struct parsedb_state *
parsedb_openl(const char *filename, enum parsedbflags flags)
{
  struct parsedb_state *ps;
  int fd;

  /* Special case stdin handling. */
  if (flags & pdb_dash_is_stdin && strcmp(filename, "-") == 0)
    return parsedb_new(filename, STDIN_FILENO, flags);
  
 
  fd = open(filename, O_RDONLY);
  if (fd == -1 && !(errno == ENOENT && (flags & pdb_allow_empty)))
  {
  	 printf("failed to open package info file '%x' for reading", filename);
  }
  ps = parsedb_new(filename, fd, flags | pdb_close_fd);
 // push_cleanup(cu_closefd, ~ehflag_normaltidy, 1, &ps->fd);
  
 return ps;
}



static struct pkginfo *
check_control_file( string ctrldir)
{
  struct pkginfo *pkg;
  string controlfile = ctrldir;
  controlfile += "/";
  controlfile += CONTROLFILE;
  
  struct parsedb_state *ps;
  int count;

  ps = parsedb_openl(controlfile.c_str(), pdb_parse_binary);
  parsedb_load(ps);
  count = parsedb_parse(ps, &pkg);
  //parsedb(controlfile.c_str(), pdb_parse_binary, &pkg);

  if (strspn(pkg->set->name, "abcdefghijklmnopqrstuvwxyz0123456789+-.") !=
      strlen(pkg->set->name))
    printf("package name has characters that aren't lowercase alphanums or '-+.'");
  if (pkg->available.arch->type == DPKG_ARCH_NONE ||
      pkg->available.arch->type == DPKG_ARCH_EMPTY)
    printf("package architecture is missing or empty");
  if (pkg->priority == PKG_PRIO_OTHER)
    printf("'%s' contains user-defined Priority value '%s'", controlfile.c_str(), pkg->otherpriority);

  return pkg;
}


static struct pkginfo *
check_control_area(const char *ctrldir, string rootdir)
{
  
  struct pkginfo *pkg;
  int warns;
 
  /* Start by reading in the control file so we can check its contents. */
  
  pkg = check_control_file(ctrldir);
 
  check_file_perms(ctrldir);
   
  check_conffiles(ctrldir, rootdir.c_str());
  warns = warning_get_count();
  if (warns)
    printf("ignoring %d warning about the control file(s)", warns);

  return pkg;
}


static intmax_t
parse_timestamp(const char *value)
{
  intmax_t timestamp;
  char *end;

  errno = 0;
  timestamp = strtoimax(value, &end, 10);
  if (value == end || *end)
    printf("unable to parse timestamp '%.255s'", value);
  else if (errno != 0)
    printf("unable to parse timestamp '%.255s'", value);

  return timestamp;
}

static void
file_treewalk_feed(const char *dir, int fd_out)
{
  struct treeroot *tree;
  struct treenode *node;
  struct file_info *fi;
  struct file_info *symlist = NULL;
  struct file_info *symlist_end = NULL;

  tree = treewalk_open(dir, TREEWALK_NONE, NULL);
  for (node = treewalk_node(tree); node ; node = treewalk_next(tree)) {
    const char *virtname = treenode_get_virtname(node);
    char *nodename;

    if (strncmp(virtname, BUILDCONTROLDIR, strlen(BUILDCONTROLDIR)) == 0)
      continue;

    nodename = str_fmt("./%s", virtname);


    /* We need to reorder the files so we can make sure that symlinks
     * will not appear before their target. */
    if (S_ISLNK(treenode_get_mode(node))) {
      fi = file_info_new(nodename);
      file_info_list_append(&symlist, &symlist_end, fi);
    } else if (fd_write(fd_out, nodename, strlen(nodename) + 1) < 0) {
      printf("failed to write filename to tar pipe (%s)","data member");
    }

    free(nodename);
  }
  treewalk_close(tree);

  for (fi = symlist; fi; fi = fi->next)
    if (fd_write(fd_out, fi->fn, strlen(fi->fn) + 1) < 0)
      printf("failed to write filename to tar pipe (%s)", "data member");

  file_info_list_free(symlist);
}


int opt_root_owner_group = 0;
int opt_uniform_compression = 1;


int
do_build(const char *const *argv)
{
  struct compress_params control_compress_params;
  struct tar_pack_options tar_options;
  struct dpkg_error err;
  struct dpkg_ar *ar;
  intmax_t timestamp;
  const char *timestamp_str;
  const char *dir, *dest;
  char *ctrldir;
  char *debar;
  char *tfbuf;
  int gzfd;



  /* Decode our arguments. */
  dir = *argv++;
  if (!dir)
    badusage(_("--%s needs a <directory> argument"), cipaction->olong);

  dest = *argv++;
  if (dest && *argv)
    badusage(_("--%s takes at most two arguments"), cipaction->olong);

  debar = gen_dest_pathname(dir, dest);
  ctrldir = str_fmt("%s/%s", dir, BUILDCONTROLDIR);

  /* Perform some sanity checks on the to-be-build package. */
  if (opt_nocheck) {
    if (debar == NULL)
      ohshit(_("target is directory - cannot skip control file check"));
    warning(_("not checking contents of control area"));
    info(_("building an unknown package in '%s'."), debar);
  } else {
    struct pkginfo *pkg;

    pkg = check_control_area(ctrldir, dir);
    if (debar == NULL)
      debar = gen_dest_pathname_from_pkg(dest, pkg);
    info(_("building package '%s' in '%s'."), pkg->set->name, debar);
  }
  m_output(stdout, _("<standard output>"));

  timestamp_str = getenv("SOURCE_DATE_EPOCH");
  if (str_is_set(timestamp_str))
    timestamp = parse_timestamp(timestamp_str);
  else
    timestamp = time(NULL);

  /* Now that we have verified everything it is time to actually
   * build something. Let's start by making the ar-wrapper. */
  ar = dpkg_ar_create(debar, 0644);

  dpkg_ar_set_mtime(ar, timestamp);

  unsetenv("TAR_OPTIONS");

  /* Create a temporary file to store the control data in. Immediately
   * unlink our temporary file so others can't mess with it. */
  tfbuf = path_make_temp_template("dpkg-deb");
  gzfd = mkstemp(tfbuf);
  if (gzfd == -1)
    ohshite(_("failed to make temporary file (%s)"), _("control member"));
  /* Make sure it's gone, the fd will remain until we close it. */
  if (unlink(tfbuf))
    ohshit(_("failed to unlink temporary file (%s), %s"), _("control member"),
           tfbuf);
  free(tfbuf);

  /* Select the compressor to use for our control archive. */
  if (opt_uniform_compression) {
    control_compress_params = compress_params;
  } else {
    control_compress_params = compress_params_deb0;

    if (!compressor_check_params(&control_compress_params, &err))
      internerr("invalid control member compressor params: %s", err.str);
  }

     printf("my test %d\n",__LINE__ );
 
  /* Fork a tar to package the control-section of the package. */
  tar_options.mode = "u+rw,go=rX";
  tar_options.timestamp = timestamp;
  tar_options.root_owner_group = true;
  tarball_pack(ctrldir, control_treewalk_feed, &tar_options,
               &control_compress_params, gzfd);

  free(ctrldir);

    printf("my test %d\n",__LINE__ );

  if (lseek(gzfd, 0, SEEK_SET))
    ohshite(_("failed to rewind temporary file (%s)"), _("control member"));

  /* We have our first file for the ar-archive. Write a header for it
   * to the package and insert it. */
    printf("my test %d\n",__LINE__ );
  if (deb_format.major == 0) {
  
  
    printf("my test %d\n",__LINE__ );
  
    struct stat controlstab;
    char versionbuf[40];

    if (fstat(gzfd, &controlstab))
      ohshite(_("failed to stat temporary file (%s)"), _("control member"));
    sprintf(versionbuf, "%-8s\n%jd\n", OLDARCHIVEVERSION,
            (intmax_t)controlstab.st_size);
    if (fd_write(ar->fd, versionbuf, strlen(versionbuf)) < 0)
      ohshite(_("error writing '%s'"), debar);
    if (fd_fd_copy(gzfd, ar->fd, -1, &err) < 0)
      ohshit(_("cannot copy '%s' into archive '%s': %s"), _("control member"),
             ar->name, err.str);
  } else if (deb_format.major == 2) {
  
    printf("my test %d\n",__LINE__ );
  
  
    const char deb_magic[] = ARCHIVEVERSION "\n";
    char adminmember[16 + 1];

    sprintf(adminmember, "%s%s", ADMINMEMBER,
            compressor_get_extension(control_compress_params.type));

    dpkg_ar_put_magic(ar);
    dpkg_ar_member_put_mem(ar, DEBMAGIC, deb_magic, strlen(deb_magic));
    dpkg_ar_member_put_file(ar, adminmember, gzfd, -1);
  } else {
    internerr("unknown deb format version %d.%d", deb_format.major, deb_format.minor);
  }

  close(gzfd);

  /* Control is done, now we need to archive the data. */
  if (deb_format.major == 0) {
    /* In old format, the data member is just concatenated after the
     * control member, so we do not need a temporary file and can use
     * the compression file descriptor. */
    gzfd = ar->fd;
  } else if (deb_format.major == 2) {
    /* Start by creating a new temporary file. Immediately unlink the
     * temporary file so others can't mess with it. */
    tfbuf = path_make_temp_template("dpkg-deb");
    gzfd = mkstemp(tfbuf);
    if (gzfd == -1)
      ohshite(_("failed to make temporary file (%s)"), _("data member"));
    /* Make sure it's gone, the fd will remain until we close it. */
    if (unlink(tfbuf))
      ohshit(_("failed to unlink temporary file (%s), %s"), _("data member"),
             tfbuf);
    free(tfbuf);
  } else {
    internerr("unknown deb format version %d.%d", deb_format.major, deb_format.minor);
  }

  /* Pack the directory into a tarball, feeding files from the callback. */
  tar_options.mode = NULL;
  tar_options.timestamp = timestamp;
  tar_options.root_owner_group = opt_root_owner_group;
  tarball_pack(dir, file_treewalk_feed, &tar_options, &compress_params, gzfd);

  /* Okay, we have data.tar as well now, add it to the ar wrapper. */
  if (deb_format.major == 2) {
    char datamember[16 + 1];

    sprintf(datamember, "%s%s", DATAMEMBER,
            compressor_get_extension(compress_params.type));

	printf("[%s:%d] datamember %s ",__FUNCTION__,__LINE__,datamember);

    if (lseek(gzfd, 0, SEEK_SET))
      ohshite(_("failed to rewind temporary file (%s)"), _("data member"));

    dpkg_ar_member_put_file(ar, datamember, gzfd, -1);

    close(gzfd);
  }
  if (fsync(ar->fd))
    ohshite(_("unable to sync file '%s'"), ar->name);

  dpkg_ar_close(ar);

  free(debar);

  return 0;
}








int Pakage::create_dpkg_file(string path_dir_dpkg)
{
  struct compress_params control_compress_params;
  struct dpkg_ar *ar;
  struct dpkg_error err;
  struct tar_pack_options tar_options;
    
intmax_t timestamp;
char *tfbuf;
int gzfd;
char *ctrldir;
  char *debar;
  const char *timestamp_str;
//  const char *dir; //, *dest;

    
	//@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	string dest = path_dir_dpkg;
	dest += + "/";
	dest += name+version;
	dest +=".deb";//gen_dest_pathname(dir, dest);
	string dir = path_dir_dpkg;
	dir += + "/build_dpkg/";
	dir += name;
	dir += + "/DPKG";
	
	  debar = gen_dest_pathname(dir.c_str(), dest.c_str());
  	  ctrldir = str_fmt("%s/%s", dir.c_str(), BUILDCONTROLDIR);
	
	    struct pkginfo *pkg;

    pkg = check_control_area(ctrldir, dir);
    if (debar == NULL) {
      debar = gen_dest_pathname_from_pkg(dest.c_str(), pkg);
    }
    
    m_output(stdout, "<standard output>");	

	timestamp_str = getenv("SOURCE_DATE_EPOCH");
	if (str_is_set(timestamp_str))
	    timestamp = parse_timestamp(timestamp_str);
	else
	    timestamp = time(NULL);
	
	ar = dpkg_ar_create(debar, 0644);
	dpkg_ar_set_mtime(ar, timestamp);

	unsetenv("TAR_OPTIONS");

	tfbuf = path_make_temp_template("dpkg-deb");
	gzfd = mkstemp(tfbuf);
	 

	 
	 
  	if (gzfd == -1)
    		printf("failed to make temporary file (%s)", "control member");
  	/* Make sure it's gone, the fd will remain until we close it. */
  	if (unlink(tfbuf))
    	printf("failed to unlink temporary file (%s), %s", "control member", tfbuf);
  	free(tfbuf);	 
	


	 
	if (opt_uniform_compression) {
    		control_compress_params = compress_params();
  	} else {
    		control_compress_params = compress_params_deb0;

    		if (!compressor_check_params(&control_compress_params, &err))
      			printf("invalid control member compressor params: %s", err.str);
  	}


  /* Fork a tar to package the control-section of the package. */
  tar_options.mode = "u+rw,go=rX";
  tar_options.timestamp = timestamp;
  tar_options.root_owner_group = true;
  tarball_pack(ctrldir, control_treewalk_feed, &tar_options,
               &control_compress_params, gzfd);

  free(ctrldir);


    const char deb_magic[] = ARCHIVEVERSION "\n";
    char adminmember[16 + 1];

    sprintf(adminmember, "%s%s", ADMINMEMBER,
            compressor_get_extension(control_compress_params.type));

    dpkg_ar_put_magic(ar);
    dpkg_ar_member_put_mem(ar, DEBMAGIC, deb_magic, strlen(deb_magic));
    dpkg_ar_member_put_file(ar, adminmember, gzfd, -1);

 // free(ctrldir);
    close(gzfd);  
	
	
    tfbuf = path_make_temp_template("dpkg-deb");
    gzfd = mkstemp(tfbuf);
    if (gzfd == -1)
      printf("failed to make temporary file (%s)", "data member");
    /* Make sure it's gone, the fd will remain until we close it. */
    if (unlink(tfbuf))
      printf("failed to unlink temporary file (%s), %s", "data member", tfbuf);
    free(tfbuf);


/* Pack the directory into a tarball, feeding files from the callback. */
  tar_options.mode = NULL;
  tar_options.timestamp = timestamp;
  tar_options.root_owner_group = opt_root_owner_group;
  
    	printf("tfbuf %d \n",gzfd);
  
  //tarball_pack(dir, file_treewalk_feed, &tar_options, &compress_params, gzfd);
  
  
    //  char datamember[16 + 1];

    string datamember = "data.tar.xz";

    //sprintf(datamember, "%s%s", DATAMEMBER, compressor_get_extension(compress_params.type));

    if (lseek(gzfd, 0, SEEK_SET))
      printf("failed to rewind temporary file (%s)", "data member");

    dpkg_ar_member_put_file(ar, datamember.c_str(), gzfd, -1);

    close(gzfd);
	
	  
	return 0;
}




string Pakage::get_version()
{
	return this->version;
}

string Pakage::get_name()
{
	return name;
}



