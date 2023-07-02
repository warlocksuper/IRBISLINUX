OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PKG_NAME = m4-1.4.19
M4_TAR = ${ROOT_SOURCE}/m4-1.4.19.tar.xz
M4_CONFIGURE = ${ROOT_DIR}/build/m4/Makefile
M4_COMPILE = ${ROOT_FS}/usr/bin/m4

PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

temporary_tools: ${M4_TAR} ${PGK_SOURCE_DIR} ${M4_CONFIGURE} ${M4_COMPILE}

${M4_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/m4/m4-1.4.19.tar.xz -P ${ROOT_DIR}/source/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_DIR}/source && tar -xf m4-1.4.19.tar.xz

${M4_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/m4
	@cd ${ROOT_DIR}/build/m4 && ${ROOT_DIR}/source/m4-1.4.19/configure --prefix=/usr --host=${CONFIG_OS_ARCH_TARGET} --build=$(build-aux/config.guess)
	
${M4_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/m4
	${MAKE} -C ${ROOT_DIR}/build/m4 DESTDIR=${ROOT_FS} install	
