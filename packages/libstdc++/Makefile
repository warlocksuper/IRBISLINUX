OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

LIBSTDCXX_STAGE1_CONFIGURE = ${ROOT_BUILD}/libstdc++/Makefile
LIBSTDCXX_STAGE1_COMPILE = ${ROOT_FS}/usr/lib/libstdc++.a

all:

stage1_tools: ${LIBSTDCXX_STAGE1_CONFIGURE} ${LIBSTDCXX_STAGE1_COMPILE}

${LIBSTDCXX_STAGE1_CONFIGURE}:
	@mkdir -p ${ROOT_BUILD}/libstdc++
	@cd ${ROOT_BUILD}/libstdc++ && ${ROOT_DIR}/source/gcc-12.3.0/libstdc++-v3/configure --host=${CONFIG_OS_ARCH_TARGET} --build=$($ROOT_SOURCE/gcc-12.2.0/config.guess) --prefix=/usr --disable-multilib --disable-nls --with-gxx-include-dir=${ROOT_FS}/usr/lib/gcc/${CONFIG_OS_ARCH_TARGET}/12.3.0/include --enable-long-long --enable-libstdcxx-pch --enable-shared

${LIBSTDCXX_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_BUILD}/libstdc++
	${MAKE} -C ${ROOT_BUILD}/libstdc++ DESTDIR=${ROOT_FS} install	
