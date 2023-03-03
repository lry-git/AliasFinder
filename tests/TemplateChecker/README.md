# TemplateChecker

## Prerequisites

- LLVM & Clang = 12.0.0
- CMake >= 3.10

## How to compile LLVM & Clang

Download llvm and clang from [here](https://releases.llvm.org/download.html#12.0.0).

Download the files and run the following commands:

```shell
$ tar xf llvm-project-12.0.0.src.tar.xz
$ cd llvm-project-12.0.0
$ mv clang llvm/tools/clang
$ cd llvm
$ mkdir build && cd build
$ cmake -D CMAKE_BUILD_TYPE=Release .. 
$ make
```

### An alternative way (not test)

Downlaod llvm-project from [here](https://releases.llvm.org/download.html#12.0.0)

Then follow instructions at [here](https://llvm.org/docs/CMake.html#frequently-used-llvm-related-variables) and check `LLVM_ENABLE_PROJECTS` in [`llvm-specific-variables`](https://llvm.org/docs/CMake.html#llvm-specific-variables). For example:

```shell
$ tar xf llvm-project-xxx.tar.xz
$ cd llvm-project-xxx
$ mkdir build; cd build;
$ cmake -S llvm -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" ../llvm
$ make -j4
```

## How to use z3 lib

1. Download z3 from [here](https://github.com/Z3Prover/z3.git).

2. Compile Z3

```shell
$ python scripts/mk_make.py
$ cd build
$ make -j4
```

## How to compile

There are two approaches to compile TemplateChecker:

1. If you built LLVM and installed it, you should specify variable LLVM_PREFIX which represents the path to your LLVM install directory;
2. If you built LLVM but did not install it, you should specify variable LLVM_BUILD which represents the path to your LLVM build directory.

We recommend the first approach.

```shell
$ git clone https://github.com/ITWOI/ESAF.git
$ cd ESAF
$ mkdir cmake-build-debug
$ cd cmake-build-debug
# use absolute path (i.e., starts with "/")
# use LLVM install directory (change Release to Debug when you plan to debug the program.)
$ cmake -DLLVM_PREFIX=${LLVM_PREFIX} -D Z3_DIR=/path/to/z3/ -D CMAKE_BUILD_TYPE=Release ..
# use LLVM build directory
$ cmake -DLLVM_BUILD=${LLVM_BUILD} -D Z3_DIR=/path/to/z3/ -D CMAKE_BUILD_TYPE=Release ..
$ make -j4
```

## How to run

```shell
$ cd ${project.root}/tests/TemplateChecker
$ clang++ -emit-ast -c example.cpp
$ ../../cmake-build-debug/tools/TemplateChecker/TemplateChecker astList.txt config.txt
```
