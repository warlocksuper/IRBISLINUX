https://mesa.freedesktop.org/archive/mesa-22.3.6.tar.xz

pip3 install mako

mkdir build
cd build

pip3 install mako
meson setup --prefix=/usr --buildtype=release -Dplatforms=x11,wayland -Dgallium-drivers=auto -Dvulkan-drivers="" -Dvalgrind=disabled -Dlibunwind=disabled -Ddefault_library=shared -Degl-native-platform=x11


Dependency "libdrm_intel" not found, tried pkgconfig and cmake
../meson.build:1802:13: ERROR: Neither a subproject directory nor a llvm.wrap file was found.
Run-time dependency LLVM found: NO (tried cmake and config-tool)
## RROR: Dependency "wayland-scanner" not found
Dependency "xfixes" not found, tried pkgconfig and cmake
Dependency "xshmfence" not found, tried pkgconfig and cmake
Dependency "xrandr" not found, tried pkgconfig and cmake
