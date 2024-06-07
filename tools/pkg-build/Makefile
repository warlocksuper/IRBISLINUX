

all:
	$(CXX)  exist.c -o pkg-exist
	LIBDPKG_VOLATILE_API=1 $(CXX) create_dep_deb_pkg.cpp package.cpp -o create_dep_deb_pkg -lstdc++ -lboost_filesystem -ldpkg -lmd -llzma -lbz2 -lz -fpermissive
	
	
clean:
	@rm -rf pkg-exist
	@rm -rf create_dep_deb_pkg
