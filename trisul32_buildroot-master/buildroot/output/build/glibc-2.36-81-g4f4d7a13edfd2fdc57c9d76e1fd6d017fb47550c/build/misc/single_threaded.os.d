$(common-objpfx)misc/single_threaded.os: \
 single_threaded.c \
 $(common-objpfx)libc-modules.h \
 ../include/libc-symbols.h \
 $(common-objpfx)config.h \
 ../sysdeps/generic/libc-symver.h ../sysdeps/generic/symbol-hacks.h \
 ../include/sys/single_threaded.h ../misc/sys/single_threaded.h \
 ../include/features.h ../include/features-time64.h \
 ../sysdeps/unix/sysv/linux/features-time64.h \
 ../sysdeps/riscv/bits/wordsize.h ../bits/timesize.h \
 ../include/stdc-predef.h ../include/sys/cdefs.h ../misc/sys/cdefs.h \
 ../sysdeps/ieee754/ldbl-128/bits/long-double.h ../include/gnu/stubs.h
$(common-objpfx)libc-modules.h:
../include/libc-symbols.h:
$(common-objpfx)config.h:
../sysdeps/generic/libc-symver.h:
../sysdeps/generic/symbol-hacks.h:
../include/sys/single_threaded.h:
../misc/sys/single_threaded.h:
../include/features.h:
../include/features-time64.h:
../sysdeps/unix/sysv/linux/features-time64.h:
../sysdeps/riscv/bits/wordsize.h:
../bits/timesize.h:
../include/stdc-predef.h:
../include/sys/cdefs.h:
../misc/sys/cdefs.h:
../sysdeps/ieee754/ldbl-128/bits/long-double.h:
../include/gnu/stubs.h:
