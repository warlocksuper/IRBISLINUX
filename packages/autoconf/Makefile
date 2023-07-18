OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = autoconf-2.71

PKG_TAR = autoconf-2.71.tar.xz

PKG_TAR_DIR = ${ROOT_SOURCE}/${PKG_TAR}


PGK_BUILD_DIR = ${ROOT_BUILD}/autoconf
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

PGK_UNTAG = ${PGK_SOURCE_DIR}/configure
PKG_URL = https://ftp.gnu.org/gnu/autoconf/autoconf-2.71.tar.xz
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile
PKG_COMPILE = ${PGK_BUILD_DIR}/autoconf
PKG_INSTALL = ${ROOT_FS}/usr/bin/autoconf

all:

temporary_tools: ${PKG_TAR_DIR}  ${PGK_UNTAG} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PKG_INSTALL}
	
${PKG_TAR_DIR}:
	wget ${PKG_URL}	-P ${ROOT_SOURCE}

${PGK_UNTAG}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR}

${PKG_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_BUILD_DIR} && CC=${CONFIG_OS_ARCH_TARGET}-gcc ${PGK_SOURCE_DIR}/configure --prefix=/usr

${PKG_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}

${PKG_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${ROOT_FS} install
              	
clean:
	rm -rf 	${PKG_TAR} ${PKG_NAME}	
