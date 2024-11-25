package su.irbis.irbpkg;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

class PKG
{
	private final String pkgname;
    public boolean exist = false;

    public PKG(String pkg_name)
    {
        this.pkgname = pkg_name;
        this.exist = check_installed_pkg();
    }
    
    public boolean find_pkg(String path)
    {
	    Path path__dir_pkg = Paths.get(path);
        return !Files.exists(path__dir_pkg);
    }
    
    public List<PKG> check_depends()
    {
        List<PKG> deps_list = new ArrayList<>();
        String depP = find_line_from_file().substring(pkgname.length()+1);
        String[] dep = depP.split("\\s+");
        for (String s : dep) {
            if (!s.isEmpty()) {
                PKG x = new PKG(s);
                deps_list.add(x);
            }
        }
 	    return deps_list;
    }

    public String getPkgname()
    {
        return pkgname;
    }

    private String find_line_from_file()
    {
        try {
            List<String> content = readTextFile(irbpkg.work_dir+"/depands_package");
            for(int i=0;i<content.size();i++)
            {

               if(content.get(i).startsWith(pkgname))
               {
                   return content.get(i);
               }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return "";
    }

    private List<String> readTextFile(String pathx) throws IOException {
        return Files.readAllLines(Paths.get(pathx));
    }

    //  /var/lib/dpkg/info/curl.list  папка содержит файлы пакетов если файл существует пакет установленн
    public boolean check_installed_pkg()
    {
        String path = "/var/lib/dpkg/info/"+this.pkgname+".list";
        Path path__dir_pkg = Paths.get(path);
        return Files.exists(path__dir_pkg);
    }
}
