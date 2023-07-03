OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

DIFF_TAR = ${ROOT_DIR}/source/diffutils-3.9.tar.xz
DIFF_CONFIGURE = ${ROOT_DIR}/build/diffutils/Makefile
DIFF_COMPILE = ${ROOT_DIR}/rootfs/usr/bin/diff

all:

temporary_tools: ${DIFF_TAR}  ${DIFF_CONFIGURE} ${DIFF_COMPILE}

${DIFF_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/diffutils/diffutils-3.9.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf diffutils-3.9.tar.xz

${DIFF_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/diffutils
	@cd ${ROOT_DIR}/build/diffutils && ${ROOT_DIR}/source/diffutils-3.9/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET}
	
${DIFF_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/diffutils
	${MAKE} -C ${ROOT_DIR}/build/diffutils DESTDIR=${ROOT_DIR}/rootfs install	
