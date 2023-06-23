OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

LIBSTDCXX_STAGE1_CONFIGURE = ${ROOT_DIR}/build/libstdc++/Makefile
LIBSTDCXX_STAGE1_COMPILE = ${ROOT_DIR}/rootfs/usr/lib/libstdc++.a

all:

stage1_tools: ${LIBSTDCXX_STAGE1_CONFIGURE} ${LIBSTDCXX_STAGE1_COMPILE}

${LIBSTDCXX_STAGE1_CONFIGURE}:
	@mkdir -p ${ROOT_DIR}/build/libstdc++
	@cd ${ROOT_DIR}/build/libstdc++ && ${ROOT_DIR}/source/gcc-12.2.0/libstdc++-v3/configure --host=${CONFIG_OS_ARCH}-pc-linux-gnu --build=$(../config.guess) --prefix=/usr --disable-multilib --disable-nls --disable-libstdcxx-pch --with-gxx-include-dir=/tools/${CONFIG_OS_ARCH}-pc-linux-gnu/include/c++/12.2.0

${LIBSTDCXX_STAGE1_COMPILE}:
	${MAKE} -C ${ROOT_DIR}/build/libstdc++
	${MAKE} -C ${ROOT_DIR}/build/libstdc++ DESTDIR=${ROOT_DIR}/rootfs install	
