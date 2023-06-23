OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

DH_MAKE_TAR = ${ROOT_DIR}/source/dh-make_2.202301.dsc
FINDUTILS_PRE_CONFIGURE = ${ROOT_DIR}/build/findutils/src/file
FINDUTILS_CONFIGURE = ${ROOT_DIR}/build/findutils/Makefile
FINDUTILS_COMPILE = ${ROOT_DIR}/build/findutils/find/find

FINDUTILS_INSTALL = ${ROOT_FS}/usr/bin/find

### Depends: debhelper (>= 13.1), dpkg-dev, make, python3:any

all:

temporary_tools: ${DH_MAKE_TAR} ${FINDUTILS_CONFIGURE} ${FINDUTILS_COMPILE} ${FINDUTILS_INSTALL}

${DH_MAKE_TAR}:
	@cd ${ROOT_DIR}/source && apt-get source dh-make
	@cd ${ROOT_DIR}/source && tar -xf dh-make_2.202301.tar.xz

${FINDUTILS_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/findutils
	@cd ${ROOT_DIR}/build/findutils && ${ROOT_DIR}/source/findutils-4.9.0/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$(build-aux/config.guess) --localstatedir=/var/lib/locate
	
${FINDUTILS_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/findutils

${FINDUTILS_INSTALL}:
	${MAKE} -C ${ROOT_DIR}/build/findutils DESTDIR=${ROOT_DIR}/rootfs install
				
