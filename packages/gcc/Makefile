OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

GCC_TAR = ${ROOT_SOURCE}/gcc-12.2.0.tar.xz

PGK_SOURCE_DIR = ${ROOT_SOURCE}/gcc-12.2.0


GCC_STAGE1_CONFIGURE = ${ROOT_BUILD}/gcc/Makefile
GCC_STAGE1_COMPILE = ${ROOT_TOOLS}/share/info/gcc.info


GCC_STAGE2_BUILD_DIR = ${ROOT_BUILD}/gcc_stage2
GCC_STAGE2_CONFIGURE = ${GCC_STAGE2_BUILD_DIR}/Makefile
GCC_STAGE2_COMPILE = ${GCC_STAGE2_BUILD_DIR}/gcc/cc8
GCC_STAGE2_INSTALL = ${ROOT_FS}/usr/bin/gcc33

GCC_STAGE1_POST_CONFIG = ${ROOT_TOOLS}/lib/gcc/${CONFIG_OS_ARCH_TARGET}/12.2.0/install-tools/include/limits.h

CXXFLAGS=-fpermissive

export

all:

stage1_tools: ${GCC_TAR}  ${PGK_SOURCE_DIR}  ${GCC_STAGE1_CONFIGURE} ${GCC_STAGE1_COMPILE} ${GCC_STAGE1_POST_CONFIG}

${GCC_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.xz -P ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/mpfr/mpfr-4.2.0.tar.xz -P ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/gmp/gmp-6.2.1.tar.xz -P ${ROOT_SOURCE}
	wget https://ftp.gnu.org/gnu/mpc/mpc-1.3.1.tar.gz -P${ROOT_SOURCE}		


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf gcc-12.2.0.tar.xz
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
    --build=x86_64-pc-linux-gnu                    \
    --host=${CONFIG_OS_ARCH_TARGET}                \
    --target=${CONFIG_OS_ARCH_TARGET}              \
    --with-sysroot=${ROOT_FS}			   \
    --prefix=/usr                                  \
    --with-build-sysroot=${ROOT_FS}  \
    --enable-shared				   \
    --enable-default-pie                           \
    --enable-default-ssp                           \
    --disable-nls                                  \
    --disable-multilib                             \
    --disable-libatomic                            \
    --disable-libgomp                              \
    --disable-libquadmath                          \
    --disable-libssp                               \
    --disable-libvtv                               \
    --enable-languages=c,c++

## enable	@cd ${GCC_STAGE2_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --host=${CONFIG_OS_ARCH_TARGET} --target=${CONFIG_OS_ARCH_TARGET} --prefix=/usr --with-glibc-version=2.37 --with-build-sysroot=${ROOT_FS} --with-newlib --without-headers --disable-nls --disable-shared --disable-multilib --disable-threads --disable-libatomic --disable-libgomp --disable-libquadmath --disable-libssp --disable-libvtv --enable-languages=c,c++	--enable-libstdcxx=yes

##	@cd ${GCC_STAGE2_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --host=${CONFIG_OS_ARCH}-pc-linux-gnu --target=${CONFIG_OS_ARCH}-pc-linux-gnu --prefix=/usr --with-build-sysroot=${ROOT_FS} --enable-languages=c,c++ --with-newlib --without-headers --disable-nls --disable-shared --disable-multilib --disable-threads --disable-libatomic --disable-libgomp --disable-libquadmath --disable-libssp --disable-libvtv --disable-libstdcxx

##	@cd ${GCC_STAGE2_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --build=$(../config.guess) --host=${CONFIG_OS_ARCH}-pc-linux-gnu --target=${CONFIG_OS_ARCH}-pc-linux-gnu LDFLAGS_FOR_TARGET=-L${ROOT_DIR}/tools/lib/gcc/${CONFIG_OS_ARCH}-pc-linux-gnu/12.2.0 --prefix=/usr --with-build-sysroot=${ROOT_FS} --enable-default-pie --enable-default-ssp --disable-nls --disable-multilib --disable-libatomic --disable-libgomp --disable-libquadmath --disable-libssp  --disable-libvtv --enable-languages=c,c++ CPPFLAGS=-I${ROOT_DIR}/tools/${CONFIG_OS_ARCH}-pc-linux-gnu/include/c++/12.2.0/
	
${GCC_STAGE2_COMPILE}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR} -i
	
	
${GCC_STAGE2_INSTALL}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR} DESTDIR=${ROOT_FS} install
	
