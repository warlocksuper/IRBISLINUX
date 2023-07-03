#!/bin/sh


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
