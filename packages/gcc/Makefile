OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

GCC_TAR = ${ROOT_DIR}/source/gcc-12.2.0.tar.xz

PGK_SOURCE_DIR = ${ROOT_SOURCE}/gcc-12.2.0


GCC_STAGE1_CONFIGURE = ${ROOT_DIR}/build/gcc/Makefile
GCC_STAGE1_COMPILE = ${ROOT_DIR}/tools/share/info/gcc.info


GCC_STAGE2_BUILD_DIR = ${ROOT_BUILD}/gcc_stage2
GCC_STAGE2_CONFIGURE = ${GCC_STAGE2_BUILD_DIR}/Makefile
GCC_STAGE2_COMPILE = ${GCC_STAGE2_BUILD_DIR}/gcc/cc1
GCC_STAGE2_INSTALL = ${ROOT_FS}/usr/bin/gcc

all:

stage1_tools: ${GCC_TAR}  ${GCC_STAGE1_CONFIGURE} ${GCC_STAGE1_COMPILE}

${GCC_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf gcc-12.2.0.tar.xz
	wget https://ftp.gnu.org/gnu/mpfr/mpfr-4.2.0.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf mpfr-4.2.0.tar.xz
	@cd ${ROOT_DIR}/source && mv -v mpfr-4.2.0 gcc-12.2.0/mpfr
	wget https://ftp.gnu.org/gnu/gmp/gmp-6.2.1.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf gmp-6.2.1.tar.xz
	@cd ${ROOT_DIR}/source && mv -v gmp-6.2.1 gcc-12.2.0/gmp
	wget https://ftp.gnu.org/gnu/mpc/mpc-1.3.1.tar.gz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf mpc-1.3.1.tar.gz
	@cd ${ROOT_DIR}/source && mv -v mpc-1.3.1 gcc-12.2.0/mpc		

${GCC_STAGE1_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/gcc
	@cd ${ROOT_DIR}/build/gcc && ${ROOT_DIR}/source/gcc-12.2.0/configure --target=${CONFIG_OS_ARCH}-pc-linux-gnu --prefix=${ROOT_DIR}/tools --with-glibc-version=2.37 --with-sysroot=${ROOT_FS} --with-newlib --without-headers --disable-nls --disable-shared --disable-multilib --disable-threads --disable-libatomic --disable-libgomp --disable-libquadmath --disable-libssp --disable-libvtv --disable-libstdcxx --enable-languages=c,c++

${GCC_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/gcc all-gcc all-target-libgcc
	${MAKE} -C ${ROOT_DIR}/build/gcc install-gcc install-target-libgcc	
	
temporary_tools: ${GCC_STAGE2_CONFIGURE} ${GCC_STAGE2_COMPILE} ${GCC_STAGE2_INSTALL}

${GCC_STAGE2_CONFIGURE}:
	@mkdir -p ${GCC_STAGE2_BUILD_DIR}
	@cd ${GCC_STAGE2_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --build=$(../config.guess) --host=${CONFIG_OS_ARCH}-pc-linux-gnu --target=${CONFIG_OS_ARCH}-pc-linux-gnu LDFLAGS_FOR_TARGET=-L${ROOT_DIR}/tools/lib/gcc/${CONFIG_OS_ARCH}-pc-linux-gnu/12.2.0 --prefix=/usr --with-build-sysroot=${ROOT_FS} --enable-default-pie --enable-default-ssp --disable-nls --disable-multilib --disable-libatomic --disable-libgomp --disable-libquadmath --disable-libssp  --disable-libvtv --enable-languages=c,c++ CPPFLAGS=-I${ROOT_DIR}/tools/${CONFIG_OS_ARCH}-pc-linux-gnu/include/c++/12.2.0/
	
${GCC_STAGE2_COMPILE}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR}
	
	
${GCC_STAGE2_INSTALL}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR} DESTDIR=${ROOT_FS} install
	
