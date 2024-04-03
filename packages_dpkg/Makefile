PATH = /sbin:/bin:/usr/sbin:/usr/bin:/usr/libexec:/usr/sbin:/usr/libexec:/usr/sbin:/usr/libexec:${ROOT_TOOLS}/pkg-build

PKG_LIST_DIR = basefile_dpkg dbus_dpkg xf86-input-synaptics_dpkg ncurses_dpkg readline_dpkg #linux_dpkg # glib_dpkg ## linux_dpkg

PKG_LIST_DIR +=   dwz_dpkg psmisc_dpkg cpio_dpkg libxcrypt_dpkg gobject-introspection_dpkg LSB-Tools_dpkg libffi_dpkg make-ca_dpkg brotli_dpkg  p11-kit_dpkg xorg-server_dpkg xcb-util-wm_dpkg xorgproto_dpkg xcb-util-renderutil_dpkg xcb-util-cursor_dpkg   python_modules_dpkg mesa_dpkg 
PKG_LIST_DIR +=  setxkbmap_dpkg pciutils_dpkg docbook_dpkg


## Python

PKG_LIST_DIR +=  pycairo_dpkg  pygobject_dpkg   # doxypypy_dpkg  # Cython_dpkg  надо найти способ создавать пакеты python


#### XORG
PKG_LIST_DIR +=  xf86-input-synaptics_dpkg liboauth_dpkg

### KDE
PKG_LIST_DIR +=  sqlite_dpkg sddm_dpkg  phonon_dpkg phonon-backend-gstreamer_dpkg a52dec_dpkg libmad_dpkg lua_dpkg  vlc_dpkg phonon-backend-vlc_dpkg polkit-qt-1_dpkg libdbusmenu-qt_dpkg   plasma-wayland-protocols_dpkg kuserfeedback_dpkg KDE_dpkg


PKG_LIST_DIR += wayland_dpkg wayland-protocols_dpkg




PKG_LIST_DIR += acpid_dpkg rest_dpkg yaml_dpkg ruby_dpkg harfbuzz_dpkg SDL_dpkg libwebp_dpkg libwpe_dpkg wpebackend-fdo_dpkg enchant_dpkg openjpeg_dpkg 
PKG_LIST_DIR += libhandy_dpkg rsync_dpkg xterm_dpkg  links_dpkg lynx_dpkg libxml2_dpkg lightdm-gtk-greeter_dpkg amtk_dpkg gtksourceview4_dpkg tepl_dpkg libpeas_dpkg gspell_dpkg gedit_dpkg 
PKG_LIST_DIR += upower_dpkg polkit_dpkg gcr3_dpkg  gcr_dpkg gnome-keyring_dpkg mutter_dpkg gnome-shell_dpkg gnome-shell-extensions_dpkg  glu_dpkg pinentry_dpkg cogl_dpkg clutter_dpkg xscreensaver_dpkg
PKG_LIST_DIR += XML-Simple_dpkg hicolor-icon-theme_dpkg icon-naming-utils_dpkg gnome-icon-theme_dpkg gdk-pixbuf_dpkg gdk-pixbuf-xlib_dpkg gnome-icon-theme-extras_dpkg 
PKG_LIST_DIR += gnome-icon-theme-symbolic_dpkg gnome-themes-extra_dpkg  gdm_dpkg  unifdef_dpkg  yasm_dpkg libaom_dpkg libavif_dpkg
PKG_LIST_DIR += krb5_dpkg ConsoleKit_dpkg   libpipeline_dpkg  xfce4-settings_dpkg 
PKG_LIST_DIR += libxslt_dpkg gnome-session_dpkg colord_dpkg colord-gtk_dpkg gnome-online-accounts_dpkg cracklib_dpkg  libpwquality_dpkg libmbim_dpkg  libqmi_dpkg gsound_dpkg gnome-bluetooth_dpkg ModemManager_dpkg  
PKG_LIST_DIR += libgtop_dpkg  libatasmart_dpkg keyutils_dpkg libaio_dpkg  LVM2_dpkg libbytesize_dpkg e2fsprogs_dpkg
PKG_LIST_DIR +=  json-c_dpkg cryptsetup_dpkg libnvme_dpkg  libblockdev_dpkg  udisks_dpkg  gnome-control-center_dpkg 
PKG_LIST_DIR +=  libdaemon_dpkg avahi_dpkg fuse_dpkg  libcdio_dpkg  libcdio-paranoia_dpkg    gvfs_dpkg   
PKG_LIST_DIR +=  librsvg_dpkg  libglade_dpkg   xmlto_dpkg gnome-online-accounts_dpkg xbitmaps_dpkg 

