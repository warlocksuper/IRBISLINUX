
OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

all: stage1 

stage1: compile_toolchain finale_toolchain
	

finale_toolchain:
	sh libexec/gcc/${OS_ARCH_TARGET}/12.2.0/install-tools/mkheaders
	@echo " " > ./stage1
	
compile_toolchain:
	${MAKE} -C ${ROOT_DIR}/packages stage1	
