OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}



COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 384
PKG_NAME = xterm
PKG_URL = https://invisible-mirror.net/archives/xterm/xterm-384.tgz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tgz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: basefiles "


PKG_DEBIAN_SECTION = "Section: xorg"

PKG_DEBIAN_DEST = "Description: xterm is a terminal emulator for the X Window System."

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
	@sed -i '/v0/{n;s/new:/new:kb=^?:/}' ${PGK_SOURCE_DIR}/termcap 
	@printf '\tkbs=\\177,\n' >> ${PGK_SOURCE_DIR}/terminfo
	@cd ${PKG_BUILD_DIR} && TERMINFO=/usr/share/terminfo ${PGK_SOURCE_DIR}/configure --prefix=/usr  --sysconfdir=/etc --localstatedir=/var  --with-app-defaults=/etc/X11/app-defaults

${PKG_COMPILE}:
	@cd ${PKG_BUILD_DIR} && make


${PKG_MAKE_INTALL}:
	@cd ${PKG_BUILD_DIR} && make DESTDIR=${PKG_BUILD_DIR_DPKG} install
	@cd ${PKG_BUILD_DIR} && make DESTDIR=${PKG_BUILD_DIR_DPKG} install-ti
	@rm -rf ${PKG_BUILD_DIR_DPKG}/usr/share/terminfo/a/ansi+enq

${PKG_BUILD_DIR_DEBIAN}:
	@find ${PKG_BUILD_DIR_DPKG} -name "*.la" -type f -delete
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	install -d ${PKG_BUILD_DIR_DPKG}//usr/share/applications
	install -d ${PKG_BUILD_DIR_DPKG}/etc/X11/app-defaults/
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
	@cp XTerm ${PKG_BUILD_DIR_DPKG}/etc/X11/app-defaults/
	@cd ${PGK_SOURCE_DIR} && 	cp -v *.desktop   ${PKG_BUILD_DIR_DPKG}/usr/share/applications/
	@echo "/etc/X11/app-defaults/XTerm"  >  ${PKG_BUILD_DIR_DPKG}/DEBIAN/conffiles
	
${PKG_DPKG_FILE_PATH}:
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	@echo "" > ${ROOT_DIR}/packages_dpkg/${PKG_NAME}_dpkg
