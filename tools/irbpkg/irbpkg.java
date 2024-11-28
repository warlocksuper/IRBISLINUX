package su.irbis.irbpkg;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class irbpkg {

    public static final String work_dir = "E:\\Project";
    public static final String pkg_dir = work_dir + "\\packages_dpkg";

    public static void main(String []args)
    {
        if( args.length < 1)
        {
            usage();
            return;
        }
        String namepkg = args[0];
        System.out.println("IRBIS PKG Manager ");
        PKG pkg = new PKG(namepkg);
        if (find_pkg(pkg_dir))
        {
            System.out.println("Pkg file not fount "+namepkg);
        }
        //Получение списка зависимостей
        List<PKG> depends =  pkg.check_depends();
        //irbpkg.Debug("depends " + depends + " count "+ depends.size());
        //Проверка установленных зависимостей
        boolean depFail = false;
        for (PKG dep : depends)
        {
            if (!dep.exist)
            {
                Debug("pakage not installed " + dep.getPkgname() );
                depFail = true;
            }
        }

        if(!depFail)
        {
            Debug("Starting create pakage " + namepkg );
            IRBMaker maker = new IRBMaker(namepkg);
        }
    }

    private static void usage()
    {
        System.out.println("usage: ");
        System.out.println("ipkg options pkg_name ");
    }

    private static boolean find_pkg(String path)
    {
        Path path__dir_pkg = Paths.get(path);
        return !Files.exists(path__dir_pkg);
    }

    public static void Debug(String text)
    {
        System.out.println(text);
    }
}

