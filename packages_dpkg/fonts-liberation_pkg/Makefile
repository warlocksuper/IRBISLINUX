OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 2.1.5
PKG_NAME = fonts-liberation
PKG_ORIG = liberation-fonts(>=2.1.5)

PKG_DEBIAN_SECTION = "Section: misc"
PKG_DEBIAN_DEST = "Description: пакет для совместимости с Дебиан"


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 


PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${PKG_BUILD_DIR}/${PKG_DPKG_FILE}


${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}: ${PKG_BUILD_DIR_DPKG}  ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN}
	@echo "Собираем пакет ${PKG_NAME}"
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

${PKG_BUILD_DIR_DPKG}:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}

${PKG_MAKE_INTALL}:
	install -d ${PKG_BUILD_DIR_DPKG}/usr/share/deb
	@echo "${PKG_VERSION}" >  ${PKG_BUILD_DIR_DPKG}/usr/share/deb/${PKG_NAME}

${PKG_BUILD_DIR_DEBIAN}:
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	@echo "Package: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Depends: ${PKG_ORIG} " >> ${PKG_BUILD_DIR_DEBIAN} 
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEST} >> ${PKG_BUILD_DIR_DEBIAN}	
	
