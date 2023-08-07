OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

COPY_ROOTFS = ${ROOT_FS}/etc

all:

stage1_tools: ${COPY_ROOTFS}
	
	
${COPY_ROOTFS}:
	@mkdir -p ${ROOT_FS}
	@cp -rf skeleton/* ${ROOT_FS}/*
