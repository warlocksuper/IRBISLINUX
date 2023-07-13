OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


GCC_TAR = gcc-12.3.0.tar.gz
GCC_TAR_DIR = ${ROOT_SOURCE}/${GCC_TAR}
PGK_SOURCE_DIR = ${ROOT_SOURCE}/gcc-12.3.0


GCC_STAGE1_CONFIGURE = ${ROOT_BUILD}/gcc/Makefile
GCC_STAGE1_COMPILE = ${ROOT_TOOLS}/share/info/gcc.info


GCC_STAGE2_BUILD_DIR = ${ROOT_BUILD}/gcc_stage2
GCC_STAGE2_CONFIGURE = ${GCC_STAGE2_BUILD_DIR}/Makefile
GCC_STAGE2_COMPILE = ${GCC_STAGE2_BUILD_DIR}/gcc/cc1
GCC_STAGE2_INSTALL = ${ROOT_FS}/usr/bin/gcc

GCC_STAGE1_POST_CONFIG = ${ROOT_TOOLS}/lib/gcc/${CONFIG_OS_ARCH_TARGET}/12.2.0/install-tools/include/limits.h

CXXFLAGS=-fpermissive

export

all:

stage1_tools: ${GCC_TAR_DIR}  ${PGK_SOURCE_DIR}  ${GCC_STAGE1_CONFIGURE} ${GCC_STAGE1_COMPILE} ${GCC_STAGE1_POST_CONFIG}

${GCC_TAR_DIR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/gcc/gcc-12.3.0/gcc-12.3.0.tar.gz -P ${ROOT_SOURCE}
##	wget http://mirror.linux-ia64.org/gnu/gcc/releases/gcc-12.3.0/gcc-12.3.0.tar.gz	-P ${ROOT_SOURCE}
##	wget https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.xz -P ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/mpfr/mpfr-4.2.0.tar.xz -P ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/gmp/gmp-6.2.1.tar.xz -P ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/mpc/mpc-1.3.1.tar.gz -P${ROOT_SOURCE}		


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${GCC_TAR}
	@cd ${ROOT_SOURCE} && tar -xf mpfr-4.2.0.tar.xz
	@cd ${ROOT_SOURCE} && mv -v mpfr-4.2.0 gcc-12.2.0/mpfr
	@cd ${ROOT_SOURCE} && tar -xf gmp-6.2.1.tar.xz
	@cd ${ROOT_SOURCE} && mv -v gmp-6.2.1 gcc-12.2.0/gmp
	@cd ${ROOT_SOURCE} && tar -xf mpc-1.3.1.tar.gz
	@cd ${ROOT_SOURCE} && mv -v mpc-1.3.1 gcc-12.2.0/mpc


${GCC_STAGE1_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/gcc
	@cd ${ROOT_BUILD}/gcc && ${PGK_SOURCE_DIR}/configure --target=${CONFIG_OS_ARCH_TARGET} --prefix=${ROOT_TOOLS} --with-glibc-version=2.37 --with-sysroot=${ROOT_FS} --with-newlib --without-headers --disable-nls --disable-shared --disable-multilib --disable-threads --disable-libatomic --disable-libgomp --disable-libquadmath --disable-libssp --disable-libvtv --disable-libstdcxx --enable-languages=c,c++

${GCC_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/gcc ##all-gcc all-target-libgcc
	${MAKE} -C ${ROOT_BUILD}/gcc install ##install-gcc install-target-libgcc	

${GCC_STAGE1_POST_CONFIG}:
	@cd ${PGK_SOURCE_DIR} && cat gcc/limitx.h gcc/glimits.h gcc/limity.h > ${GCC_STAGE1_POST_CONFIG}
	
temporary_tools: ${GCC_STAGE2_CONFIGURE} ${GCC_STAGE2_COMPILE} ${GCC_STAGE2_INSTALL}

BUILD_BUILD = `echo ${PGK_SOURCE_DIR}/config.guess`

${GCC_STAGE2_CONFIGURE}:
	@mkdir -p ${GCC_STAGE2_BUILD_DIR}
	@cd ${GCC_STAGE2_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure \
	--target=${CONFIG_OS_ARCH_TARGET} --host=${CONFIG_OS_ARCH_TARGET} --build=${CONFIG_OS_ARCH_TARGET} --prefix=/usr --exec-prefix=/usr --sysconfdir=/etc --localstatedir=/var --disable-gtk-doc --disable-gtk-doc-html --disable-doc --disable-docs --disable-documentation --with-xmlto=no --with-fop=no --disable-dependency-tracking --enable-ipv6 --disable-static --enable-shared --target=${CONFIG_OS_ARCH_TARGET} --with-sysroot=${ROOT_FS} --enable-__cxa_atexit --with-gnu-ld --disable-libssp --disable-multilib  --enable-plugins --enable-lto --with-gmp=${ROOT_FS} --with-mpc=${ROOT_FS} --with-mpfr=${ROOT_FS} --with-pkgversion='IRBIS 2023.07' --with-bugurl=http://support.irbis.su --without-zstd --enable-libquadmath --enable-libquadmath-support --enable-tls --enable-threads --without-isl --without-cloog --with-arch=x86-64 --with-sysroot=/ --with-build-sysroot=${ROOT_FS} --disable-__cxa_atexit --with-gmp=${ROOT_FS} --with-mpc=${ROOT_FS} --with-mpfr=${ROOT_FS} --disable-libsanitizer --disable-plugin --disable-lto --enable-languages=c,c++ --disable-boostrap --disable-libgomp --disable-nls --disable-libmpx --disable-gcov --enable-decimal-float=no


###   --disable-decimal-float
##    --build=x86_64-pc-linux-gnu                    \
##    --host=${CONFIG_OS_ARCH_TARGET}                \
##    --target=${CONFIG_OS_ARCH_TARGET}              \
##    --with-sysroot=${ROOT_FS}			   \
##    --prefix=/usr                                  \
##    --with-build-sysroot=${ROOT_FS}  \
##    --enable-shared				   \
##    --enable-default-pie                           \
##    --enable-default-ssp                           \
##    --disable-nls                                  \
##    --disable-multilib                             \
##    --disable-libatomic                            \
##    --disable-libgomp                              \
##    --disable-libquadmath                          \
##    --disable-libssp                               \
##    --disable-libvtv                               \
##    --enable-languages=c,c++

	
${GCC_STAGE2_COMPILE}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR} -i
	
	
${GCC_STAGE2_INSTALL}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR} DESTDIR=${ROOT_FS} install
	
