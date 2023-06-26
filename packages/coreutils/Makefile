OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

COREUTILS_TAR = ${ROOT_DIR}/source/coreutils-9.1.tar.xz
COREUTILS__CONFIGURE = ${ROOT_DIR}/build/coreutils/Makefile
COREUTILS__COMPILE = ${ROOT_DIR}/rootfs/usr/bin/ls

all:

temporary_tools: ${COREUTILS_TAR}  ${COREUTILS__CONFIGURE} ${COREUTILS__COMPILE}

${COREUTILS_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/coreutils/coreutils-9.1.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf coreutils-9.1.tar.xz

${COREUTILS__CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/coreutils
	@cd ${ROOT_DIR}/build/coreutils && ${ROOT_DIR}/source/coreutils-9.1/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$(build-aux/config.guess) --enable-install-program=hostname --enable-no-install-program=kill,uptime
	
${COREUTILS__COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/coreutils
	${MAKE} -C ${ROOT_DIR}/build/coreutils DESTDIR=${ROOT_DIR}/rootfs install	
