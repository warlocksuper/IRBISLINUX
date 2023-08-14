OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = cmake-3.27.0-rc4
PKG_URL = https://github.com/Kitware/CMake/releases/download/v3.27.0-rc4/cmake-3.27.0-rc4.tar.gz
PKG_TAR_FILE = ${PKG_NAME}.tar.gz
PGK_BUILD_DIR = ${ROOT_BUILD}/cmake

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}



PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}
PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


PKG_COMPILE = ${PGK_BUILD_DIR}/cmake
PGK_INSTALL = ${ROOT_FS}/usr/bin/cmake

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}


all:

temporary_tools: ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PGK_INSTALL}

${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_CONFIGURE}:
	@mkdir -p ${PGK_BUILD_DIR}
	@cd ${PGK_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr --system-libs --no-system-jsoncpp --no-system-librhash 
	
${PKG_COMPILE}:
	${MAKE} -C ${PGK_BUILD_DIR} -DCMAKE_USE_OPENSSL=OFF

${PGK_INSTALL}:
	${MAKE} -C ${PGK_BUILD_DIR} DESTDIR=${ROOT_FS} install
				
