
Depends: gperf

all:

dpkg:
	https://github.com/eudev-project/eudev/releases/download/v3.2.11/eudev-3.2.11.tar.gz
	./configure --prefix=/usr --bindir=/usr/sbin --sysconfdir=/etc --disable-static

	make check
	mkdir DPGK
	make DESTDIR=/root/gperf-3.1/DPKG install
	du -s DPKG
