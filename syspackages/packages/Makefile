include ../.config


export

obj-${CONFIG_OS_PERL} += perl
obj-${CONFIG_OS_PYTHON} += python


${obj-y}:
	echo $@
	${MAKE} -C $@_pkg
	
