

all:

dpkg:
	https://ftp.gnu.org/gnu/gperf/gperf-3.1.tar.gz
	./configure --prefix=/usr

	make check
	mkdir DPGK
	make DESTDIR=/root/gperf-3.1/DPKG install
	du -s DPKG
