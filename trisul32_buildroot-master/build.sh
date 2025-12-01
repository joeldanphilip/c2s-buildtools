#!/bin/sh
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
VMLINUX=/buildroot/output/build/linux-5.4.1/vmlinux
BBL_BUILD=./riscv-pk/build
ROOT_DIR=$(pwd)
TOOLCHAIN=$(pwd)/buildroot/output/host/bin

cd buildroot
make clean
#make -j8 allnoconfig
make -j8 menuconfig
make -j8 linux-menuconfig
#make clean
make -j8

cd $ROOT_DIR
rm -rf $BBL_BUILD
mkdir $BBL_BUILD
cd $BBL_BUILD

export PATH=$PATH:$TOOLCHAIN

cp $ROOT_DIR$VMLINUX ./
../configure --host=riscv32-buildroot-linux-gnu --with-payload=./vmlinux  --with-arch=rv32ima --with-abi=ilp32  
make
$TOOLCHAIN/riscv32-buildroot-linux-gnu-objcopy --gap-fill 0 -I elf32-littleriscv -O binary --set-section-flags .bss=alloc,load,contents bbl bbl.bin

cp bbl bbl.bin ../../
