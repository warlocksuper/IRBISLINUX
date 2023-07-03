OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

GREP_TAR = ${ROOT_SOURCE}/grep-3.8.tar.xz
GREP_BUILD_DIR = ${ROOT_BUILD}/grep
## GAWK_PRE_CONFIGURE = ${ROOT_DIR}/build/findutils/src/file
GREP_CONFIGURE = ${GREP_BUILD_DIR}/Makefile
GREP_COMPILE = ${GREP_BUILD_DIR}/src/grep
GREP_INSTALL = ${ROOT_FS}/usr/bin/grep

all:

temporary_tools: ${GREP_TAR} ${GREP_CONFIGURE} ${GREP_COMPILE} ${GREP_INSTALL}

${GREP_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/grep/grep-3.8.tar.xz -P ${ROOT_SOURCE}/
	@cd ${ROOT_SOURCE} && tar -xf grep-3.8.tar.xz

${GREP_CONFIGURE}:
	@mkdir -p ${GREP_BUILD_DIR}
	@cd ${GREP_BUILD_DIR} && ${ROOT_SOURCE}/grep-3.8/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET}
	
${GREP_COMPILE}:
	${MAKE} -C ${GREP_BUILD_DIR}

${GREP_INSTALL}:
	${MAKE} -C ${GREP_BUILD_DIR} DESTDIR=${ROOT_FS} install
				
