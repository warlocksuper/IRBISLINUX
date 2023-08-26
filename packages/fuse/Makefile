https://github.com/libfuse/libfuse/releases/download/fuse-3.13.1/fuse-3.13.1.tar.xz

sed -i '/^udev/,$ s/^/#/' util/meson.build

mkdir build
cd build

meson --prefix=/usr --buildtype=release ..
