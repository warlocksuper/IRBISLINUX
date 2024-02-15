
ifdef PKG_COMPILE_MAKE
COMPILE:
	@cd ${PKG_COMPILE_DIR} && make


${PKG_MAKE_INTALL}:
	@cd ${PKG_COMPILE_DIR} && make DESTDIR=${PKG_BUILD_DIR_DPKG} install
endif	

ifdef PKG_COMPILE_NINJA
COMPILE:
	@cd ${PKG_COMPILE_DIR} && ninja


${PKG_MAKE_INTALL}:
	@cd ${PKG_COMPILE_DIR} && DESTDIR=${PKG_BUILD_DIR_DPKG}  ninja install
endif	
