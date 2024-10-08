
PKG_BUILD_DEB_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_DEB_NAME}
PKG_BUILD_DEB_DIR_DPKG = ${PKG_BUILD_DEB_DIR}/DPKG
PKG_BUILD_DIR_DEB_DEBIAN = ${PKG_BUILD_DEB_DIR_DPKG}/DEBIAN/control

PKG_BUILD_DEB_DIR2 = ${PKG_BUILD_DIR_ALL}/${PKG_DEB_NAME2}
PKG_BUILD_DEB_DIR_DPKG2 = ${PKG_BUILD_DEB_DIR2}/DPKG
PKG_BUILD_DIR_DEB_DEBIAN2 = ${PKG_BUILD_DEB_DIR_DPKG2}/DEBIAN/control

PKG_BUILD_DEB_DIR3 = ${PKG_BUILD_DIR_ALL}/${PKG_DEB_NAME3}
PKG_BUILD_DEB_DIR_DPKG3 = ${PKG_BUILD_DEB_DIR3}/DPKG
PKG_BUILD_DIR_DEB_DEBIAN3 = ${PKG_BUILD_DEB_DIR_DPKG3}/DEBIAN/control

PKG_BUILD_DIR_DEB_DEBIAN_DESCR = "Description: пакет для совместимости с Дебиан"
PKG_BUILD_DIR_MAINTAINER = "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>"
PKG_BUILD_DIR_ARH = "Architecture: amd64"


PKG_BUILD_DEB_DIR_DEBIAN:
	install -d ${PKG_BUILD_DEB_DIR_DPKG}/DEBIAN
	@echo "Package: ${PKG_DEB_NAME}" > ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_ARH} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_MAINTAINER} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Section: misc" >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Depends: ${PKG_ORIG} " >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_DEB_DEBIAN_DESCR} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
ifdef PKG_DEB_NAME2
	install -d ${PKG_BUILD_DEB_DIR_DPKG2}/DEBIAN
	@echo "Package: ${PKG_DEB_NAME2}" > ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_ARH} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_MAINTAINER} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Section: misc" >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Depends: ${PKG_ORIG} " >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_DEB_DEBIAN_DESCR} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
endif	
ifdef PKG_DEB_NAME3
	install -d ${PKG_BUILD_DEB_DIR_DPKG3}/DEBIAN
	@echo "Package: ${PKG_DEB_NAME3}" > ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_ARH} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_MAINTAINER} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Section: misc" >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo "Depends: ${PKG_ORIG} " >> ${PKG_BUILD_DIR_DEB_DEBIAN}
	@echo ${PKG_BUILD_DIR_DEB_DEBIAN_DESCR} >> ${PKG_BUILD_DIR_DEB_DEBIAN}
endif	

