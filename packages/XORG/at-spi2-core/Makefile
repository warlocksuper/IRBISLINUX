wget https://download.gnome.org/sources/at-spi2-core/2.46/at-spi2-core-2.46.0.tar.xz

depend 
libxml
dbus
glib
gsettings-desktop-schemas


tar -xf at-spi2-core-2.46.0.tar.xz

mkdir DPKG
mkdir build && cd build

meson --prefix=/root/at-spi2-core-2.46.0/DPKG --buildtype=release -Dsystemd_user_dir=/tmp ..

meson --prefix=/usr --buildtype=release -Dsystemd_user_dir=/usr/lib/systemd/system ..