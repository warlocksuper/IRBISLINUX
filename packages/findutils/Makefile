OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

FINDUTILS_TAR = ${ROOT_DIR}/source/findutils-4.9.0.tar.xz
FINDUTILS_PRE_CONFIGURE = ${ROOT_DIR}/build/findutils/src/file
FINDUTILS_CONFIGURE = ${ROOT_DIR}/build/findutils/Makefile
FINDUTILS_COMPILE = ${ROOT_DIR}/build/findutils/find/find

FINDUTILS_INSTALL = ${ROOT_FS}/usr/bin/find

all:

temporary_tools: ${FINDUTILS_TAR} ${FINDUTILS_CONFIGURE} ${FINDUTILS_COMPILE} ${FINDUTILS_INSTALL}

${FINDUTILS_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/findutils/findutils-4.9.0.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf findutils-4.9.0.tar.xz

${FINDUTILS_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/findutils
	@cd ${ROOT_DIR}/build/findutils && ${ROOT_DIR}/source/findutils-4.9.0/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$(build-aux/config.guess) --localstatedir=/var/lib/locate
	
${FINDUTILS_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/findutils

${FINDUTILS_INSTALL}:
	${MAKE} -C ${ROOT_DIR}/build/findutils DESTDIR=${ROOT_DIR}/rootfs install
				
