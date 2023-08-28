##//No package 'libzstd' found

OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_URL = https://kernel.org/pub/linux/utils/kernel/kmod/kmod-30.tar.xz

PKG_NAME = grep-3.8
GREP_TAR = ${ROOT_SOURCE}/grep-3.8.tar.xz
GREP_BUILD_DIR = ${ROOT_BUILD}/grep
## GAWK_PRE_CONFIGURE = ${ROOT_DIR}/build/findutils/src/file
GREP_CONFIGURE = ${GREP_BUILD_DIR}/Makefile
GREP_COMPILE = ${GREP_BUILD_DIR}/src/grep
GREP_INSTALL = ${ROOT_FS}/usr/bin/grep

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

temporary_tools: ${GREP_TAR} ${PGK_SOURCE_DIR} ${GREP_CONFIGURE} ${GREP_COMPILE} ${GREP_INSTALL}

${GREP_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf grep-3.8.tar.xz

${GREP_CONFIGURE}:
	@mkdir -p ${GREP_BUILD_DIR}
	@cd ${GREP_BUILD_DIR} && ${ROOT_SOURCE}/kmod-30/Configures --with-openssl --with-xz --with-zstd --with-zlib
	
${GREP_COMPILE}:
	${MAKE} -C ${GREP_BUILD_DIR}

${GREP_INSTALL}:
	${MAKE} -C ${GREP_BUILD_DIR} DESTDIR=${ROOT_FS} install
				
