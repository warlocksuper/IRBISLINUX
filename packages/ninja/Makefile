


export NINJAJOBS=1
https://github.com/ninja-build/ninja/archive/v1.11.1/ninja-1.11.1.tar.gz

dpkg: compile install 

compile:
	python3 configure.py --bootstrap
## or cmake -DCMAKE_INSTALL_PREFIX=/usr  CMakeLists.txt
install:
	mkdir DPKG
	mkdir -p DPKG/usr/bin
	mkdir -p DPKG/usr/share/bash-completion/completion/ninja
	mkdir -p DPKG/usr/share/zsh/site-functions/_ninja
	install -vm755 ninja DPKG/usr/bin/
	install -vDm644 misc/bash-completion DPKG/usr/share/bash-completion/completion/ninja/	
	install -vDm644 misc/zsh-completion DPKG/usr/share/zsh/site-functions/_ninja
	cp -r DEBIAN DPKG/
	du -s DPKG | awk '{print $1 }' >> DPKG/DEBIAN/control
