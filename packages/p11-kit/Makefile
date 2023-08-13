https://github.com/p11-glue/p11-kit/releases/download/0.24.1/p11-kit-0.24.1.tar.xz

mkdir p11-build &&
cd    p11-build &&

meson --prefix=/usr --buildtype=release -Dtrust_paths=/etc/pki/anchors &&
ninja
