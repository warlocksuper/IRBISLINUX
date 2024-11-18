class irbpkg
{
    public static void main(String []args)
    {
        if( args.length < 1) 
        {
        	usage();
        	return;
        }
        System.out.println("IRBIS PKG Manager "+args.length);
        PKG pkg = new PKG(args[0], "/home/warlock/IRBISLINUX");
        //System.out.println("finding pkg "+args.length);
        
    }
    
    private static void usage()
    {
    	System.out.println("usage: ");
    	System.out.println("ipkg options pkg_name ");
    } 
};
