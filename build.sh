UbuntuLLVM="https://github.com/llvm/llvm-project/releases/download/llvmorg-12.0.0/clang+llvm-12.0.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz"
LLVMHome="llvm-12.0.0.obj"
HOME=$(pwd)
########
# Download LLVM if need be.
#######
if [ ! -d "$LLVM_BUILD" ]
then
    if [ ! -d "$LLVMHome" ]
    then
        # echo "Downloading LLVM binary for $OSDisplayName"
        # generic_download_file "$urlLLVM" llvm.tar.xz
        proxychains wget -c "$UbuntuLLVM" -O "llvm.tar.xz"
        mkdir -p "./$LLVMHome" && tar -xf llvm.tar.xz -C "./$LLVMHome" --strip-components 1
        rm llvm.tar.xz
    fi

    export LLVM_BUILD="$HOME/$LLVMHome"
fi

if [ "$1" == "debug" ]; then
    build_dir="Debug-build"
    build_type="Debug"
else
    build_dir="Release-build"
    build_type="Release"
fi
mkdir -p $build_dir
cd $build_dir
# cmake -DLLVM_PREFIX=${LLVM_PREFIX} -D Z3_DIR=/path/to/z3/ -D CMAKE_BUILD_TYPE=Release ..
# use LLVM build directory
cmake -DLLVM_BUILD=$LLVM_BUILD -DZ3_DIR=z3.obj -DCMAKE_BUILD_TYPE=$build_type ..
make -j16