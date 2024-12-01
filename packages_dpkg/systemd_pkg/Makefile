OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}

PATH = $(shell printenv PATH):${ROOT_DIR}/scripts:${ROOT_DIR}/tools/pkg-build/
export  PATH

PKG_VERSION = 256.6
PKG_NAME = systemd
PKG_URL =  https://github.com/systemd/systemd/archive/refs/tags/v256.6.tar.gz  ##https://github.com/systemd/systemd/archive/v255/systemd-255.tar.gz
PKG_TAR_FILE = v${PKG_VERSION}.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}-${PKG_VERSION}
PKG_DEBIAN_DEPANDS = "Depends:  libseccomp(>=2.5.5-3), util-linux(>=2.40.1), kmod(>=31), openssl(>=3.2.1), zstd(>=1.5.4), libxcrypt(>=4.4.36)"
PKG_DEBIAN_SECTION = "Section: system"
PKG_DEBIAN_DEST = "Description: system and service manager."
PKG_BUILD_REPLACES = " elogind, eudev, sysvinit "


PKG_DPKG_FILE = ${PKG_NAME}.${PKG_VERSION}.deb



PKG_TAR = ${ROOT_SOURCE}/${PKG_TAR_FILE}

PKG_BUILD_DIR = ${PKG_BUILD_DIR_ALL}/${PKG_NAME}
PKG_BUILD_DIR_DPKG = ${PKG_BUILD_DIR}/DPKG
PKG_MAKE_INTALL = ${PKG_BUILD_DIR_DPKG}/usr
PKG_BUILD_DIR_DEBIAN = ${PKG_BUILD_DIR_DPKG}/DEBIAN/control

PKG_DPKG_FILE_PATH = ${ROOT_DPKG_ARCH}/${PKG_DPKG_FILE}

#PKG_COMPILE_MAKE = ""
PKG_COMPILE_NINJA = ""
PKG_COMPILE_DIR = ${PKG_BUILD_DIR}  # может быть ${PGK_SOURCE_DIR} для компиляции в папке исходников или ${PKG_BUILD_DIR}  для компиляции в отдельном каталоги


.PHONY:  all, COMPILE, BUILD_DIR, PKG_CONFIGURE, DEL_ANY_FILE

PKG_COMPLITE =  $(shell pkg-exist ${PKG_DPKG_FILE_PATH})   ## определяет естьли собранный файл пакета если нет собираем

ifeq ($(strip "$(PKG_COMPLITE)"),$(strip "0  "))
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
	@cd ${PKG_BUILD_DIR} && $(MESON)  -Ddefault-dnssec=no -Dfirstboot=false -Dinstall-tests=false -Dldconfig=false        \
      -Dman=false              \
      -Dsysusers=false        \
      -Drpmmacrosdir=no       \
      -Dhomed=disabled        \
      -Duserdb=false          \
      -Dmode=release          \
      -Dpam=enabled           \
      -Dpamconfdir=/etc/pam.d \
      -Ddev-kvm-mode=0660     \
      -Dnobody-group=nogroup  \
      -Dsysupdate=disabled    \
          -Dbootloader=disabled \
      -Dsbat-distro='irbis' \
     -Dsbat-distro-summary='IRBIS Linux' \
     -Dsbat-distro-pkgname="${PKG_NAME}" \
     -Dsbat-distro-version="${PKG_VERSION}" \
     -Dsbat-distro-url="https://irbis.su/support" \
      -Dukify=enabled  ${PGK_SOURCE_DIR}  

include ${ROOT_DIR}/scripts/compile.mk

include ${ROOT_DIR}/scripts/build_dpkg.mk

else
all: 
	@echo "Уже собранно ${PKG_COMPLITE} ${PKG_NAME}"	
endif	
