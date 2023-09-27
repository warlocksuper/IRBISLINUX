https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.7/llvm-15.0.7.src.tar.xz

https://anduin.linuxfromscratch.org/BLFS/llvm/llvm-cmake-15.0.7.src.tar.xz
https://github.com/llvm/llvm-project/releases/download/llvmorg-15.0.7/clang-15.0.7.src.tar.xz

tar -xf llvm-15.0.7.src.tar.xz
cd llvm-15.0.7.src
tar -xf ../llvm-cmake-15.0.7.src.tar.xz 
cp cmake-15.0.7.src/Modules/* cmake/modules/
###sed '/LLVM_COMMON_UTILS/s@../cmake@cmake-15.0.7.src@' -i CMakeLists.txt

tar -xf ../clang-15.0.7.src.tar.xz

mkdir build && cd build
CC=gcc CXX=g++ cmake -DCMAKE_INSTALL_PREFIX=/usr -DLLVM_ENABLE_FFI=ON -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=ON -DLLVM_ENABLE_RTTI=ON -DLLVM_TARGETS_TO_BUILD="host;AMDGPU;BPF" -DLLVM_BINUTILS_INCDIR=/usr/include -DLLVM_INCLUDE_BENCHMARKS=OFF -DCLANG_DEFAULT_PIE_ON_LINUX=ON -Wno-dev ..

## -DLLVM_BUILD_LLVM_DYLIB=ON -DLLVM_LINK_LLVM_DYLIB=ON
