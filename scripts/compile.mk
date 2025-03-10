
ifdef PKG_COMPILE_MAKE
COMPILE:
	@cd ${PKG_COMPILE_DIR} && make ${PKG_COMPILE_MAKE_ADD_OPT} -j1


${PKG_MAKE_INTALL}:
	@cd ${PKG_COMPILE_DIR} && make DESTDIR=${PKG_BUILD_DIR_DPKG}   ${PKG_COMPILE_MAKE_INSTALL_ADD_OPT}   install
endif	

ifdef PKG_COMPILE_NINJA
COMPILE:
	@cd ${PKG_COMPILE_DIR} && ninja -j1


${PKG_MAKE_INTALL}:
	@cd ${PKG_COMPILE_DIR} &&  ${NEED_SUDO} DESTDIR=${PKG_BUILD_DIR_DPKG}  ninja install
endif	

ifdef PKG_COMPILE_CMAKE
COMPILE:
	@cd ${PKG_COMPILE_DIR} && cmake --build ${PKG_COMPILE_MAKE_ADD_OPT} 


${PKG_MAKE_INTALL}:
	@cd ${PKG_COMPILE_DIR} && DESTDIR=${PKG_BUILD_DIR_DPKG}  cmake  ${PKG_COMPILE_MAKE_INSTALL_ADD_OPT}  install
endif	

ifdef PKG_COMPILE_CARGO
COMPILE:
	@cd ${PKG_COMPILE_DIR} && cargo build --release ${PKG_COMPILE_MAKE_ADD_OPT} 

${PKG_MAKE_INTALL}:
	@cd ${PKG_COMPILE_DIR} && cargo install --path ${PKG_BUILD_DIR_DPKG} 
endif	

