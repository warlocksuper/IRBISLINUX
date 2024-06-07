
${PKG_BUILD_DIR_DEBIAN}:
	@find ${PKG_BUILD_DIR_DPKG} -name "*.la" -type f -delete
	@rm -rf ${PKG_BUILD_DIR_DPKG}/usr/share/info/dir
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	@echo "Package: ${PKG_NAME}" > ${PKG_BUILD_DIR_DEBIAN}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Provides: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
ifdef PKG_BUILD_REPLACES
	@echo "Replaces: ${PKG_BUILD_REPLACES}" >> ${PKG_BUILD_DIR_DEBIAN}
endif	
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEPANDS} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEST} >> ${PKG_BUILD_DIR_DEBIAN}
	@cp postinst ${PKG_BUILD_DIR_DPKG}/DEBIAN/