### XFCE4
PKG_LIST_DIR +=   fontconfig_dpkg graphite2_dpkg garcon_dpkg  cairo_dpkg  expat_dpkg libXrender_dpkg xfce4-panel_dpkg check_dpkg  pulseaudio_dpkg  xfce4-pulseaudio-plugin_dpkg  boost_dpkg  mm-common_dpkg libsigc++_dpkg glibmm_dpkg  gtkmm_dpkg  pavucontrol_dpkg 
PKG_LIST_DIR +=   xfce4-taskmanager_dpkg


# не собираются sgml-common_dpkg  gnome-control-center_dpkg gcc_dpkg webkitgtk_dpkg   linux_dpkg    webkitgtk_dpkg

#Sound
PKG_LIST_DIR += alsa-lib_dpkg alsa-plugins_dpkg alsa-utils_dpkg fltk_dpkg   alsa-firmware_dpkg  alsa-oss_dpkg alsa-ucm-conf_dpkg
PKG_LIST_DIR += libass_dpkg  fdk-aac_dpkg lame_dpkg opus_dpkg libtheora_dpkg libvpx_dpkg nasm_dpkg x264_dpkg  x265_dpkg   ffmpeg_dpkg  sbc_dpkg  libfreeaptx_dpkg  # pipewire_dpkg   ##alsa-tools_dpkg



PKG_LIST_DIR += bluez_dpkg blueman_dpkg  sgml-common_dpkg   gtkglext_dpkg  gksu_dpkg  synaptic_dpkg 

export

PKG_LIST =  util-linux systemd bash at-spi2-core attr LMDB libxcvt lzo squashfuse libappimage  qrencode giflib jasper LibRaw poppler kColorPicker kImageAnnotator  qt-everywhere-opensource  qcoro signond libaccounts-glib libaccounts-qt  libpcap plymouth Python   lm-sensors libqalculate signon-plugin-oauth2 libxmlb  AppStream docbook-xml qemu # gtk-doc ostree flatpak  qtwebkit qtwebengine   # node  qtwebengine         ostree  flatpak  mobile-broadband-provider-info NetworkManager gpgme qca # qtwebkit    glibc 




all: ${PKG_LIST} ${PKG_LIST_DIR}
##all:	${PKG_LIST}


python_modules_dpkg:
	${MAKE} -C python_modules

${PKG_LIST}:
	${MAKE} -C $@_pkg

doxypypy_dpkg:
	${MAKE} -C doxypypy


kuserfeedback_dpkg:
	${MAKE} -C kuserfeedback


plasma-wayland-protocols_dpkg:
	${MAKE} -C plasma-wayland-protocols


libdbusmenu-qt_dpkg:
	${MAKE} -C libdbusmenu-qt

polkit-qt-1_dpkg:
	${MAKE} -C polkit-qt

phonon-backend-vlc_dpkg:
	${MAKE} -C phonon-backend-vlc

lua_dpkg:
	${MAKE} -C lua

libmad_dpkg:
	${MAKE} -C libmad

a52dec_dpkg:
	${MAKE} -C a52dec


vlc_dpkg:
	${MAKE} -C vlc

phonon-backend-gstreamer_dpkg:
	${MAKE} -C phonon-backend-gstreamer


