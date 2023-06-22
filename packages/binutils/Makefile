OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

BINUTILS_TAR = ${ROOT_DIR}/source/binutils-2.40.tar.xz

all:

stage1_tools: ${BINUTILS_TAR}

${BINUTILS_TAR}:
	@mkdir -p ${ROOT_DIR}/source
	wget -p ${ROOT_DIR}/source https://sourceware.org/pub/binutils/releases/binutils-2.40.tar.xz


