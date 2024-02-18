
ifdef PKG_COMPILE_MAKE
COMPILE:
	pip3 wheel -w ${PKG_BUILD_DIR}  --no-build-isolation --no-deps ${PGK_SOURCE_DIR}


${PKG_MAKE_INTALL}:
	install -d ${PKG_BUILD_DIR_DPKG}/usr/lib/python3.11/site-packages/
	@cd ${PKG_COMPILE_DIR} && pip3 install --target=${PKG_BUILD_DIR_DPKG}/usr/lib/python3.11/site-packages/  --no-index --find-links ${PKG_BUILD_DIR}  --no-cache-dir --no-user ${PKG_NAME}
endif	

ifdef PKG_COMPILE_NINJA
COMPILE:
	@cd ${PKG_COMPILE_DIR} && ninja


${PKG_MAKE_INTALL}:
	@cd ${PKG_COMPILE_DIR} && DESTDIR=${PKG_BUILD_DIR_DPKG}  ninja install
endif	
