
all: 


stage1:
	${MAKE} -C basefile stage1_tools
	${MAKE} -C binutils stage1_tools
	${MAKE} -C gcc stage1_tools
	${MAKE} -C linux stage1_tools
	${MAKE} -C glibc stage1_tools
	${MAKE} -C libstdc++ stage1_tools
	
temporary_tools:
	${MAKE} -C m4 temporary_tools
	${MAKE} -C ncurses temporary_tools
	${MAKE} -C busybox temporary_tools	
	${MAKE} -C bash temporary_tools
	${MAKE} -C coreutils temporary_tools
	${MAKE} -C diffutils temporary_tools
	${MAKE} -C file temporary_tools
	${MAKE} -C findutils  temporary_tools
	${MAKE} -C gawk  temporary_tools
	${MAKE} -C grep  temporary_tools
	${MAKE} -C gzip  temporary_tools
	${MAKE} -C make  temporary_tools
	${MAKE} -C patch  temporary_tools
	${MAKE} -C sed  temporary_tools
	${MAKE} -C tar  temporary_tools
	${MAKE} -C xz  temporary_tools
	${MAKE} -C zlib  temporary_tools
	${MAKE} -C binutils  temporary_tools
	${MAKE} -C gmp  temporary_tools
	${MAKE} -C mpfr  temporary_tools
	${MAKE} -C mpc  temporary_tools
	${MAKE} -C gcc  temporary_tools
	${MAKE} -C bison  temporary_tools	
	${MAKE} -C flex  temporary_tools
	${MAKE} -C perl temporary_tools
	${MAKE} -C python temporary_tools
	${MAKE} -C autoconf temporary_tools
	${MAKE} -C cmake  temporary_tools
	${MAKE} -C bc  temporary_tools
	${MAKE} -C elfutils  temporary_tools
	${MAKE} -C openssl temporary_tools
	${MAKE} -C bzip2 temporary_tools
	${MAKE} -C gettext temporary_tools
	${MAKE} -C git temporary_tools							
	${MAKE} -C dh_make  temporary_tools
	
dpkg_build:
	${MAKE} -C bash dpkg	
	${MAKE} -C xz dpkg
	${MAKE} -C ninja dpkg
	${MAKE} -C XORG dpkg

		
