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
cmake -DLLVM_BUILD=/home/shared/llvm-project-12.0.1.src/build -DZ3_DIR=z3.obj -DCMAKE_BUILD_TYPE=$build_type ..
make -j16