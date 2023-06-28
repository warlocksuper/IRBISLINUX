
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
	${MAKE} -C ncurses temporary_tools
	${MAKE} -C bash temporary_tools
	${MAKE} -C coreutils temporary_tools
	${MAKE} -C diffutils temporary_tools
	${MAKE} -C file temporary_tools
	${MAKE} -C findutils  temporary_tools
	${MAKE} -C gawk  temporary_tools
	${MAKE} -C grep  temporary_tools	
	${MAKE} -C dh_make  temporary_tools
