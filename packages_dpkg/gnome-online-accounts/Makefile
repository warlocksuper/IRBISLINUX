OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

#depand rest WebKitGTK

COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 3.46.0
PKG_NAME = gnome-online-accounts
PKG_URL = https://download.gnome.org/sources/gnome-online-accounts/3.46/gnome-online-accounts-3.46.0.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: gcr(>=4.0.0), json-glib(>=1.6.6) rest(>=0.9.1) "


PKG_DEBIAN_SECTION = "Section: xorg"

PKG_DEBIAN_DEST = "Description: he GNOME Online Accounts package contains a framework used to access the user's online accounts."

PKG_COMPILE = ${PGK_BUILD_DIR}/icccm/.libs/libxcb-icccm.so


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

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
	@cd ${PKG_BUILD_DIR} && meson --prefix=/usr --buildtype=release -Dkerberos=false -Dgoogle_client_secret=5ntt6GbbkjnTVXx-MSxbmx5e -Dgoogle_client_id=595013732528-llk8trb03f0ldpqq6nprjp1s79596646.apps.googleusercontent.com ${PGK_SOURCE_DIR}

${PKG_COMPILE}: 
	@cd ${PKG_BUILD_DIR} && ninja


${PKG_MAKE_INTALL}:  
	@cd ${PKG_BUILD_DIR} && DESTDIR=${PKG_BUILD_DIR_DPKG} ninja install

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
	