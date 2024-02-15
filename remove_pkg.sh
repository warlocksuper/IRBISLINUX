#!/bin/sh

echo remove pkg $1

rm -rf packages_dpkg/$1_dpkg
rm -rf DPKG/$1*
rm -rf instaled/$1_dpkg
sudo rm -rf build_dpkg/$1

