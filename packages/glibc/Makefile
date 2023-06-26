OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

GLIBC_TAR = ${ROOT_DIR}/source/glibc-2.37.tar.xz
GLIBC_STAGE1_CONFIGURE = ${ROOT_DIR}/build/glibc/Makefile
GLIBC_STAGE1_COMPILE = ${ROOT_FS}/usr/lib/crt1.o
GLIBC_STAGE1_INSTALL = ${ROOT_FS}/usr/lib/ld-linux-x86-64.so.2
export ARG_MAX=20480
all:

stage1_tools: ${GLIBC_TAR}  ${GLIBC_STAGE1_CONFIGURE} ${GLIBC_STAGE1_COMPILE} ${GLIBC_STAGE1_INSTALL}

${GLIBC_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/glibc/glibc-2.37.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf glibc-2.37.tar.xz
	@cp ${ROOT_DIR}/packages/glibc/glibc-2.37-fhs-1.patch  ${ROOT_DIR}/source/glibc-2.37/
	@cd ${ROOT_DIR}/source/glibc-2.37 && patch -Np1 -i glibc-2.37-fhs-1.patch

${GLIBC_STAGE1_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/glibc
	@cp ${ROOT_DIR}/packages/glibc/configparms ${ROOT_DIR}/build/glibc/
	@cd ${ROOT_DIR}/build/glibc && ${ROOT_DIR}/source/glibc-2.37/configure --prefix=/usr --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$(../scripts/config.guess) --enable-kernel=3.2 --with-headers=${ROOT_DIR}/rootfs/usr/include libc_cv_slibdir=/usr/lib
	
${GLIBC_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/glibc
	
${GLIBC_STAGE1_INSTALL}:
		${MAKE} -C ${ROOT_DIR}/build/glibc DESTDIR=${ROOT_FS} install	
