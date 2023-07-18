OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_NAME = linux-6.1.37

LINUX_TAR = ${ROOT_SOURCE}/${PKG_NAME}.tar.xz
PKG_URL = https://www.kernel.org/pub/linux/kernel/v6.x/${PKG_NAME}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

LINUX_STAGE1_CONFIGURE = ${ROOT_SOURCE}/${PKG_NAME}/usr/include/linux/version.h
LINUX_STAGE1_COPY = ${ROOT_FS}/usr/include/linux/version.h

all:

stage1_tools: ${LINUX_TAR} ${PGK_SOURCE_DIR}  ${LINUX_STAGE1_CONFIGURE} ${LINUX_STAGE1_COPY}

${LINUX_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/
	@cd ${ROOT_SOURCE} && tar -xf ${LINUX_TAR}

${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${LINUX_TAR}

${LINUX_STAGE1_CONFIGURE}:
	${MAKE} -C ${PGK_SOURCE_DIR} mrproper
	${MAKE} -C ${PGK_SOURCE_DIR} headers
	
${LINUX_STAGE1_COPY}:
	@mkdir -p ${ROOT_FS}/usr
	@mkdir -p ${ROOT_FS}/usr/include
	@cd ${PGK_SOURCE_DIR} && find usr/include -type f ! -name '*.h' -delete
	@cp -rv ${PGK_SOURCE_DIR}/usr/include/* ${ROOT_FS}/usr/include/
