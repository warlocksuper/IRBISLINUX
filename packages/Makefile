
all: 
	${MAKE} -C binutils

stage1:
	${MAKE} -C binutils stage1_tools
	${MAKE} -C gcc stage1_tools
	${MAKE} -C linux stage1_tools
	${MAKE} -C glibc stage1_tools
	${MAKE} -C libstdc++ stage1_tools
	
temporary_tools:
	${MAKE} -C m4 temporary_tools	
