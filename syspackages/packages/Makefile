include ../.config


export

obj-${CONFIG_OS_PERL} += perl
obj-${CONFIG_OS_ZLIB} += zlib
obj-${CONFIG_OS_ZLIB} += libmd
obj-${CONFIG_OS_OPENSSL} += openssl
obj-${CONFIG_OS_PYTHON} += python
obj-${CONFIG_OS_WGET} += wget

all: ${obj-y}

${obj-y}:
	echo $@
	${MAKE} -C $@_pkg
	