gtkglext_dpkg:
	${MAKE} -C gtkglext

gksu_dpkg:
	${MAKE} -C gksu

docbook_dpkg:
	${MAKE} -C docbook

synaptic_dpkg:
	${MAKE} -C synaptic

libfreeaptx_dpkg:
	${MAKE} -C libfreeaptx

sbc_dpkg:
	${MAKE} -C sbc

Cython_dpkg:
	${MAKE} -C Cython

pycairo_dpkg:
	${MAKE} -C pycairo

pygobject_dpkg:
	${MAKE} -C pygobject


blueman_dpkg:
	${MAKE} -C blueman

bluez_dpkg:
	${MAKE} -C bluez

xfce4-taskmanager_dpkg:
	${MAKE} -C xfce4-taskmanager

alsa-ucm-conf_dpkg:
	${MAKE} -C alsa-ucm-conf

xf86-input-synaptics_dpkg:
	${MAKE} -C xf86-input-synaptics

readline_dpkg:
	${MAKE} -C readline

x265_dpkg:
	${MAKE} -C x265

nasm_dpkg:
	${MAKE} -C nasm

x264_dpkg:
	${MAKE} -C x264

libvpx_dpkg:
	${MAKE} -C libvpx

libtheora_dpkg:
	${MAKE} -C libtheora


opus_dpkg:
	${MAKE} -C opus

lame_dpkg:
	${MAKE} -C lame

fdk-aac_dpkg:
	${MAKE} -C fdk-aac

libass_dpkg:
	${MAKE} -C libass


ffmpeg_dpkg:
	${MAKE} -C ffmpeg

pipewire_dpkg:
	${MAKE} -C pipewire


check_dpkg:
	${MAKE} -C check


pulseaudio_dpkg:
	${MAKE} -C pulseaudio

alsa-firmware_dpkg:
	${MAKE} -C alsa-firmware


alsa-oss_dpkg:
	${MAKE} -C alsa-oss


pciutils_dpkg:
	${MAKE} -C pciutils


fltk_dpkg:
	${MAKE} -C fltk

alsa-tools_dpkg:
	${MAKE} -C alsa-tools

alsa-utils_dpkg:
	${MAKE} -C alsa-utils

alsa-plugins_dpkg:
	${MAKE} -C alsa-plugins



alsa-lib_dpkg:
	${MAKE} -C alsa-lib


glibmm_dpkg:
	${MAKE} -C glimm

mm-common_dpkg:
	${MAKE} -C mm-common

libsigc++_dpkg:
	${MAKE} -C libsigc++

boost_dpkg:
	${MAKE} -C boost

gtkmm_dpkg:
	${MAKE} -C gtkmm

pavucontrol_dpkg:
	${MAKE} -C pavucontrol


xfce4-pulseaudio-plugin_dpkg:
	${MAKE} -C xfce4-pulseaudio-plugin

libXrender_dpkg:
	${MAKE} -C libXrender

expat_dpkg:
	${MAKE} -C expat

graphite2_dpkg:
	${MAKE} -C graphite2

fontconfig_dpkg:
	${MAKE} -C fontconfig

cairo_dpkg:
	${MAKE} -C cairo

garcon_dpkg:
	${MAKE} -C garcon

xfce4-panel_dpkg:
	${MAKE} -C xfce4-panel

xbitmaps_dpkg:
	${MAKE} -C xbitmaps

libcdio-paranoia_dpkg:
	${MAKE} -C libcdio-paranoia

libcdio_dpkg:
	${MAKE} -C libcdio

fuse_dpkg:
	${MAKE} -C fuse

libdaemon_dpkg:
	${MAKE} -C libdaemon

avahi_dpkg:
	${MAKE} -C avahi

phonon_dpkg:
	${MAKE} -C phonon

setxkbmap_dpkg:
	${MAKE} -C setxkbmap

sqlite_dpkg:
	${MAKE} -C sqlite

