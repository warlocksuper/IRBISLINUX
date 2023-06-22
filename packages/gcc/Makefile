OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

GCC_TAR = ${ROOT_DIR}/source/gcc-12.2.0.tar.xz

GCC_STAGE1_CONFIGURE = ${ROOT_DIR}/build/gcc/Makefile
GCC_STAGE1_COMPILE = ${ROOT_DIR}/tools/share/info/gcc.info

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
	@cd ${ROOT_DIR}/build/gcc && ${ROOT_DIR}/source/gcc-12.2.0/configure --target=${CONFIG_OS_ARCH}-pc-linux-gnu --prefix=${ROOT_DIR}/tools --with-glibc-version=2.37 --with-sysroot=${ROOT_DIR}/rootfs --with-newlib --without-headers --disable-nls --disable-shared --disable-multilib --disable-threads --disable-libatomic --disable-libgomp --disable-libquadmath --disable-libssp --disable-libvtv --disable-libstdcxx --enable-languages=c,c++

${GCC_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/gcc all-gcc all-target-libgcc
	${MAKE} -C ${ROOT_DIR}/build/binutils install-gcc install-target-libgcc	
	
	
