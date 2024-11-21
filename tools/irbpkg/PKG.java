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

    public PKG(String pkg_name)
    {
        this.pkgname = pkg_name;
    }
    
    public boolean find_pkg(String path)
    {
	    Path path__dir_pkg = Paths.get(path);
        return !Files.exists(path__dir_pkg);
    }
    
    public List<String> check_depends()
    {
        List<String> deps_list = new ArrayList<>();
        String depP = find_line_from_file().substring(pkgname.length()+1);
        String[] dep = depP.split("\\s+");
        for (String s : dep) {
            if (!s.isEmpty()) {
                deps_list.add(s);
            }
        }
 	    return deps_list;
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
}
