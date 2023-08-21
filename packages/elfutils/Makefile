OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = elfutils-0.188
PKG_URL = https://sourceware.org/ftp/elfutils/0.188/elfutils-0.188.tar.bz2
PKG_TAR_FILE = ${PKG_NAME}.tar.bz2
PGK_BUILD_DIR = ${ROOT_BUILD}/elfutils
PKG_COMPILE = ${PGK_BUILD_DIR}/elfutils
PGK_INSTALL = ${ROOT_FS}/usr/bin/elfutils

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}



PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

temporary_tools: ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PGK_INSTALL}

${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}
		
${PKG_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --sysconfdir=/etc --disable-debuginfod --enable-libdebuginfod=dummy
	
${PKG_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}

${PGK_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR}/libelf DESTDIR=${ROOT_FS} install
	@cd ${PGK_BUILD_DIR} && install -vm644 config/libelf.pc ${ROOT_FS}/usr/lib/pkgconfig
	@rm -rf ${ROOT_FS}/usr/lib/libelf.a	


dpkg:
	./configure --prefix=/usr --sysconfdir=/etc --disable-debuginfod --enable-libdebuginfod=dummy
/*

gzip.c:57:11: fatal error: bzlib.h: No such file or directory
   57 | # include <bzlib.h>

*/
