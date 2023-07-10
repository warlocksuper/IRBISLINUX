#!/bin/sh

##GLIB_CFLAGS=/usr/lib GLIB_LIBS=/usr/lib

ROOT_DIR=`pwd`/rootfs
sudo mkdir -p $ROOT_DIR/dev
sudo mount -v --bind /dev $ROOT_DIR/dev

sudo mount -v --bind /dev/pts $ROOT_DIR/dev/pts
sudo mkdir -p $ROOT_DIR/proc
sudo mount -vt proc proc $ROOT_DIR/proc
sudo mkdir -p $ROOT_DIR/sys
sudo mount -vt sysfs sysfs $ROOT_DIR/sys
sudo mkdir -p $ROOT_DIR/tmp
sudo mount -vt tmpfs tmpfs $ROOT_DIR/tmp
sudo busybox chroot rootfs /usr/bin/env -i   \
    HOME=/root                  \
    LANG=en_US.UTF-8		\
    GLIB_CFLAGS=-I/usr/include	\
    GLIB_LIBS=-I/usr/lib	\
    TERM="$TERM"                \
    PS1='(IRBIS) \u:\w\$ ' \
    PATH=/usr/bin:/usr/sbin     \
    /bin/bash --login
