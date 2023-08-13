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

GCC_STAGE1_POST_CONFIG = ${ROOT_TOOLS}/lib/gcc/${CONFIG_OS_ARCH_TARGET}/12.3.0/install-tools/include/limits.h

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
	@cd ${ROOT_SOURCE} && mv -v mpfr-4.2.0 gcc-12.3.0/mpfr
	@cd ${ROOT_SOURCE} && tar -xf gmp-6.2.1.tar.xz
	@cd ${ROOT_SOURCE} && mv -v gmp-6.2.1 gcc-12.3.0/gmp
	@cd ${ROOT_SOURCE} && tar -xf mpc-1.3.1.tar.gz
	@cd ${ROOT_SOURCE} && mv -v mpc-1.3.1 gcc-12.3.0/mpc


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
	@cd ${GCC_STAGE2_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --target=${CONFIG_OS_ARCH_TARGET} --host=${CONFIG_OS_ARCH_TARGET} --build=x86_64-pc-linux-gnu --disable-dependency-tracking --prefix=/usr --exec-prefix=/usr --bindir=/usr/bin --sbindir=/usr/sbin --libexecdir=/usr/lib --sysconfdir=/etc --datadir=/usr/share --localstatedir=/var --mandir=/usr/man --infodir=/usr/info --disable-nls CXXFLAGS_FOR_TARGET="-g -D_GLIBCXX_INCLUDE_NEXT_C_HEADERS" --enable-languages=c,c++ --with-bugurl=https://support.irbis.su/ --with-pkgversion=IRBIS GCC 12.3.0 --enable-shared --disable-__cxa_atexit --with-default-libstdcxx-abi=gcc4-compatible --enable-target-optspace --with-gnu-ld --disable-nls --disable-libsanitizer --disable-libvtv --disable-libcilkrts --disable-libmudflap --disable-libmpx --disable-multilib --disable-libgomp --disable-libquadmath --disable-libssp --disable-decimal-float --disable-libstdcxx-pch --with-host-libstdcxx=-lstdc++ --prefix=/usr --libexecdir=/usr/lib --with-local-prefix=/usr --with-stage1-ldflags=-lstdc++


${GCC_STAGE2_COMPILE}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR} -i
	
	
${GCC_STAGE2_INSTALL}:
	${MAKE} -C ${GCC_STAGE2_BUILD_DIR} DESTDIR=${ROOT_FS} install
	
	
dpkg:
	../configure --prefix=/usr --exec-prefix=/usr --bindir=/usr/bin --sbindir=/usr/sbin --libexecdir=/usr/lib --sysconfdir=/etc --datadir=/usr/share --localstatedir=/var --mandir=/usr/man --infodir=/usr/info --disable-multilib  --with-system-zlib --with-bugurl=https://support.irbis.su/ --with-pkgversion=IRBIS GCC 12.3.0 --enable-shared --disable-__cxa_atexit --enable-target-optspace --with-gnu-ld 	
