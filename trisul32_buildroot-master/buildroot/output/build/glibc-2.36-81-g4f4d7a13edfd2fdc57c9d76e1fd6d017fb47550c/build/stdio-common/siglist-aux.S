	.file	"siglist-gen.c"
	.option pic
	.text
	.globl	__sys_sigabbrev
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
.LC0:
	.string	"HUP"
	.align	2
.LC1:
	.string	"INT"
	.align	2
.LC2:
	.string	"QUIT"
	.align	2
.LC3:
	.string	"ILL"
	.align	2
.LC4:
	.string	"TRAP"
	.align	2
.LC5:
	.string	"ABRT"
	.align	2
.LC6:
	.string	"BUS"
	.align	2
.LC7:
	.string	"FPE"
	.align	2
.LC8:
	.string	"KILL"
	.align	2
.LC9:
	.string	"USR1"
	.align	2
.LC10:
	.string	"SEGV"
	.align	2
.LC11:
	.string	"USR2"
	.align	2
.LC12:
	.string	"PIPE"
	.align	2
.LC13:
	.string	"ALRM"
	.align	2
.LC14:
	.string	"TERM"
	.align	2
.LC15:
	.string	"STKFLT"
	.align	2
.LC16:
	.string	"CHLD"
	.align	2
.LC17:
	.string	"CONT"
	.align	2
.LC18:
	.string	"STOP"
	.align	2
.LC19:
	.string	"TSTP"
	.align	2
.LC20:
	.string	"TTIN"
	.align	2
.LC21:
	.string	"TTOU"
	.align	2
.LC22:
	.string	"URG"
	.align	2
.LC23:
	.string	"XCPU"
	.align	2
.LC24:
	.string	"XFSZ"
	.align	2
.LC25:
	.string	"VTALRM"
	.align	2
.LC26:
	.string	"PROF"
	.align	2
.LC27:
	.string	"WINCH"
	.align	2
.LC28:
	.string	"POLL"
	.align	2
.LC29:
	.string	"PWR"
	.align	2
.LC30:
	.string	"SYS"
	.globl	__sys_siglist
	.align	2
.LC31:
	.string	"Hangup"
	.align	2
.LC32:
	.string	"Interrupt"
	.align	2
.LC33:
	.string	"Quit"
	.align	2
.LC34:
	.string	"Illegal instruction"
	.align	2
.LC35:
	.string	"Trace/breakpoint trap"
	.align	2
.LC36:
	.string	"Aborted"
	.align	2
.LC37:
	.string	"Bus error"
	.align	2
.LC38:
	.string	"Floating point exception"
	.align	2
.LC39:
	.string	"Killed"
	.align	2
.LC40:
	.string	"User defined signal 1"
	.align	2
.LC41:
	.string	"Segmentation fault"
	.align	2
.LC42:
	.string	"User defined signal 2"
	.align	2
.LC43:
	.string	"Broken pipe"
	.align	2
.LC44:
	.string	"Alarm clock"
	.align	2
.LC45:
	.string	"Terminated"
	.align	2
.LC46:
	.string	"Stack fault"
	.align	2
.LC47:
	.string	"Child exited"
	.align	2
.LC48:
	.string	"Continued"
	.align	2
.LC49:
	.string	"Stopped (signal)"
	.align	2
.LC50:
	.string	"Stopped"
	.align	2
.LC51:
	.string	"Stopped (tty input)"
	.align	2
.LC52:
	.string	"Stopped (tty output)"
	.align	2
.LC53:
	.string	"Urgent I/O condition"
	.align	2
.LC54:
	.string	"CPU time limit exceeded"
	.align	2
.LC55:
	.string	"File size limit exceeded"
	.align	2
.LC56:
	.string	"Virtual timer expired"
	.align	2
.LC57:
	.string	"Profiling timer expired"
	.align	2
.LC58:
	.string	"Window changed"
	.align	2
.LC59:
	.string	"I/O possible"
	.align	2
.LC60:
	.string	"Power failure"
	.align	2
.LC61:
	.string	"Bad system call"
	.section	.data.rel.ro.local,"aw"
	.align	2
	.type	__sys_sigabbrev, @object
	.size	__sys_sigabbrev, 260
__sys_sigabbrev:
	.zero	4
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	.LC7
	.word	.LC8
	.word	.LC9
	.word	.LC10
	.word	.LC11
	.word	.LC12
	.word	.LC13
	.word	.LC14
	.word	.LC15
	.word	.LC16
	.word	.LC17
	.word	.LC18
	.word	.LC19
	.word	.LC20
	.word	.LC21
	.word	.LC22
	.word	.LC23
	.word	.LC24
	.word	.LC25
	.word	.LC26
	.word	.LC27
	.word	.LC28
	.word	.LC29
	.word	.LC30
	.zero	132
	.type	__sys_siglist, @object
	.size	__sys_siglist, 260
__sys_siglist:
	.zero	4
	.word	.LC31
	.word	.LC32
	.word	.LC33
	.word	.LC34
	.word	.LC35
	.word	.LC36
	.word	.LC37
	.word	.LC38
	.word	.LC39
	.word	.LC40
	.word	.LC41
	.word	.LC42
	.word	.LC43
	.word	.LC44
	.word	.LC45
	.word	.LC46
	.word	.LC47
	.word	.LC48
	.word	.LC49
	.word	.LC50
	.word	.LC51
	.word	.LC52
	.word	.LC53
	.word	.LC54
	.word	.LC55
	.word	.LC56
	.word	.LC57
	.word	.LC58
	.word	.LC59
	.word	.LC60
	.word	.LC61
	.zero	132
	.ident	"GCC: (Buildroot 2023.02.5) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
