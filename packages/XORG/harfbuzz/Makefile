https://github.com/harfbuzz/harfbuzz/releases/download/7.0.0/harfbuzz-7.0.0.tar.xz

##mkdir build
##cd build

##meson --prefix=/usr --buildtype=release -Dgraphite2=enabled .. not make
./configure --prefix=/usr --with-graphite2=yes --sysconfdir=/etc --disable-static GLIB_LIBS=-lglib-2.0 --with-gobject=yes --with-cairo=yes --with-icu=auto --with-freetype=yes --with-uniscribe=auto --with-gdi=auto --with-directwrite=auto --with-coretext=auto

depend freetype graphite2


--with-gobject=[yes/no/auto]
                          Use gobject [default=no]
  --with-cairo=[yes/no/auto]
                          Use cairo [default=auto]
  --with-chafa=[yes/no/auto]
                          Use chafa [default=auto]
  --with-icu=[yes/no/builtin/auto]
                          Use ICU [default=auto]
  --with-graphite2=[yes/no/auto]
                          Use the graphite2 library [default=no]
  --with-freetype=[yes/no/auto]
                          Use the FreeType library [default=auto]
  --with-uniscribe=[yes/no/auto]
                          Use the Uniscribe library [default=no]
  --with-gdi=[yes/no/auto]
                          Provide GDI integration helpers [default=no]
  --with-directwrite=[yes/no/auto]
                          Use the DirectWrite library (experimental)
                          [default=no]
  --with-coretext=[yes/no/auto]
                          Use CoreText [default=no]
