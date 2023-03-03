#! /bin/sh

export SOURCE_BASE=$(pwd)

rm -rf ./astFile
mkdir ./astFile

cp ./linux_x86.mk ./astFile
cd ./astFile
make -f linux_x86.mk

rm ./linux_x86.mk
cd ..

find $(pwd) -name "*.ast" > astList.txt
