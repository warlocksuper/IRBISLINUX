OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

BINUTILS_TAR = ${ROOT_DIR}/source/binutils-2.40.tar.xz
BINUTILS_STAGE1_CONFIGURE = ${ROOT_BUILD}/binutils/Makefile
BINUTILS_STAGE1_COMPILE = ${ROOT_DIR}/tools/lib/libctf.a
BINUTILS_STAGE2_CONFIGURE = ${ROOT_BUILD}/binutils_stage2/Makefile
BINUTILS_STAGE2_COMPILE = ${ROOT_BUILD}/binutils_stage2/binutils/elfedit
BINUTILS_STAGE2_INSTALL = ${ROOT_FS}/usr/lib/libctf.a

PGK_SOURCE_DIR = ${ROOT_DIR}/source/binutils-2.40


all:

stage1_tools: ${BINUTILS_TAR}  ${BINUTILS_STAGE1_CONFIGURE} ${BINUTILS_STAGE1_COMPILE}

${BINUTILS_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://sourceware.org/pub/binutils/releases/binutils-2.40.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf binutils-2.40.tar.xz

${BINUTILS_STAGE1_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/binutils
	@cd ${ROOT_DIR}/build/binutils && ${PGK_SOURCE_DIR}/configure --prefix=${ROOT_DIR}/tools --with-sysroot=${ROOT_FS} --target=${CONFIG_OS_ARCH}-pc-linux-gnu --disable-nls --enable-gprofng=no --disable-werror
	
${BINUTILS_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/binutils
	${MAKE} -C ${ROOT_BUILD}/binutils install
	@cd ${ROOT_DIR}	&& ln -sv usr/lib lib64	
	
temporary_tools: ${BINUTILS_TAR} ${BINUTILS_STAGE2_CONFIGURE} ${BINUTILS_STAGE2_COMPILE} ${BINUTILS_STAGE2_INSTALL}
		

${BINUTILS_STAGE2_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/binutils_stage2
	@cd ${ROOT_BUILD}/binutils_stage2 && ${PGK_SOURCE_DIR}/configure --prefix=/usr --build=x86_64-pc-linux-gnu --host=${CONFIG_OS_ARCH}-pc-linux-gnu --disable-nls --enable-shared --enable-gprofng=no --disable-werror --enable-64-bit-bfd
	
	
${BINUTILS_STAGE2_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/binutils_stage2
	
${BINUTILS_STAGE2_INSTALL}:
	${MAKE} -C ${ROOT_BUILD}/binutils_stage2 DESTDIR=${ROOT_FS} install		
