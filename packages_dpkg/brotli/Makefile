OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}



COPY_ROOTFS = ${ROOT_FS}/etc

PKG_VERSION = 1.0.9
PKG_NAME = brotli
PKG_URL = https://github.com/google/brotli/archive/v1.0.9/brotli-1.0.9.tar.gz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: cmake(>=3.27.0-rc4)"


PKG_DEBIAN_SECTION = "Section: libraries"
PKG_DEBIAN_DEST = "Description: Brotli provides a general-purpose lossless compression algorithm that compresses data using a combination of a modern variant of the LZ77 algorithm, Huffman coding and 2nd order context modeling. Its libraries are particularly used for WOFF2 fonts on webpages."


PKG_COMPILE = ${PKG_BUILD_DIR}/brotli


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 

PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}
PKG_BUILD_DIR_ALL = ${ROOT_DIR}/build_dpkg
PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DIR}/DPKG/${PKG_DPKG_FILE}
PKG_CONFIGURE = ${PKG_BUILD_DIR}/Makefile


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
	@cd ${PKG_BUILD_DIR} && cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release ${PGK_SOURCE_DIR} 

${PKG_COMPILE}:
	${MAKE} -C ${PKG_BUILD_DIR}


${PKG_MAKE_INTALL}:
	${MAKE} -C ${PKG_BUILD_DIR} DESTDIR=${PKG_BUILD_DIR_DPKG} install
	@mv ${PKG_BUILD_DIR_DPKG}/usr/lib64 ${PKG_BUILD_DIR_DPKG}/usr/lib

${PKG_BUILD_DIR_DEBIAN}:
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