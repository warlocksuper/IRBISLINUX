include ../.config

OS_ARCH_HOST = amd64-irbis-linux-gnu
OS_CONFIGURE = ./configure --prefix=/usr --host=${OS_ARCH_HOST}

export

obj-${CONFIG_OS_PERL} += perl
obj-${CONFIG_OS_ZLIB} += zlib
obj-${CONFIG_OS_ZLIB} += libmd
obj-${CONFIG_OS_OPENSSL} += openssl
obj-${CONFIG_OS_PYTHON} += python
obj-${CONFIG_OS_LIBXML2} += libxml2
obj-${CONFIG_OS_NETTLE} += nettle
obj-${CONFIG_OS_BISON} += bison
obj-${CONFIG_OS_AUTOMAKE} += automake
obj-${CONFIG_OS_AUTOCONF} += autoconf
obj-${CONFIG_OS_PCG_CONFIG} += pkg-config
obj-${CONFIG_OS_GNUTLS} += gnutls
obj-${CONFIG_OS_WGET} += wget
obj-${CONFIG_OS_OPENSSL} += openssl



all: ${obj-y}

${obj-y}:
	echo $@
	${MAKE} -C $@_pkg
	
