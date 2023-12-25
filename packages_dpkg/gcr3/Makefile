OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}



COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 3.41.1
PKG_NAME = gcr3
PKG_URL =  https://download.gnome.org/sources/gcr/3.41/gcr-3.41.1.tar.xz
PKG_TAR_FILE = gcr-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/gcr-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends:  glib(>=2.74.5), libgcrypt(>=1.10.1), p11-kit(>=0.24.1)  "


PKG_DEBIAN_SECTION = "Section: library"

PKG_DEBIAN_DEST = "Description: The Gcr package contains libraries used for displaying certificates and accessing key stores. It also provides the viewer for crypto files on the GNOME Desktop."

PKG_COMPILE = ${PGK_BUILD_DIR}/icccm/.libs/libxcb-icccm.so


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${PKG_BUILD_DIR}/${PKG_DPKG_FILE}

PKG_CONFIGURE = ${PGK_BUILD_DIR}/Makefile


all: ${PKG_BUILD_DIR_ALL} ${PKG_BUILD_DIR_DPKG} ${PKG_TAR} ${PGK_SOURCE_DIR} ${PKG_CONFIGURE} ${PKG_COMPILE} ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN} ${PKG_DPKG_FILE_PATH}

${PKG_BUILD_DIR_ALL}:
	@mkdir -p ${PKG_BUILD_DIR_ALL}
	
${PKG_BUILD_DIR}:
	@mkdir -p ${PKG_BUILD_DIR}

${PKG_BUILD_DIR_DPKG}:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}


${PKG_TAR}:
	@mkdir -p ${ROOT_FS}
	@mkdir -p ${ROOT_SOURCE}
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

${PKG_CONFIGURE}:
	@mkdir -p ${PKG_BUILD_DIR}
	@sed -i 's:"/desktop:"/org:' ${PGK_SOURCE_DIR}/schema/*.xml
	@cd ${PKG_BUILD_DIR} &&  meson --prefix=/usr --buildtype=release -Dgtk_doc=false  ${PGK_SOURCE_DIR} 

${PKG_COMPILE}:
	@cd ${PKG_BUILD_DIR} && ninja


${PKG_MAKE_INTALL}:
	@cd ${PKG_BUILD_DIR} && DESTDIR=${PKG_BUILD_DIR_DPKG}  ninja  install
	@rm ${PKG_BUILD_DIR_DPKG}/usr/lib/systemd/user/gcr-ssh-agent.service
	@rm ${PKG_BUILD_DIR_DPKG}/usr/lib/systemd/user/gcr-ssh-agent.socket
	@rm ${PKG_BUILD_DIR_DPKG}/usr/libexec/gcr-ssh-agent

${PKG_BUILD_DIR_DEBIAN}:
	@find ${PKG_BUILD_DIR_DPKG} -name "*.la" -type f -delete
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	@echo "Package: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Architecture: amd64" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Version: ${PKG_VERSION}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Provides: ${PKG_NAME}" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Maintainer: Dmitry Lebedev <D.Lebedev@irbis.su>" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_SECTION} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEPANDS} >> ${PKG_BUILD_DIR_DEBIAN}
	@echo "Installed-Size: `du -s ${PKG_BUILD_DIR_DPKG} | cut -f1`" >> ${PKG_BUILD_DIR_DEBIAN}
	@echo ${PKG_DEBIAN_DEST} >> ${PKG_BUILD_DIR_DEBIAN}
	@cp postinst ${PKG_BUILD_DIR_DPKG}/DEBIAN/	
	
${PKG_DPKG_FILE_PATH}:
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	@echo "" > ${ROOT_DIR}/packages_dpkg/${PKG_NAME}_dpkg
