OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

M4_TAR = ${ROOT_DIR}/source/m4-1.4.19.tar.xz
M4_CONFIGURE = ${ROOT_DIR}/build/m4/Makefile
M4_COMPILE = ${ROOT_DIR}/rootfs/usr/bin/m4

all:

temporary_tools: ${M4_TAR}  ${M4_CONFIGURE} ${M4_COMPILE}

${M4_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/m4/m4-1.4.19.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf m4-1.4.19.tar.xz

${M4_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/m4
	@cd ${ROOT_DIR}/build/m4 && ${ROOT_DIR}/source/m4-1.4.19/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$(build-aux/config.guess)
	
${M4_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/m4
	${MAKE} -C ${ROOT_DIR}/build/m4 DESTDIR=${ROOT_DIR}/rootfs install	
