$(common-objpfx)nptl/libpthread-compat.os: \
 libpthread-compat.c \
 $(common-objpfx)libc-modules.h \
 ../include/libc-symbols.h \
 $(common-objpfx)config.h \
 ../sysdeps/generic/libc-symver.h ../sysdeps/generic/symbol-hacks.h \
 ../include/sys/cdefs.h ../misc/sys/cdefs.h ../include/features.h \
 ../include/features-time64.h \
 ../sysdeps/unix/sysv/linux/features-time64.h \
 ../sysdeps/riscv/bits/wordsize.h ../bits/timesize.h \
 ../include/stdc-predef.h ../include/gnu/stubs.h \
 ../sysdeps/ieee754/ldbl-128/bits/long-double.h ../include/shlib-compat.h \
 $(common-objpfx)abi-versions.h
$(common-objpfx)libc-modules.h:
../include/libc-symbols.h:
$(common-objpfx)config.h:
../sysdeps/generic/libc-symver.h:
../sysdeps/generic/symbol-hacks.h:
../include/sys/cdefs.h:
../misc/sys/cdefs.h:
../include/features.h:
../include/features-time64.h:
../sysdeps/unix/sysv/linux/features-time64.h:
../sysdeps/riscv/bits/wordsize.h:
../bits/timesize.h:
../include/stdc-predef.h:
../include/gnu/stubs.h:
../sysdeps/ieee754/ldbl-128/bits/long-double.h:
../include/shlib-compat.h:
$(common-objpfx)abi-versions.h:
