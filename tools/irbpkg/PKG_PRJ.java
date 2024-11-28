package su.irbis.irbpkg;

//Класс для файла проекта
// должен парсить проект
//Понять тип проекта

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class PKG_PRJ {
    private String name_pkg;
    private final String path_pkg;
    private List<String> content;
    public PKG_PRJ(String name, String path)
    {
        this.name_pkg = name;
        this.path_pkg = path + "/"+name+"/Makefile" ;
    }

    public boolean open_project()
    {
        if(open_file())
        {
            //Понять тип проекта
            //PKG_COMPILE_MAKE = ""
            //#PKG_COMPILE_NINJA = ""
            //PKG_COMPILE_CMAKE = ""
            //PKG_COMPILE_PYTHON = ""
        }
        return false;
    }

    private boolean open_file()
    {
        try {
            content =  Files.readAllLines(Paths.get(this.path_pkg));
            if (!content.isEmpty()) return true;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }
    public enum PKG_TYPE {

    }
}


