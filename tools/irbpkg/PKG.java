import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

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
        
        find_pkg();
        
    }
    private int find_pkg()
    {
    	System.out.println("finding pkg "+pkgname );
    	Path path = Paths.get(work_dir + dir_source);

	if (Files.exists(path)) {
    		System.out.println("work dir exist");
	}
    	return 0;
    }
};
