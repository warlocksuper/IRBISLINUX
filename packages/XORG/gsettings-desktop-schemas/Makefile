wget https://download.gnome.org/sources/gsettings-desktop-schemas/43/gsettings-desktop-schemas-43.0.tar.xz --no-check-certificate


tar -xf gsettings-desktop-schemas-43.0.tar.xz

sed -i -r 's:"(/system):"/org/gnome\1:g' schemas/*.in

mkdir build && cd build
meson --prefix=/root/gsettings-desktop-schemas-43.0/DPKG --buildtype=release ..
ninja
ninja install
