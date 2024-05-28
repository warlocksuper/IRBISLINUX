OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}



COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 6.1.92
PKG_NAME = linux
PKG_URL =  https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.1.92.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: basefile(>=0.2)  "
PKG_NAME1 = linux-headers
PKG_NAME2 = linux-modules
PKG_NAME3 = linux-kernel




PKG_DEBIAN_SECTION = "Section: linux"

PKG_DEBIAN_DEST = "Description: linux headers."
PKG_DEBIAN_DEST2 = "Description: linux modules."
PKG_DEBIAN_DEST3 = "Description: kernel linux."


PKG_COMPILE = ${PGK_BUILD_DIR}/icccm/.libs/libxcb-icccm.so


PKG_DPKG_FILE = ${PKG_NAME1}.${PKG_VERSION}.deb 
PKG_DPKG_FILE2 = ${PKG_NAME2}.${PKG_VERSION}.deb 
PKG_DPKG_FILE3 = ${PKG_NAME3}.${PKG_VERSION}.deb 


PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG_HEADER
PKG_BUILD_DIR_DPKG2 = ${PKG_BUILD_DIR}/DPKG_MODULES
PKG_BUILD_DIR_DPKG3 = ${PKG_BUILD_DIR}/DPKG_KERNEL


PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control
PKG_BUILD_DIR_DEBIAN2 = ${PKG_BUILD_DIR_DPKG2}/DEBIAN/control
PKG_BUILD_DIR_DEBIAN3 = ${PKG_BUILD_DIR_DPKG3}/DEBIAN/control


PKG_DPKG_FILE_PATH = ${PKG_BUILD_DIR}/${PKG_DPKG_FILE}

PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


all: ${PKG_BUILD_DIR_ALL} ${PKG_BUILD_DIR_DPKG} ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN} ${PKG_DPKG_FILE_PATH}

${PKG_BUILD_DIR_ALL}:
	@mkdir -p ${PKG_BUILD_DIR_ALL}
	
${PKG_BUILD_DIR}:
	@mkdir -p ${PKG_BUILD_DIR}

${PKG_BUILD_DIR_DPKG}:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${PKG_BUILD_DIR_DPKG2}
	@mkdir -p ${PKG_BUILD_DIR_DPKG3}/boot


${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_CONFIGURE}:
	@mkdir -p ${PKG_BUILD_DIR}
#	@cd ${PGK_SOURCE_DIR} && patch -Np1 -i  ${ROOT_DIR}/packages_dpkg/linux/patch-6.1.76
	@cd ${PGK_SOURCE_DIR} && make mrproper
	@cp CONFIG ${PGK_SOURCE_DIR}/.config
#	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/configure --prefix=/usr  --sysconfdir=/etc --localstatedir=/var --enable-static=no

${PKG_COMPILE}:
	@cd ${PGK_SOURCE_DIR} && make headers
	@cd ${PGK_SOURCE_DIR} && make 


${PKG_MAKE_INTALL}:
	find ${PGK_SOURCE_DIR}/usr/include -type f ! -name '*.h' -delete
	install -d ${PKG_BUILD_DIR_DPKG}/usr/include/
	cp -rv ${PGK_SOURCE_DIR}/usr/include/* ${PKG_BUILD_DIR_DPKG}/usr/include/
	install -d ${PKG_BUILD_DIR_DPKG2}/usr
	cd ${PGK_SOURCE_DIR} && make INSTALL_MOD_PATH=${PKG_BUILD_DIR_DPKG2}/usr modules_install
	install -d ${PKG_BUILD_DIR_DPKG3}/usr
	cp -iv ${PGK_SOURCE_DIR}/arch/x86/boot/bzImage ${PKG_BUILD_DIR_DPKG3}/boot/vmlinuz-${PKG_VERSION}-irbislinux
	cp -iv ${PGK_SOURCE_DIR}/System.map ${PKG_BUILD_DIR_DPKG3}/boot/System.map-${PKG_VERSION}
	cp -iv ${PGK_SOURCE_DIR}/.config  ${PKG_BUILD_DIR_DPKG3}/boot/config-${PKG_VERSION}





${PKG_BUILD_DIR_DEBIAN}:
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	install -d ${PKG_BUILD_DIR_DPKG2}/DEBIAN
	install -d ${PKG_BUILD_DIR_DPKG3}/DEBIAN
	@echo "Package: ${PKG_NAME1}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEPANDS} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEST} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Package: ${PKG_NAME2}" >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo ${PKG_DEBIAN_DEPANDS} >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo ${PKG_DEBIAN_DEST2} >> ${PKG_BUILD_DIR_DEBIAN2}
	@echo "Package: ${PKG_NAME3}" >> ${PKG_BUILD_DIR_DEBIAN3}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN3}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN3}
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN3}
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN3}
	@echo ${PKG_DEBIAN_DEPANDS} >> ${PKG_BUILD_DIR_DEBIAN3}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN3}
	@echo ${PKG_DEBIAN_DEST3} >> ${PKG_BUILD_DIR_DEBIAN3}


	
${PKG_DPKG_FILE_PATH}:
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG2}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG2} ${PKG_DPKG_FILE2}
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG3}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG3} ${PKG_DPKG_FILE3}
	@echo "" > ${ROOT_DIR}/packages_dpkg/${PKG_NAME}_dpkg
	
