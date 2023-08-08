OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PKG_NAME = busybox-1.36.1
PKG_TAR_FILE = busybox-1.36.1.tar.bz2
PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_URL = https://busybox.net/downloads/busybox-1.36.1.tar.bz2

PKG_COMPILE = ${PGK_SOURCE_DIR}/busybox

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

PKG_CONFIGURE = ${PGK_SOURCE_DIR}/.config

PKG_INSTALL = ${ROOT_FS}/usr/sbin/busybox
PKG_INSTALL_PATH = $(shell printenv ROOT_FS | sed 's_/_\\/_g')

all:

temporary_tools: ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PKG_INSTALL}


${PKG_TAR}: 
	wget ${PKG_URL} -P ${ROOT_SOURCE}/

${PGK_SOURCE_DIR}: 
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}
	
${PKG_CONFIGURE}:
	@cp config ${PGK_SOURCE_DIR}/.config
	sed -i 's/INSTALL_PREFIX/CONFIG_PREFIX="$(shell printenv ROOT_FS | sed 's_/_\\/_g')"/g' ${PGK_SOURCE_DIR}/.config
	sed -i 's/COMPILER_PREFIX=""/COMPILER_PREFIX="'${CONFIG_OS_ARCH_TARGET}'-"/g' ${PGK_SOURCE_DIR}/.config
	
	

${PKG_COMPILE}:
	CC=amd64-irbis-linux-gnu-gcc  CONFIG_CROSS_COMPILER_PREFIX=${CONFIG_OS_ARCH_TARGET}- ${MAKE} -C ${PGK_SOURCE_DIR}
	
${PKG_INSTALL}:
	${MAKE} -C ${PGK_SOURCE_DIR} install		
	
