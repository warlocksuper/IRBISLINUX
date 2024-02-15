OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PKG_SRC_URL = https://download.kde.org/stable/frameworks/5.109

PKG_VERSION = 5.109.0
PKG_NAME = extra-cmake-modules
PKG_URL =   ${PKG_SRC_URL}/extra-cmake-modules-5.109.0.tar.xz
PKG_TAR_FILE = ${PKG_NAME}-${PKG_VERSION}.tar.xz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends: cmake(>=3.27.0-rc4) "

PKG_DEBIAN_SECTION = "Section: kde"

PKG_DEBIAN_DEST = "Description: The Extra Cmake Modules package contains extra CMake modules used by KDE Frameworks 5 and other packages."

PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb 
PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}

PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

PKG_COMPILE_MAKE = ""
# PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги


.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE

PKG_COMPLITE =  $(shell if [ -f "${PKG_DPKG_FILE_PATH}" ]; then echo "1"; else echo "0"; fi ) ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip $(PKG_COMPLITE)),$(strip "0"))
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
	@cd ${PGK_SOURCE_DIR} && sed -i '/"lib64"/s/64//' ${PGK_SOURCE_DIR}/kde-modules/KDEInstallDirsCommon.cmake
	@cd ${PGK_SOURCE_DIR} && sed -e '/PACKAGE_INIT/i set(SAVE_PACKAGE_PREFIX_DIR "${PACKAGE_PREFIX_DIR}")'  -e '/^include/a set(PACKAGE_PREFIX_DIR "${SAVE_PACKAGE_PREFIX_DIR}")' -i  ${PGK_SOURCE_DIR}/ECMConfig.cmake.in 
	@cd ${PKG_BUILD_DIR} && $(CMAKE)  ${PGK_SOURCE_DIR}

include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk

else
all: 
	@echo "Уже собранно ${PKG_NAME}"	
endif		
	
	
	
