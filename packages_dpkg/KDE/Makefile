PATH = /sbin:/bin:/usr/sbin:/usr/bin:/usr/libexec:/usr/sbin:/usr/libexec:/usr/sbin:/usr/libexec

PKG_LIST_DIR = extra-cmake-modules  attica  karchive kcodecs kconfig kcoreaddons kdnssd kguiaddons  ki18n kidletime kimageformats kitemmodels kitemviews kplotting kwidgetsaddons kwindowsystem networkmanager-qt
PKG_LIST_DIR += solid

.PHONY: extra-cmake-modules  attica  karchive kcodecs kconfig kcoreaddons kdnssd

# kapidox
# не собираются sgml-common_dpkg
#checkinstall  -D --nodoc --pkgname имя пакета 
##${ROOT_DIR}/instaled/${PKG_NAME}_dpkg
##ifneq (,$(wildcard ${ROOT_DIR}/instaled/$@_dpkg))



export

all: ${PKG_LIST_DIR}


${PKG_LIST_DIR}:
	${MAKE} -C $@_dpkg
		
