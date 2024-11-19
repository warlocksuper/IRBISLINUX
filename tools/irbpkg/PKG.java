import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

class PKG
{
	private String pkgname;
	private String work_dir = "/etc/irbpkg";
	private String dir_source = "/packages_dpkg";
	
    public PKG(String pkg_name, String path_work_dir)
    {
        if( pkg_name.length() < 0) 
        {
        	System.out.println("error not name pkg");
        	return ;
        }
        this.pkgname = pkg_name;
        if(path_work_dir.length() > 0)
        {
          this.work_dir = path_work_dir;
        }
        if(find_pkg())
        {
        	return ;
        }
        
        
        check_depends();
        
    }
    
    private boolean find_pkg()
    {
    	
    	String strpath = work_dir + dir_source+"/"+pkgname+"_pkg";
	Path path__dir_pkg = Paths.get(strpath);
	if (!Files.exists(path__dir_pkg)) {
    		System.out.println("Pkg not fount "+strpath);
    		return true;
	}
	System.out.println("found pkg "+pkgname );
    	return false;
    }
    
    private List<String> check_depends() 
    {
    
        List<String> deps_list = new ArrayList<>();
    	// Find dep from fiile
    	find_line_from_file();
 	return deps_list;
    }
    private String find_line_from_file()
    {
  
  	return "";  
    }
};
