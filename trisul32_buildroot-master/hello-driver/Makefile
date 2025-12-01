# Makefile for building hello.ko out-of-tree module

# Adjust KDIR to point to your kernel build directory
KDIR ?= /home/premjith/Desktop/gc2025/TRISUL32_BUILDROOT/buildroot/output/build/linux-5.4.1
PWD  := $(shell pwd)

# Default target
obj-m += hello.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=riscv CROSS_COMPILE=/home/premjith/Desktop/gc2025/TRISUL32_BUILDROOT/buildroot/output/host/bin/riscv32-buildroot-linux-gnu- modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
