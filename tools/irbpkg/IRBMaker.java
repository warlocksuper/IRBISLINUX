package su.irbis;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

// надо предусмотреть парамерт устанавливается пакет после сборки или нет

public class IRBMaker {

        private final String namepkg;
        private PKG_PRJ pkgPrj;

        public IRBMaker(String namepkg)
        {

                this.namepkg = namepkg;
                this.pkgPrj = new PKG_PRJ(this.namepkg,irbpkg.work_dir+ "\\packages_dpkg");
        }

        public boolean make()
        {
                //Найти файл проекта
                if(!pkgPrj.open_project())
                {
                        return false;
                }
                //Понять тип проекта
                //Выбрать сценарий сборки
                //Подготовить рабочий каталог
                //начать сборку
                //понять успешность сборки
                //установить пакет
                return  false;
        }

        private boolean find_pkg(String path)
        {
                Path path__dir_pkg = Paths.get(path);
                return !Files.exists(path__dir_pkg);
        }
}

