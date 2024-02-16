PATH = /sbin:/bin:/usr/sbin:/usr/bin:/usr/libexec:/usr/sbin:/usr/libexec:/usr/sbin:/usr/libexec

PKG_LIST_DIR = extra-cmake-modules  attica  karchive kcodecs kconfig kcoreaddons kdbusaddons kdnssd kguiaddons  ki18n kidletime kimageformats kitemmodels kitemviews kplotting kwidgetsaddons kwindowsystem 
PKG_LIST_DIR += networkmanager-qt solid sonnet threadweaver kauth kcompletion kcrash kdoctools kpty kunitconversion kconfigwidgets kservice kglobalaccel kpackage kdesu kemoticons kiconthemes kjobwidgets
PKG_LIST_DIR += knotifications ktextwidgets kxmlgui kbookmarks kwallet kded kio kdeclarative kcmutils kirigami2 syndication knewstuff frameworkintegration kinit kparts  kactivities kdewebkit

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
		
