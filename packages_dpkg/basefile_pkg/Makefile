OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 0.3
PKG_NAME = basefile

PKG_DEBIAN_SECTION = "Section: system"
PKG_DEBIAN_DEST = "Description: Базовые файлы для линукса IRBIS"


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
	@cp -r skeleton/* ${PKG_BUILD_DIR_DPKG}/
	install -d ${PKG_BUILD_DIR_DPKG}/usr/lib
	install -d ${PKG_BUILD_DIR_DPKG}/bin
	install -d ${PKG_BUILD_DIR_DPKG}/dev
	install -d ${PKG_BUILD_DIR_DPKG}/home
	install -d ${PKG_BUILD_DIR_DPKG}/media
	install -d ${PKG_BUILD_DIR_DPKG}/proc
	install -d ${PKG_BUILD_DIR_DPKG}/run
	install -d ${PKG_BUILD_DIR_DPKG}/sbin
	install -d ${PKG_BUILD_DIR_DPKG}/sys
	install -d ${PKG_BUILD_DIR_DPKG}/tmp
	install -d ${PKG_BUILD_DIR_DPKG}/var/log
	ln -sr ${PKG_BUILD_DIR_DPKG}/etc/irbis-release ${PKG_BUILD_DIR_DPKG}/etc/os-release
	ln -sr ${PKG_BUILD_DIR_DPKG}/usr/lib ${PKG_BUILD_DIR_DPKG}/lib
	ln -sr ${PKG_BUILD_DIR_DPKG}/usr/lib ${PKG_BUILD_DIR_DPKG}/lib64
	ln -sr ${PKG_BUILD_DIR_DPKG}/usr ${PKG_BUILD_DIR_DPKG}/usr/local
	ln -sr ${PKG_BUILD_DIR_DPKG}/usr/lib ${PKG_BUILD_DIR_DPKG}/usr/lib64
	ln -sr ${PKG_BUILD_DIR_DPKG}/run ${PKG_BUILD_DIR_DPKG}/var/run	

${PKG_BUILD_DIR_DEBIAN}:
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	@cp DEBIAN/conffiles ${PKG_BUILD_DIR_DPKG}/DEBIAN/
	@echo "Package: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Provides: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Replaces: bash-completion " >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEST} >> ${PKG_BUILD_DIR_DEBIAN}	
	
