https://download.gnome.org/sources/NetworkManager/1.42/NetworkManager-1.42.0.tar.xz

grep -rl '^#!.*python$' | xargs sed -i '1s/python/&3/'


Configure --with-crypto=gnutls --enable-ppp=no --enable-ovs=no  --enable-qt=no --enable-gtk-doc=no --enable-gtk-doc-htm=no --enable-introspection=no

depand libndp readline newt


##Configure --enable-vala=yes --enable-wifi --with-session-tracking=systemd --with-crypto=gnutls --enable-ppp=no --enable-ovs=no  --enable-qt=no --enable-gtk-doc=no --enable-gtk-doc-htm=no --enable-introspection=no


mkdir build &&
cd    build    &&

CXXFLAGS+="-O2 -fPIC"            \
meson setup                      \
      --prefix=/usr              \
      --buildtype=release        \
      -Dlibaudit=no              \
      -Dlibpsl=false             \
      -Dnmtui=true               \
      -Dovs=false                \
      -Dppp=false                \
      -Dselinux=false            \
      -Dqt=false                 \
      -Dsession_tracking=systemd \
      -Dmodem_manager=false      \
      .. &&
ninja