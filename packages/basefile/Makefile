OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

COPY_ROOTFS = ${ROOT_FS}/etc

all:

stage1_tools: ${COPY_ROOTFS}
	
	
${COPY_ROOTFS}:
	@mkdir -p ${ROOT_FS}
	cp -r skeleton/* ${ROOT_FS}/
	install -d ${ROOT_FS}/var/log
