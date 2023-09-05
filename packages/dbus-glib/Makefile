OS_CONFIG = ${ROOT_DIR}/.config
include ${OS_CONFIG}


PKG_NAME = dbus-glib-0.112
PKG_URL = https://dbus.freedesktop.org/releases/dbus-glib/dbus-glib-0.112.tar.gz
PGK_SOURCE_DIR = ${ROOT_SOURCE}/${PKG_NAME}

all:

GLIB_CFLAGS="-I/include/glib-2.0 -I/lib/glib-2.0/include"  GLIB_LIBS="-lglib-2.0" Configuresd 
