wget --no-check-certificate https://download.gnome.org/sources/cairo/1.17/cairo-1.17.6.tar.xz


sed 's/PTR/void */' -i util/cairo-trace/lookup-symbol.c
./configure --prefix=/usr --sysconfdir=/etc --disable-static --enable-tee --enable-xlib-xcb  --enable-xlib-xrender=yes

## not need now
##--enable-gl


depand
pixman
libpng
libX11
libXext
