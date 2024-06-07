#include "package.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/filesystem.hpp>


#define  PATH_ROOT_DIR_DPGK "/home/warlock/IRBISLINUX"

using namespace std;

void usage()
{
	cout << "Используйте так:\n";
	cout << "create_dep_deb_pkg name_orig version_orig  deb_pkg...\n";
}


void create_fix_file(string pkg_dir_dpkg, string filename, string version){
	pkg_dir_dpkg += "/usr/share/deb/";
	boost::filesystem::create_directories(pkg_dir_dpkg.c_str());
	pkg_dir_dpkg += filename;
	ofstream ofs(pkg_dir_dpkg.c_str());
	ofs << version << "\n";
	ofs.close();	
}

void create_deb_packages(Pakage orig_pkg, const vector<string> params )
{

	//printf("count package %d\n",params.size());
	//vector<Pakage> params;
	for(int i = 0; i < params.size(); i++ )
	{
		Pakage pkg_new(params[i],orig_pkg.get_version(),"Пакет для совместимости с Debian");
		pkg_new.add_depends(orig_pkg);
		string path_dir_dpkg = PATH_ROOT_DIR_DPGK;
		pkg_new.create_control(PATH_ROOT_DIR_DPGK);
		//@echo "${PKG_VERSION}" >  ${PKG_BUILD_DIR_DPKG}/usr/share/deb/${PKG_NAME}
		string path_dir_file_dpkg = PATH_ROOT_DIR_DPGK; 
		path_dir_file_dpkg += "/build_dpkg";
		path_dir_file_dpkg += "/"+ params[i] +"/DPKG";
		create_fix_file(path_dir_file_dpkg,params[i],orig_pkg.get_version());
		//string path_dpkg_dir = PATH_ROOT_DIR_DPGK;
		//path_dpkg_dir += "/DPKG"; 
		pkg_new.create_dpkg_file(PATH_ROOT_DIR_DPGK);
	}
}


int main(int ac, char **av)
{
	if(ac < 4 )
	{
		usage();
		return 0;
	}

vector<string> params;
Pakage orig_pkg(av[1],av[2],"Пакет для совместимости с Debian");

	for(int i = 3; i < ac; i++ )
	{
		string param = av[i];
		printf("param %s \n",param.c_str());
		params.push_back(param);	
	}
	
create_deb_packages(orig_pkg, params );	
	
	return 0;
}
