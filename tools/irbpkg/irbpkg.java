package su.irbis.irbpkg;

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
        if (pkg.find_pkg(pkg_dir))
        {
            System.out.println("Pkg file not fount "+namepkg);
        }
        List<String> depends =  pkg.check_depends();
        irbpkg.Debug("depends " + depends + " count "+ depends.size());


    }

    private static void usage()
    {
        System.out.println("usage: ");
        System.out.println("ipkg options pkg_name ");
    }

    public static void Debug(String text)
    {
        System.out.println(text);
    }
}

