https://gitlab.freedesktop.org/wayland/wayland/-/release/1.21.0/downloads/wayland-1.21.0.tar.xz

mkdir build
cd build

meson --prefix=/usr --buildtype=release -Ddocumentation=false ..
ninja
DESTDIR=/root/wayland-1.21.0/wayland-1.21.0/build/DPKG ninja install


https://gitlab.freedesktop.org/wayland/wayland-protocols/-/release/1.31/downloads/wayland-protocols-1.31.tar.xz

meson --prefix=/usr --buildtype=release ..

../meson.build:86:1: ERROR: File unstable/keyboard-shortcuts-inhibit/keyboard-shortcuts-inhibit-unstable-v1.xml     
rename file keyboard-shortcuts-inhibit-unstable-v1.xm to keyboard-shortcuts-inhibit-unstable-v1.xml
