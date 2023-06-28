OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = make-4.4
PKG_URL = https://ftp.gnu.org/gnu/make/make-4.4.tar.gz
PKG_TAR_FILE = ${PKG_NAME}.tar.gz
PGK_BUILD_DIR = ${ROOT_BUILD}/make

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}



PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


PKG_COMPILE = ${GREP_BUILD_DIR}/make
PGK_INSTALL = ${ROOT_FS}/usr/bin/make


all:

temporary_tools: ${PKG_TAR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PGK_INSTALL}

${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu
	
${PKG_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR}

${PGK_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${ROOT_FS} install
				
