https://dri.freedesktop.org/libdrm/libdrm-2.4.115.tar.xz


mkdir build
cd build
meson setup --prefix=/usr --buildtype=release -Dudev=true -Dvalgrind=disabled -Dintel=enabled ..

DESTDIR=/root/libdrm-2.4.115/build/DPKG ninja install

Dependency "libpciaccess" not found, tried pkgconfig and cmake
