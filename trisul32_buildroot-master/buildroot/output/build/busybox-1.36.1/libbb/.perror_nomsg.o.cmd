cmd_libbb/perror_nomsg.o := /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/bin/riscv32-buildroot-linux-gnu-gcc -Wp,-MD,libbb/.perror_nomsg.o.d  -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.36.1"' -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -Os -g0 -D_FORTIFY_SOURCE=1 -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os -DHAVE_GETRANDOM    -DKBUILD_BASENAME='"perror_nomsg"'  -DKBUILD_MODNAME='"perror_nomsg"' -c -o libbb/perror_nomsg.o libbb/perror_nomsg.c

deps_libbb/perror_nomsg.o := \
  libbb/perror_nomsg.c \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/stdc-predef.h \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include-fixed/limits.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include-fixed/syslimits.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/limits.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/libc-header-start.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/features.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/features-time64.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/wordsize.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/timesize.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/cdefs.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/long-double.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/gnu/stubs.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/gnu/stubs-ilp32.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/posix1_lim.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/local_lim.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/limits.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/pthread_stack_min-dynamic.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/posix2_lim.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/xopen_lim.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/uio_lim.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/byteswap.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/byteswap.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/typesizes.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/time64.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/endian.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/endian.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/endianness.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/uintn-identity.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include/stdint.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/stdint.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/wchar.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stdint-intn.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stdint-uintn.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include/stdbool.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/unistd.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/posix_opt.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/environments.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include/stddef.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/confname.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/getopt_posix.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/getopt_core.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/unistd.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/unistd_ext.h \

libbb/perror_nomsg.o: $(deps_libbb/perror_nomsg.o)

$(deps_libbb/perror_nomsg.o):