dbus_dpkg:
	${MAKE} -C dbus

wayland-protocols_dpkg:
	${MAKE} -C wayland-protocols

wayland_dpkg:
	${MAKE} -C wayland

gnome-session_dpkg:
	${MAKE} -C gnome-session

libxslt_dpkg:
	${MAKE} -C libxslt

ncurses_dpkg:
	${MAKE} -C ncurses

xfce4-settings_dpkg:
	${MAKE} -C xfce4-settings

libpipeline_dpkg:
	${MAKE} -C libpipeline  

dwz_dpkg:
	${MAKE} -C dwz  

ConsoleKit_dpkg:
	${MAKE} -C ConsoleKit  

krb5_dpkg:
	${MAKE} -C krb5  
	
 libnvme_dpkg:
	${MAKE} -C  libnvme

json-c_dpkg:
	${MAKE} -C json-c

cryptsetup_dpkg:
	${MAKE} -C cryptsetup

e2fsprogs_dpkg:
	${MAKE} -C e2fsprogs

libbytesize_dpkg:
	${MAKE} -C libbytesize

libaio_dpkg:
	${MAKE} -C libaio

LVM2_dpkg:
	${MAKE} -C LVM2

cpio_dpkg:
	${MAKE} -C cpio

psmisc_dpkg:
	${MAKE} -C psmisc
	
upower_dpkg:
	${MAKE} -C upower

keyutils_dpkg:
	${MAKE} -C keyutils

libblockdev_dpkg:
	${MAKE} -C libblockdev

libatasmart_dpkg:
	${MAKE} -C libblockdev

udisks_dpkg:
	${MAKE} -C udisks

libgtop_dpkg:
	${MAKE} -C libgtop

libxcrypt_dpkg:
	${MAKE} -C libxcrypt

LSB-Tools_dpkg:
	${MAKE} -C LSB-Tools

gobject-introspection_dpkg:
	${MAKE} -C gobject-introspection

basefile_dpkg:
	${MAKE} -C basefile

glib_dpkg:
		${MAKE} -C glib	

gcc_dpkg:
		${MAKE} -C gcc	

libffi_dpkg:
		${MAKE} -C  libffi

libhandy_dpkg:
		${MAKE} -C  libhandy
			
linux_dpkg:
		${MAKE} -C linux	
					
make-ca_dpkg:
		${MAKE} -C make-ca

	
brotli_dpkg:
		${MAKE} -C brotli		
		
sgml-common_dpkg:
		${MAKE} -C sgml-common		

xterm_dpkg:
		${MAKE} -C xterm

rsync_dpkg:
		${MAKE} -C rsync

liboauth_dpkg:
		${MAKE} -C liboauth				

polkit_dpkg:
		${MAKE} -C polkit			
		
p11-kit_dpkg:
		${MAKE} -C p11-kit			

acpid_dpkg:
		${MAKE} -C acpid		

sddm_dpkg:
		${MAKE} -C sddm		

gcr3_dpkg:
		${MAKE} -C gcr3

gcr_dpkg:
		${MAKE} -C gcr		

gnome-keyring_dpkg:
		${MAKE} -C gnome-keyring		

XML-Simple_dpkg:
		${MAKE} -C XML-Simple

hicolor-icon-theme_dpkg:
		${MAKE} -C hicolor-icon-theme	

icon-naming-utils_dpkg:
		${MAKE} -C icon-naming-utils

gnome-icon-theme_dpkg:
		${MAKE} -C gnome-icon-theme

gnome-icon-theme-symbolic_dpkg:
		${MAKE} -C gnome-icon-theme-symbolic

libavif_dpkg:
		${MAKE} -C libavif

libpwquality_dpkg:
		${MAKE} -C libpwquality

cracklib_dpkg:
		${MAKE} -C cracklib

colord_dpkg:
		${MAKE} -C colord

colord-gtk_dpkg:
		${MAKE} -C colord-gtk

