https://download.gnome.org/sources/libwnck/43/libwnck-43.0.tar.xz


#Configure --disable-static --program-suffix=-1
#make GETTEXT_PACKAGE=libwnck-1

mkdir build &&
cd    build &&

meson --prefix=/usr --buildtype=release .. &&
ninja


add in file build.ninja  /usr/lib/libXRes.so libatk-1.0.so.0.24609.1

