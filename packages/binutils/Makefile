OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

BINUTILS_TAR = ${ROOT_DIR}/source/binutils-2.40.tar.xz
BINUTILS_STAGE1_CONFIGURE = ${ROOT_DIR}/build/binutils/Makefile
BINUTILS_STAGE1_COMPILE = ${ROOT_DIR}/tools/lib/libctf.a

all:

stage1_tools: ${BINUTILS_TAR}  ${BINUTILS_STAGE1_CONFIGURE} ${BINUTILS_STAGE1_COMPILE}

${BINUTILS_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://sourceware.org/pub/binutils/releases/binutils-2.40.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf binutils-2.40.tar.xz

${BINUTILS_STAGE1_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/binutils
	@cd ${ROOT_DIR}/build/binutils && ${ROOT_DIR}/source/binutils-2.40/configure --prefix=${ROOT_DIR}/tools --with-sysroot=${ROOT_FS} --target=${CONFIG_OS_ARCH}-pc-linux-gnu --disable-nls --enable-gprofng=no --disable-werror
	
${BINUTILS_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/binutils
	${MAKE} -C ${ROOT_DIR}/build/binutils install	
