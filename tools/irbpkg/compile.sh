#!/bin/sh

javac IRBMaker.java  irbpkg.java  PKG.java  PKG_PRJ.java
mkdir -p su/irbis
mv -rf *.class su/irbis/
