
KDE_FRAMEWORK_URL = https://download.kde.org/stable/frameworks/5.115
KDE_FRAMEWORK_VERSION =  5.115.0

PATH = /sbin:/bin:/usr/sbin:/usr/bin:/usr/libexec:/usr/sbin:/usr/libexec:/usr/sbin:/usr/libexec:${ROOT_DIR}/tools/pkg-build

PKG_LIST_DIR =  attica  karchive kcodecs kconfig kcoreaddons kdbusaddons kdnssd kguiaddons  ki18n kidletime kimageformats kitemmodels kitemviews kplotting kwidgetsaddons kwindowsystem 
PKG_LIST_DIR += networkmanager-qt solid sonnet threadweaver kauth kcompletion kcrash kdoctools kpty kunitconversion kconfigwidgets kservice kglobalaccel kpackage kdesu kemoticons kiconthemes kjobwidgets
PKG_LIST_DIR += knotifications ktextwidgets kxmlgui kbookmarks kwallet kded kio kdeclarative kcmutils kirigami2 syndication knewstuff frameworkintegration kinit kparts  kactivities syntax-highlighting ktexteditor
PKG_LIST_DIR += kdesignerplugin kwayland plasma-framework modemmanager-qt kpeople kxmlrpcclient bluez-qt kfilemetadata baloo breeze-icons oxygen-icons5 kactivities-stats krunner prison qqc2-desktop-style kjs kdelibs4support khtml kjsembed kmediaplayer kross kholidays kcalendarcore kcontacts kquickcharts knotifyconfig kdav ark  kmix kdsoap kio-extras konsole libkexiv2 libkdcraw gwenview  kaccounts-integration  plasma-welcome libksysguard kpipewire kdecoration layer-shell-qt libkscreen kscreenlocker kwin  plasma-workspace plasma-desktop breeze breeze-gtk oxygen kinfocenter plasma-disks bluedevil kde-gtk-config khotkeys kmenuedit kscreen kwallet-pam kwayland-integration kwrited milou plasma-nm plasma-pa plasma-workspace-wallpapers  polkit-kde-agent-1 powerdevil  kgamma ksshaskpass plasma-sdk sddm-kcm purpose discover kactivitymanagerd okular plasma-integration xdg-desktop-portal-kde drkonqi plasma-vault plasma-browser-integration kde-cli-tools systemsettings  plasma-thunderbolt plasma-nano plasma-firewall plasma-systemmonitor qqc2-breeze-style  ksystemstats oxygen-sounds  plymouth-kcm breeze-plymouth  kdenlive  plasma-mobile   aura-browser 
#kdewebkit flatpak-kcm

.PHONY:  attica  karchive kcodecs kconfig kcoreaddons kdnssd

# kapidox
# не собираются sgml-common_dpkg
#checkinstall  -D --nodoc --pkgname имя пакета 
##${ROOT_DIR}/instaled/${PKG_NAME}_dpkg
##ifneq (,$(wildcard ${ROOT_DIR}/instaled/$@_dpkg))



export

all: ${PKG_LIST_DIR}


${PKG_LIST_DIR}:
	${MAKE} -C $@_dpkg
		
