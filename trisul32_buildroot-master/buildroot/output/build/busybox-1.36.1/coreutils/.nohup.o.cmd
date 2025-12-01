cmd_coreutils/nohup.o := /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/bin/riscv32-buildroot-linux-gnu-gcc -Wp,-MD,coreutils/.nohup.o.d  -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.36.1"' -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -Os -g0 -D_FORTIFY_SOURCE=1 -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os -DHAVE_GETRANDOM    -DKBUILD_BASENAME='"nohup"'  -DKBUILD_MODNAME='"nohup"' -c -o coreutils/nohup.o coreutils/nohup.c

deps_coreutils/nohup.o := \
  coreutils/nohup.c \
    $(wildcard include/config/nohup.h) \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/stdc-predef.h \
  include/libbb.h \
    $(wildcard include/config/feature/shadowpasswds.h) \
    $(wildcard include/config/use/bb/shadow.h) \
    $(wildcard include/config/selinux.h) \
    $(wildcard include/config/feature/utmp.h) \
    $(wildcard include/config/locale/support.h) \
    $(wildcard include/config/use/bb/pwd/grp.h) \
    $(wildcard include/config/lfs.h) \
    $(wildcard include/config/feature/buffers/go/on/stack.h) \
    $(wildcard include/config/feature/buffers/go/in/bss.h) \
    $(wildcard include/config/extra/cflags.h) \
    $(wildcard include/config/variable/arch/pagesize.h) \
    $(wildcard include/config/feature/verbose.h) \
    $(wildcard include/config/feature/etc/services.h) \
    $(wildcard include/config/feature/ipv6.h) \
    $(wildcard include/config/feature/seamless/xz.h) \
    $(wildcard include/config/feature/seamless/lzma.h) \
    $(wildcard include/config/feature/seamless/bz2.h) \
    $(wildcard include/config/feature/seamless/gz.h) \
    $(wildcard include/config/feature/seamless/z.h) \
    $(wildcard include/config/float/duration.h) \
    $(wildcard include/config/feature/check/names.h) \
    $(wildcard include/config/feature/prefer/applets.h) \
    $(wildcard include/config/long/opts.h) \
    $(wildcard include/config/feature/pidfile.h) \
    $(wildcard include/config/feature/syslog.h) \
    $(wildcard include/config/feature/syslog/info.h) \
    $(wildcard include/config/warn/simple/msg.h) \
    $(wildcard include/config/feature/individual.h) \
    $(wildcard include/config/shell/ash.h) \
    $(wildcard include/config/shell/hush.h) \
    $(wildcard include/config/echo.h) \
    $(wildcard include/config/sleep.h) \
    $(wildcard include/config/printf.h) \
    $(wildcard include/config/test.h) \
    $(wildcard include/config/test1.h) \
    $(wildcard include/config/test2.h) \
    $(wildcard include/config/kill.h) \
    $(wildcard include/config/killall.h) \
    $(wildcard include/config/killall5.h) \
    $(wildcard include/config/chown.h) \
    $(wildcard include/config/ls.h) \
    $(wildcard include/config/xxx.h) \
    $(wildcard include/config/route.h) \
    $(wildcard include/config/feature/hwib.h) \
    $(wildcard include/config/desktop.h) \
    $(wildcard include/config/feature/crond/d.h) \
    $(wildcard include/config/feature/setpriv/capabilities.h) \
    $(wildcard include/config/run/init.h) \
    $(wildcard include/config/feature/securetty.h) \
    $(wildcard include/config/pam.h) \
    $(wildcard include/config/use/bb/crypt.h) \
    $(wildcard include/config/feature/adduser/to/group.h) \
    $(wildcard include/config/feature/del/user/from/group.h) \
    $(wildcard include/config/ioctl/hex2str/error.h) \
    $(wildcard include/config/feature/editing.h) \
    $(wildcard include/config/feature/editing/history.h) \
    $(wildcard include/config/feature/tab/completion.h) \
    $(wildcard include/config/feature/username/completion.h) \
    $(wildcard include/config/feature/editing/fancy/prompt.h) \
    $(wildcard include/config/feature/editing/savehistory.h) \
    $(wildcard include/config/feature/editing/vi.h) \
    $(wildcard include/config/feature/editing/save/on/exit.h) \
    $(wildcard include/config/pmap.h) \
    $(wildcard include/config/feature/show/threads.h) \
    $(wildcard include/config/feature/ps/additional/columns.h) \
    $(wildcard include/config/feature/topmem.h) \
    $(wildcard include/config/feature/top/smp/process.h) \
    $(wildcard include/config/pgrep.h) \
    $(wildcard include/config/pkill.h) \
    $(wildcard include/config/pidof.h) \
    $(wildcard include/config/sestatus.h) \
    $(wildcard include/config/unicode/support.h) \
    $(wildcard include/config/feature/mtab/support.h) \
    $(wildcard include/config/feature/clean/up.h) \
    $(wildcard include/config/feature/devfs.h) \
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
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/ctype.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/locale_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/__locale_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/dirent.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/dirent.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/dirent_ext.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/errno.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/errno.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/errno.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/errno.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/errno.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/errno-base.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/error_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/fcntl.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/fcntl.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/fcntl-linux.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_iovec.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/falloc.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_timespec.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/time_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stat.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/struct_stat.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/fcntl2.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/inttypes.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/netdb.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/netinet/in.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/socket.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/socket.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/clock_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/clockid_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/timer_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/select.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/select.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/sigset_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/__sigset_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_timeval.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/select2.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/pthreadtypes.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/thread-shared-types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/pthreadtypes-arch.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/atomic_wide_counter.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/struct_mutex.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/struct_rwlock.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/socket_type.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sockaddr.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/socket.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/socket.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/posix_types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/stddef.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/posix_types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/posix_types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/bitsperlong.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/sockios.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/sockios.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_osockaddr.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/socket2.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/in.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/rpc/netdb.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/sigevent_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/__sigval_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/netdb.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/setjmp.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/setjmp.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct___jmp_buf_tag.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/setjmp2.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/signal.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/signum-generic.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/signum-arch.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/sig_atomic_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/siginfo_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/siginfo-arch.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/siginfo-consts.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/siginfo-consts-arch.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/sigval_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sigevent-consts.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sigaction.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sigcontext.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/stack_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/ucontext.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sigstack.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sigstksz.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/ss_flags.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_sigstack.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sigthread.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/signal_ext.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/paths.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/stdio.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/lib/gcc/riscv32-buildroot-linux-gnu/11.4.0/include/stdarg.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/__fpos_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/__mbstate_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/__fpos64_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/__FILE.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/FILE.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_FILE.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/cookie_io_functions_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stdio_lim.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/floatn.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/floatn-common.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stdio2-decl.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stdio2.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/stdlib.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/waitflags.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/waitstatus.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/alloca.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stdlib-float.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/stdlib.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/string.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/strings.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/strings_fortified.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/string_fortified.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/libgen.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/poll.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/poll.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/poll.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/poll2.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/ioctl.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/ioctls.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/ioctls.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/ioctls.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/ioctl.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/ioctl.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/ioctl.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/ioctl-types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/ttydefaults.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/mman.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/mman.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/mman-map-flags-generic.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/mman-linux.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/mman-shared.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/mman_ext.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/resource.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/resource.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_rusage.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/stat.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/statx.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/stat.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/types.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/int-ll64.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/statx-generic.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_statx_timestamp.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_statx.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/time.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/sysmacros.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/sysmacros.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/wait.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/idtype_t.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/termios.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-struct.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-c_cc.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-c_iflag.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-c_oflag.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-baud.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-c_cflag.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-c_lflag.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-tcflow.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/termios-misc.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/time.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/time.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/timex.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_tm.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/types/struct_itimerspec.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/param.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/param.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/linux/param.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm/param.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/asm-generic/param.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/pwd.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/grp.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/shadow.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/mntent.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/sys/statfs.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/statfs.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/utmp.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/utmp.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/utmpx.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/bits/utmpx.h \
  /home/joelphilip/Documents/C2S/Trisul32/trisul32_buildroot-master/buildroot/output/host/riscv32-buildroot-linux-gnu/sysroot/usr/include/arpa/inet.h \
  include/xatonum.h \

coreutils/nohup.o: $(deps_coreutils/nohup.o)

$(deps_coreutils/nohup.o):