gsound_dpkg:
		${MAKE} -C gsound

gnome-bluetooth_dpkg:
		${MAKE} -C gnome-bluetooth

libqmi_dpkg:
		${MAKE} -C libqmi

libmbim_dpkg:
		${MAKE} -C libmbim


ModemManager_dpkg:
		${MAKE} -C ModemManager

libaom_dpkg:
		${MAKE} -C libaom

gdk-pixbuf-xlib_dpkg:
		${MAKE} -C gdk-pixbuf-xlib

gnome-icon-theme-extras_dpkg:
		${MAKE} -C gnome-icon-theme-extras

gnome-themes-extra_dpkg:
		${MAKE} -C gnome-themes-extra
		
yasm_dpkg:
		${MAKE} -C yasm
		
unifdef_dpkg:
		${MAKE} -C unifdef
		 
gvfs_dpkg:
		${MAKE} -C gvfs

glu_dpkg:
		${MAKE} -C glu

clutter_dpkg:
		${MAKE} -C clutter

pinentry_dpkg:
		${MAKE} -C pinentry

cogl_dpkg:
		${MAKE} -C cogl

mutter_dpkg:
	${MAKE} -C mutter	

gnome-shell-extensions_dpkg:
		${MAKE} -C gnome-shell-extensions
		
gnome-shell_dpkg:
		${MAKE} -C gnome-shell	

gdm_dpkg:
		${MAKE} -C gdm	

gnome-control-center_dpkg:
		${MAKE} -C gnome-control-center		
		
KDE_dpkg:
		${MAKE} -C KDE				
		
xorg-server_dpkg:
		${MAKE} -C xorg-server
		
xcb-util-wm_dpkg:
		${MAKE} -C xcb-util-wm
		
xorgproto_dpkg:
		${MAKE} -C xorgproto
		
xcb-util-renderutil_dpkg:
		${MAKE} -C xcb-util-renderutil
		
xcb-util-cursor_dpkg:
		${MAKE} -C xcb-util-cursor		
		
mesa_dpkg:
		${MAKE} -C mesa
		
rest_dpkg:
		${MAKE} -C rest	

yaml_dpkg:
		${MAKE} -C yaml

ruby_dpkg:
		${MAKE} -C ruby

harfbuzz_dpkg:
		${MAKE} -C harfbuzz

SDL_dpkg:
		${MAKE} -C SDL

libwebp_dpkg:
		${MAKE} -C libwebp

libwpe_dpkg:
		${MAKE} -C libwpe
		
wpebackend-fdo_dpkg:
		${MAKE} -C wpebackend-fdo

enchant_dpkg:
		${MAKE} -C enchant

openjpeg_dpkg:
		${MAKE} -C openjpeg

links_dpkg:
		${MAKE} -C links

lynx_dpkg:
		${MAKE} -C lynx

libxml2_dpkg:
		${MAKE} -C libxml2

libglade_dpkg:
		${MAKE} -C libglade

xmlto_dpkg:
		${MAKE} -C xmlto

xdg-utils_dpkg:
		${MAKE} -C xdg-utils

lightdm-gtk-greeter_dpkg:
		${MAKE} -C lightdm-gtk-greeter

amtk_dpkg:
		${MAKE} -C amtk

gtksourceview4_dpkg:
		${MAKE} -C gtksourceview4

tepl_dpkg:
		${MAKE} -C tepl


libpeas_dpkg:
		${MAKE} -C libpeas

gspell_dpkg:
		${MAKE} -C gspell

gedit_dpkg:
		${MAKE} -C gedit

xscreensaver_dpkg:
		${MAKE} -C xscreensaver

librsvg_dpkg:
		${MAKE} -C librsvg

gdk-pixbuf_dpkg:
		${MAKE} -C gdk-pixbuf

webkitgtk_dpkg:
		${MAKE} -C webkitgtk
		
		
		
gnome-online-accounts_dpkg:
		${MAKE} -C gnome-online-accounts			
													
