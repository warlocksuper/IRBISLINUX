OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_VERSION = 1.0.8
PKG_NAME = bzip2
PKG_URL =  https://www.sourceware.org/pub/bzip2/bzip2-1.0.8.tar.gz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends:  "
PKG_DEBIAN_SECTION = "Section: system"
PKG_DEBIAN_DEST = "Description: The Bzip2 package contains programs for compressing and decompressing files. Compressing text files with bzip2 yields a much better compression percentage than with the traditional gzip."
#PKG_BUILD_REPLACES = " inetutils "


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb
#PKG_COMPILE_MAKE_INSTALL_ADD_OPT = MANSUFFIX=ssl


PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}

PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

PKG_COMPILE_MAKE = ""
#PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PGK_SOURCE_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги


.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE, DEL_ANY_FILE

PKG_COMPLITE =  $(shell if [ -f "${PKG_DPKG_FILE_PATH}" ]; then echo "1"; else echo "0"; fi ) ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip $(PKG_COMPLITE)),$(strip 0))
all: BUILD_DIR  ${PKG_TAR} ${PGK_SOURCE_DIR} PKG_CONFIGURE COMPILE ${PKG_MAKE_INTALL} ${PKG_BUILD_DIR_DEBIAN} 
	sudo chown root:root -R ${PKG_BUILD_DIR_DPKG}
	@cd ${ROOT_DPKG_ARCH} && sudo dpkg-deb --build ${PKG_BUILD_DIR_DPKG} ${PKG_DPKG_FILE}
	sudo dpkg -i ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

BUILD_DIR:
	@mkdir -p ${PKG_BUILD_DIR_DPKG}
	@mkdir -p ${ROOT_SOURCE}

${PKG_TAR}:
	wget ${PKG_URL} -P ${ROOT_SOURCE}/


${PGK_SOURCE_DIR}:
	@cd ${ROOT_SOURCE} && tar -xf ${PKG_TAR_FILE}

PKG_CONFIGURE:
#	@cd ${PKG_BUILD_DIR} && ${PGK_SOURCE_DIR}/${CONFIGURE} 


#include ${ROOT_DIR}/scripts/compile.mk
COMPILE:
	@cd ${PGK_SOURCE_DIR} && make  -f Makefile-libbz2_so 
	install -d ${PKG_BUILD_DIR_DPKG}/DEBIAN
	install -d ${PKG_BUILD_DIR_DPKG}/usr/bin
	install -d ${PKG_BUILD_DIR_DPKG}/usr/lib
	install -d ${PKG_BUILD_DIR_DPKG}/usr/include
	@cd ${PGK_SOURCE_DIR} && cp -r libbz2.so.1.0 ${PKG_BUILD_DIR_DPKG}/usr/lib/libbz2.so.1.0
	@cd ${PGK_SOURCE_DIR} && cp -r libbz2.so.1.0.8 ${PKG_BUILD_DIR_DPKG}/usr/lib/libbz2.so.1.0.8
	@cd ${PGK_SOURCE_DIR} && cp -r bzip2-shared ${PKG_BUILD_DIR_DPKG}/usr/bin/bzip2	
	@cd ${PGK_SOURCE_DIR} && cp -r bzlib.h ${PKG_BUILD_DIR_DPKG}/usr/include/	
	@cd ${PKG_BUILD_DIR_DPKG}/usr/bin && ln -sfv bzip2 bzcat
	@cd ${PKG_BUILD_DIR_DPKG}/usr/bin && ln -sfv bzip2 bunzip2
	@cd ${PKG_BUILD_DIR_DPKG}/usr/lib && ln -sv libbz2.so.1.0.8 libbz2.so

include ${ROOT_DIR}/scripts/build_dpkg.mk

else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif	
