#!/bin/sh

echo remove pkg $1

rm -rf packages_dpkg/$1_dpkg
rm -rf DPKG/$1*
sudo rm -rf build_dpkg/$1

