OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

LINUX_TAR = ${ROOT_DIR}/source/linux-6.1.11.tar.xz
LINUX_STAGE1_CONFIGURE = ${ROOT_DIR}/source/linux-6.1.11/usr/include/linux/version.h
LINUX_STAGE1_COPY = ${ROOT_DIR}/rootfs/usr/include/linux/version.h

all:

stage1_tools: ${LINUX_TAR}  ${LINUX_STAGE1_CONFIGURE} ${LINUX_STAGE1_COPY}

${LINUX_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_DIR}/source
	wget https://www.kernel.org/pub/linux/kernel/v6.x/linux-6.1.11.tar.xz -P ${ROOT_DIR}/source/
	@cd ${ROOT_DIR}/source && tar -xf linux-6.1.11.tar.xz

${LINUX_STAGE1_CONFIGURE}:
	${MAKE} -C ${ROOT_DIR}/source/linux-6.1.11 mrproper
	${MAKE} -C ${ROOT_DIR}/source/linux-6.1.11 headers
	
${LINUX_STAGE1_COPY}:
	@cd ${ROOT_DIR}/source/linux-6.1.11 && find usr/include -type f ! -name '*.h' -delete
	@cp -rv ${ROOT_DIR}/source/linux-6.1.11/usr/include ${ROOT_DIR}/rootfs/usr/include/
