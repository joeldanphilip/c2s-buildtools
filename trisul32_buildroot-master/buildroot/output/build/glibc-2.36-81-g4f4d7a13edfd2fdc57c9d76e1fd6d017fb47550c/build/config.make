# config.make.  Generated from config.make.in by configure.
# Don't edit this file.  Put configuration parameters in configparms instead.

version = 2.36
release = stable

# Installation prefixes.
install_root = $(DESTDIR)
prefix = /usr
exec_prefix = ${prefix}
datadir = ${datarootdir}
libdir = ${exec_prefix}/lib
bindir = ${exec_prefix}/bin
slibdir = /lib32
rtlddir = /lib
complocaledir = 
sysconfdir = /etc
libexecdir = ${exec_prefix}/libexec
rootsbindir = /sbin
infodir = ${datarootdir}/info
includedir = ${prefix}/include
datarootdir = ${prefix}/share
localstatedir = /var
localedir = ${datarootdir}/locale
multidir= .

# Should we use and build ldconfig?
use-ldconfig = yes

# Maybe the `ldd' script must be rewritten.
ldd-rewrite-script = sysdeps/unix/sysv/linux/riscv/ldd-rewrite.sed

# System configuration.
config-machine = riscv32
base-machine = riscv
config-vendor = buildroot
config-os = linux-gnu
config-sysdirs =  sysdeps/unix/sysv/linux/riscv/rv32/ sysdeps/unix/sysv/linux/riscv sysdeps/riscv/nptl sysdeps/unix/sysv/linux/generic/wordsize-32 sysdeps/unix/sysv/linux/generic sysdeps/unix/sysv/linux/riscv/rv32 sysdeps/unix/sysv/linux sysdeps/nptl sysdeps/pthread sysdeps/gnu sysdeps/unix/inet sysdeps/unix/sysv sysdeps/unix sysdeps/posix sysdeps/riscv/rv32/ sysdeps/riscv/rv32 sysdeps/riscv/nofpu sysdeps/ieee754/soft-fp sysdeps/riscv sysdeps/ieee754/ldbl-128 sysdeps/ieee754/dbl-64 sysdeps/ieee754/flt-32 sysdeps/wordsize-32 sysdeps/ieee754 sysdeps/generic
cflags-cpu = 
asflags-cpu = 

config-extra-cflags = 
config-extra-cppflags = 
config-cflags-nofma = -ffp-contract=off

defines = 
sysheaders = /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include
sysincludes = -nostdinc -isystem /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include -isystem /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include-fixed -isystem /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include
c++-sysincludes = 
c++-cstdlib-header = 
c++-cmath-header = 
c++-bits-std_abs-h = 
all-warnings = 
enable-werror = no

have-z-execstack = yes
have-protected-data = yes
have-insert = yes
have-glob-dat-reloc = no
with-fp = no
enable-timezone-tools = yes
unwind-find-fde = no
have-fpie = yes
have-ssp = no
stack-protector = -fno-stack-protector
no-stack-protector = 
have-selinux = no
have-libaudit = 
have-libcap = 
have-cc-with-libunwind = no
bind-now = no
use-default-link = no
have-cxx-thread_local = no
have-loop-to-function = yes
have-textrel_ifunc = yes

multi-arch = no

mach-interface-list = 

experimental-malloc = yes

memory-tagging = no

nss-crypt = no
static-nss-crypt = no

# Configuration options.
build-shared = yes
build-profile = no
build-static-nss = no
cross-compiling = yes
force-install = yes
build-crypt = yes
build-nscd = yes
use-nscd = yes
build-hardcoded-path-in-tests= no
build-pt-chown = no
have-tunables = yes
pthread-in-libc = yes

# Build tools.
CC = /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/bin/riscv32-buildroot-linux-gnu-gcc
CXX = 
BUILD_CC = gcc
CFLAGS = -Os -fno-lto
CPPFLAGS-config = 
CPPUNDEFS = 
extra-nonshared-cflags = 
rtld-early-cflags = 
ASFLAGS-config =  -Wa,--noexecstack
AR = /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/../../../../riscv32-buildroot-linux-gnu/bin/ar
NM = /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/bin/riscv32-buildroot-linux-gnu-gcc-nm
MAKEINFO = makeinfo
AS = $(CC) -c
BISON = bison
AUTOCONF = no
OBJDUMP = /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/../../../../riscv32-buildroot-linux-gnu/bin/objdump
OBJCOPY = /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/../../../../riscv32-buildroot-linux-gnu/bin/objcopy
GPROF = gprof
READELF = /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/bin/riscv32-buildroot-linux-gnu-readelf

# Installation tools.
INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_INFO = /usr/bin/install-info
LN_S = ln -s
MSGFMT = msgfmt

# Script execution tools.
BASH = /bin/sh
AWK = gawk
PERL = /usr/bin/perl
PYTHON = python3 -B

# Additional libraries.
LIBGD = no

# Package versions and bug reporting configuration.
PKGVERSION = (Buildroot) 
PKGVERSION_TEXI = (Buildroot) 
REPORT_BUGS_TO = <https://www.gnu.org/software/libc/bugs.html>
REPORT_BUGS_TEXI = @uref{https://www.gnu.org/software/libc/bugs.html}

# More variables may be inserted below by configure.

have-gnu-retain = yes
with-lld = no
have-z-start-stop-gc = yes
have-depaudit = yes
have-dt-relr = no
have-no-dynamic-linker = yes
have-static-pie = yes
have-mtls-dialect-gnu2 = no
default-abi = ilp32
riscv-r-align = yes
build-mathvec = no
have-ifunc = yes
have-gcc-ifunc = yes
build-pic-default = yes
cc-pie-default = yes
build-pie-default = yes
enable-static-pie = no
