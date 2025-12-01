	.file	"cxx11-ios_failure.cc"
	.option pic
	.text
	.section	.rodata._ZNK12_GLOBAL__N_117io_error_category4nameEv.str1.4,"aMS",@progbits,1
	.align	2
.LC0:
	.string	"iostream"
	.section	.text._ZNK12_GLOBAL__N_117io_error_category4nameEv,"ax",@progbits
	.align	2
	.type	_ZNK12_GLOBAL__N_117io_error_category4nameEv, @function
_ZNK12_GLOBAL__N_117io_error_category4nameEv:
.LFB1482:
	.cfi_startproc
	lla	a0,.LC0
	ret
	.cfi_endproc
.LFE1482:
	.size	_ZNK12_GLOBAL__N_117io_error_category4nameEv, .-_ZNK12_GLOBAL__N_117io_error_category4nameEv
	.section	.text._ZN12_GLOBAL__N_113constant_initD2Ev,"ax",@progbits
	.align	2
	.type	_ZN12_GLOBAL__N_113constant_initD2Ev, @function
_ZN12_GLOBAL__N_113constant_initD2Ev:
.LFB1495:
	.cfi_startproc
	ret
	.cfi_endproc
.LFE1495:
	.size	_ZN12_GLOBAL__N_113constant_initD2Ev, .-_ZN12_GLOBAL__N_113constant_initD2Ev
	.set	_ZN12_GLOBAL__N_113constant_initD1Ev,_ZN12_GLOBAL__N_113constant_initD2Ev
	.section	.rodata._ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei.str1.4,"aMS",@progbits,1
	.align	2
.LC1:
	.string	"iostream error"
	.align	2
.LC2:
	.string	"Unknown error"
	.section	.text._ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei,"ax",@progbits
	.align	2
	.type	_ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei, @function
_ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei:
.LFB1483:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1483
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	sw	s0,8(sp)
	sw	ra,12(sp)
	sw	s1,4(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	.cfi_offset 9, -12
	addi	a5,a0,8
	sw	a5,0(a0)
	sw	zero,4(a0)
	sb	zero,8(a0)
	li	a5,1
	mv	s0,a0
	lla	a1,.LC1
	beq	a2,a5,.L10
	lla	a1,.LC2
.L10:
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEPKc@plt
.LEHE0:
	j	.L11
.L7:
	mv	s1,a0
	mv	a0,s0
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	mv	a0,s1
.LEHB1:
	call	_Unwind_Resume@plt
.LEHE1:
.L11:
	lw	ra,12(sp)
	.cfi_restore 1
	mv	a0,s0
	lw	s0,8(sp)
	.cfi_restore 8
	lw	s1,4(sp)
	.cfi_restore 9
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1483:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei,"a",@progbits
.LLSDA1483:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x1a
	.4byte	.LEHB0-.LFB1483
	.4byte	.LEHE0-.LEHB0
	.4byte	.L7-.LFB1483
	.byte	0
	.4byte	.LEHB1-.LFB1483
	.4byte	.LEHE1-.LEHB1
	.4byte	0
	.byte	0
	.section	.text._ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei
	.size	_ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei, .-_ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei
	.section	.text._ZN12_GLOBAL__N_117io_error_categoryD2Ev,"ax",@progbits
	.align	2
	.type	_ZN12_GLOBAL__N_117io_error_categoryD2Ev, @function
_ZN12_GLOBAL__N_117io_error_categoryD2Ev:
.LFB1876:
	.cfi_startproc
	lla	a5,.LANCHOR0+8
	sw	a5,0(a0)
	tail	_ZNSt3_V214error_categoryD2Ev@plt
	.cfi_endproc
.LFE1876:
	.size	_ZN12_GLOBAL__N_117io_error_categoryD2Ev, .-_ZN12_GLOBAL__N_117io_error_categoryD2Ev
	.set	_ZN12_GLOBAL__N_117io_error_categoryD1Ev,_ZN12_GLOBAL__N_117io_error_categoryD2Ev
	.section	.text._ZN12_GLOBAL__N_117io_error_categoryD0Ev,"ax",@progbits
	.align	2
	.type	_ZN12_GLOBAL__N_117io_error_categoryD0Ev, @function
_ZN12_GLOBAL__N_117io_error_categoryD0Ev:
.LFB1878:
	.cfi_startproc
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	sw	s0,8(sp)
	sw	ra,12(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	mv	s0,a0
	call	_ZN12_GLOBAL__N_117io_error_categoryD1Ev
	mv	a0,s0
	lw	s0,8(sp)
	.cfi_restore 8
	lw	ra,12(sp)
	.cfi_restore 1
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	tail	_ZdlPv@plt
	.cfi_endproc
.LFE1878:
	.size	_ZN12_GLOBAL__N_117io_error_categoryD0Ev, .-_ZN12_GLOBAL__N_117io_error_categoryD0Ev
	.section	.text._ZNSt8ios_base7failureB5cxx11D2Ev,"ax",@progbits
	.align	2
	.globl	_ZNSt8ios_base7failureB5cxx11D2Ev
	.type	_ZNSt8ios_base7failureB5cxx11D2Ev, @function
_ZNSt8ios_base7failureB5cxx11D2Ev:
.LFB1508:
	.cfi_startproc
	la	a5,_ZTVNSt8ios_base7failureB5cxx11E
	addi	a5,a5,8
	sw	a5,0(a0)
	tail	_ZNSt12system_errorD2Ev@plt
	.cfi_endproc
.LFE1508:
	.size	_ZNSt8ios_base7failureB5cxx11D2Ev, .-_ZNSt8ios_base7failureB5cxx11D2Ev
	.globl	_ZNSt8ios_base7failureB5cxx11D1Ev
	.set	_ZNSt8ios_base7failureB5cxx11D1Ev,_ZNSt8ios_base7failureB5cxx11D2Ev
	.section	.text._ZNSt8ios_base7failureB5cxx11D0Ev,"ax",@progbits
	.align	2
	.globl	_ZNSt8ios_base7failureB5cxx11D0Ev
	.type	_ZNSt8ios_base7failureB5cxx11D0Ev, @function
_ZNSt8ios_base7failureB5cxx11D0Ev:
.LFB1510:
	.cfi_startproc
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	sw	s0,8(sp)
	sw	ra,12(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	mv	s0,a0
	call	_ZNSt8ios_base7failureB5cxx11D1Ev@plt
	mv	a0,s0
	lw	s0,8(sp)
	.cfi_restore 8
	lw	ra,12(sp)
	.cfi_restore 1
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	tail	_ZdlPv@plt
	.cfi_endproc
.LFE1510:
	.size	_ZNSt8ios_base7failureB5cxx11D0Ev, .-_ZNSt8ios_base7failureB5cxx11D0Ev
	.section	.text._ZNKSt8ios_base7failureB5cxx114whatEv,"ax",@progbits
	.align	2
	.globl	_ZNKSt8ios_base7failureB5cxx114whatEv
	.type	_ZNKSt8ios_base7failureB5cxx114whatEv, @function
_ZNKSt8ios_base7failureB5cxx114whatEv:
.LFB1511:
	.cfi_startproc
	tail	_ZNKSt13runtime_error4whatEv@plt
	.cfi_endproc
.LFE1511:
	.size	_ZNKSt8ios_base7failureB5cxx114whatEv, .-_ZNKSt8ios_base7failureB5cxx114whatEv
	.section	.text._ZNSt19__iosfail_type_infoD2Ev,"ax",@progbits
	.align	2
	.globl	_ZNSt19__iosfail_type_infoD2Ev
	.type	_ZNSt19__iosfail_type_infoD2Ev, @function
_ZNSt19__iosfail_type_infoD2Ev:
.LFB1523:
	.cfi_startproc
	la	a5,_ZTVSt19__iosfail_type_info
	addi	a5,a5,8
	sw	a5,0(a0)
	tail	_ZN10__cxxabiv120__si_class_type_infoD2Ev@plt
	.cfi_endproc
.LFE1523:
	.size	_ZNSt19__iosfail_type_infoD2Ev, .-_ZNSt19__iosfail_type_infoD2Ev
	.globl	_ZNSt19__iosfail_type_infoD1Ev
	.set	_ZNSt19__iosfail_type_infoD1Ev,_ZNSt19__iosfail_type_infoD2Ev
	.section	.text._ZNSt19__iosfail_type_infoD0Ev,"ax",@progbits
	.align	2
	.globl	_ZNSt19__iosfail_type_infoD0Ev
	.type	_ZNSt19__iosfail_type_infoD0Ev, @function
_ZNSt19__iosfail_type_infoD0Ev:
.LFB1525:
	.cfi_startproc
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	sw	s0,8(sp)
	sw	ra,12(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	mv	s0,a0
	call	_ZNSt19__iosfail_type_infoD1Ev@plt
	mv	a0,s0
	lw	s0,8(sp)
	.cfi_restore 8
	lw	ra,12(sp)
	.cfi_restore 1
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	tail	_ZdlPv@plt
	.cfi_endproc
.LFE1525:
	.size	_ZNSt19__iosfail_type_infoD0Ev, .-_ZNSt19__iosfail_type_infoD0Ev
	.section	.text._ZNKSt19__iosfail_type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv,"ax",@progbits
	.align	2
	.globl	_ZNKSt19__iosfail_type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv
	.type	_ZNKSt19__iosfail_type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv, @function
_ZNKSt19__iosfail_type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv:
.LFB1526:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	s0,24(sp)
	.cfi_offset 8, -8
	mv	s0,a0
	mv	a0,a1
	sw	a2,12(sp)
	sw	a1,8(sp)
	sw	ra,28(sp)
	.cfi_offset 1, -4
	call	_ZSt24__is_ios_failure_handlerPKN10__cxxabiv117__class_type_infoE@plt
	lw	a1,8(sp)
	lw	a2,12(sp)
	bne	a0,zero,.L26
	mv	a0,s0
	lw	s0,24(sp)
	.cfi_remember_state
	.cfi_restore 8
	lw	ra,28(sp)
	.cfi_restore 1
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	tail	_ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv@plt
.L26:
	.cfi_restore_state
	lw	a5,0(a2)
	lw	ra,28(sp)
	.cfi_restore 1
	lw	s0,24(sp)
	.cfi_restore 8
	addi	a5,a5,16
	sw	a5,0(a2)
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1526:
	.size	_ZNKSt19__iosfail_type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv, .-_ZNKSt19__iosfail_type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv
	.section	.text._ZNSt13__ios_failureD2Ev,"axG",@progbits,_ZNSt13__ios_failureD5Ev,comdat
	.align	2
	.weak	_ZNSt13__ios_failureD2Ev
	.type	_ZNSt13__ios_failureD2Ev, @function
_ZNSt13__ios_failureD2Ev:
.LFB1519:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1519
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	la	a5,_ZTVSt13__ios_failure
	sw	s0,8(sp)
	sw	ra,12(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	addi	a5,a5,8
	mv	s0,a0
	sw	a5,0(a0)
	addi	a0,a0,16
	call	_ZSt21__destroy_ios_failurePv@plt
	mv	a0,s0
	lw	s0,8(sp)
	.cfi_restore 8
	lw	ra,12(sp)
	.cfi_restore 1
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	tail	_ZNSt8ios_base7failureB5cxx11D2Ev@plt
	.cfi_endproc
.LFE1519:
	.section	.gcc_except_table._ZNSt13__ios_failureD2Ev,"aG",@progbits,_ZNSt13__ios_failureD5Ev,comdat
.LLSDA1519:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0
	.section	.text._ZNSt13__ios_failureD2Ev,"axG",@progbits,_ZNSt13__ios_failureD5Ev,comdat
	.size	_ZNSt13__ios_failureD2Ev, .-_ZNSt13__ios_failureD2Ev
	.weak	_ZNSt13__ios_failureD1Ev
	.set	_ZNSt13__ios_failureD1Ev,_ZNSt13__ios_failureD2Ev
	.section	.text._ZNSt13__ios_failureD0Ev,"axG",@progbits,_ZNSt13__ios_failureD5Ev,comdat
	.align	2
	.weak	_ZNSt13__ios_failureD0Ev
	.type	_ZNSt13__ios_failureD0Ev, @function
_ZNSt13__ios_failureD0Ev:
.LFB1521:
	.cfi_startproc
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	la	t1,_ZNSt13__ios_failureD1Ev
	sw	s0,8(sp)
	sw	ra,12(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	mv	s0,a0
	jalr	t1
	mv	a0,s0
	lw	s0,8(sp)
	.cfi_restore 8
	lw	ra,12(sp)
	.cfi_restore 1
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	tail	_ZdlPv@plt
	.cfi_endproc
.LFE1521:
	.size	_ZNSt13__ios_failureD0Ev, .-_ZNSt13__ios_failureD0Ev
	.section	.rodata._ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.str1.4,"aMS",@progbits,1
	.align	2
.LC3:
	.string	"basic_string::append"
	.align	2
.LC4:
	.string	": "
	.section	.text._ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"axG",@progbits,_ZNSt12system_errorC5ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.align	2
	.weak	_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1133:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1133
	addi	sp,sp,-128
	.cfi_def_cfa_offset 128
	sw	s1,116(sp)
	.cfi_offset 9, -12
	addi	s1,sp,48
	sw	s0,120(sp)
	sw	a1,8(sp)
	.cfi_offset 8, -8
	mv	s0,a0
	mv	a1,a3
	mv	a0,s1
	sw	ra,124(sp)
	sw	s2,112(sp)
	sw	s3,108(sp)
	.cfi_offset 1, -4
	.cfi_offset 18, -16
	.cfi_offset 19, -20
	sw	a2,12(sp)
.LEHB2:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@plt
.LEHE2:
	lw	a4,52(sp)
	li	a5,1073741824
	addi	a5,a5,-1
	sub	a5,a5,a4
	li	a4,1
	bgtu	a5,a4,.L33
	lla	a0,.LC3
.LEHB3:
	call	_ZSt20__throw_length_errorPKc@plt
.L48:
.L53:
	mv	s0,a0
	j	.L42
.L33:
	li	a2,2
	lla	a1,.LC4
	mv	a0,s1
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcj@plt
.LEHE3:
	lw	a1,12(sp)
	lw	a2,8(sp)
	addi	s2,sp,72
	lw	a5,0(a1)
	mv	a0,s2
	lw	a5,16(a5)
.LEHB4:
	jalr	a5
.LEHE4:
	lw	a4,76(sp)
	lw	a5,52(sp)
	lw	a2,48(sp)
	li	a3,15
	add	a5,a5,a4
	addi	a4,sp,56
	beq	a2,a4,.L36
	lw	a3,56(sp)
.L36:
	addi	s3,sp,24
	bleu	a5,a3,.L37
	lw	a2,72(sp)
	addi	a4,sp,80
	li	a3,15
	beq	a2,a4,.L38
	lw	a3,80(sp)
.L38:
	bgtu	a5,a3,.L37
	mv	a2,s1
	li	a1,0
	mv	a0,s2
.LEHB5:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEjRKS4_@plt
	j	.L52
.L37:
	mv	a1,s2
	mv	a0,s1
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_@plt
.LEHE5:
.L52:
	mv	a1,a0
	mv	a0,s3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@plt
	mv	a1,s3
	mv	a0,s0
.LEHB6:
	call	_ZNSt13runtime_errorC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@plt
.LEHE6:
	mv	a0,s3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	mv	a0,s2
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	mv	a0,s1
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	la	a5,_ZTVSt12system_error
	addi	a5,a5,8
	sw	a5,0(s0)
	lw	a5,8(sp)
	lw	ra,124(sp)
	.cfi_remember_state
	.cfi_restore 1
	lw	s1,116(sp)
	.cfi_restore 9
	sw	a5,8(s0)
	lw	a5,12(sp)
	lw	s2,112(sp)
	.cfi_restore 18
	lw	s3,108(sp)
	.cfi_restore 19
	sw	a5,12(s0)
	lw	s0,120(sp)
	.cfi_restore 8
	addi	sp,sp,128
	.cfi_def_cfa_offset 0
	jr	ra
.L47:
	.cfi_restore_state
	mv	s0,a0
	mv	a0,s3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
.L41:
	mv	a0,s2
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
.L42:
	mv	a0,s1
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	mv	a0,s0
.LEHB7:
	call	_Unwind_Resume@plt
.LEHE7:
.L46:
	mv	s0,a0
	j	.L41
.L45:
	j	.L53
	.cfi_endproc
.LFE1133:
	.section	.gcc_except_table._ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"aG",@progbits,_ZNSt12system_errorC5ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
.LLSDA1133:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x4e
	.4byte	.LEHB2-.LFB1133
	.4byte	.LEHE2-.LEHB2
	.4byte	0
	.byte	0
	.4byte	.LEHB3-.LFB1133
	.4byte	.LEHE3-.LEHB3
	.4byte	.L48-.LFB1133
	.byte	0
	.4byte	.LEHB4-.LFB1133
	.4byte	.LEHE4-.LEHB4
	.4byte	.L45-.LFB1133
	.byte	0
	.4byte	.LEHB5-.LFB1133
	.4byte	.LEHE5-.LEHB5
	.4byte	.L46-.LFB1133
	.byte	0
	.4byte	.LEHB6-.LFB1133
	.4byte	.LEHE6-.LEHB6
	.4byte	.L47-.LFB1133
	.byte	0
	.4byte	.LEHB7-.LFB1133
	.4byte	.LEHE7-.LEHB7
	.4byte	0
	.byte	0
	.section	.text._ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"axG",@progbits,_ZNSt12system_errorC5ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.size	_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.weak	_ZNSt12system_errorC1ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.set	_ZNSt12system_errorC1ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.text._ZNSt12system_errorC2ESt10error_codePKc,"axG",@progbits,_ZNSt12system_errorC5ESt10error_codePKc,comdat
	.align	2
	.weak	_ZNSt12system_errorC2ESt10error_codePKc
	.type	_ZNSt12system_errorC2ESt10error_codePKc, @function
_ZNSt12system_errorC2ESt10error_codePKc:
.LFB1136:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1136
	mv	a5,a2
	lw	a4,0(a5)
	addi	sp,sp,-128
	.cfi_def_cfa_offset 128
	sw	s1,116(sp)
	lw	a4,16(a4)
	.cfi_offset 9, -12
	addi	s1,sp,72
	sw	s0,120(sp)
	sw	s3,108(sp)
	sw	a1,8(sp)
	sw	a2,12(sp)
	sw	ra,124(sp)
	mv	a2,a1
	sw	s2,112(sp)
	.cfi_offset 8, -8
	.cfi_offset 19, -20
	.cfi_offset 1, -4
	.cfi_offset 18, -16
	mv	a1,a5
	mv	s0,a0
	mv	a0,s1
	mv	s3,a3
.LEHB8:
	jalr	a4
.LEHE8:
	lla	a2,.LC4
	li	a1,0
	mv	a0,s1
.LEHB9:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEjPKc@plt
.LEHE9:
	addi	s2,sp,48
	mv	a1,a0
	mv	a0,s2
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@plt
	mv	a2,s3
	li	a1,0
	mv	a0,s2
.LEHB10:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEjPKc@plt
.LEHE10:
	addi	s3,sp,24
	mv	a1,a0
	mv	a0,s3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_@plt
	mv	a1,s3
	mv	a0,s0
.LEHB11:
	call	_ZNSt13runtime_errorC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@plt
.LEHE11:
	mv	a0,s3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	mv	a0,s2
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	mv	a0,s1
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	la	a5,_ZTVSt12system_error
	addi	a5,a5,8
	sw	a5,0(s0)
	lw	a5,8(sp)
	lw	ra,124(sp)
	.cfi_remember_state
	.cfi_restore 1
	lw	s1,116(sp)
	.cfi_restore 9
	sw	a5,8(s0)
	lw	a5,12(sp)
	lw	s2,112(sp)
	.cfi_restore 18
	lw	s3,108(sp)
	.cfi_restore 19
	sw	a5,12(s0)
	lw	s0,120(sp)
	.cfi_restore 8
	addi	sp,sp,128
	.cfi_def_cfa_offset 0
	jr	ra
.L60:
	.cfi_restore_state
	mv	s0,a0
	mv	a0,s3
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
.L56:
	mv	a0,s2
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
.L57:
	mv	a0,s1
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv@plt
	mv	a0,s0
.LEHB12:
	call	_Unwind_Resume@plt
.LEHE12:
.L59:
	mv	s0,a0
	j	.L56
.L58:
	mv	s0,a0
	j	.L57
	.cfi_endproc
.LFE1136:
	.section	.gcc_except_table._ZNSt12system_errorC2ESt10error_codePKc,"aG",@progbits,_ZNSt12system_errorC5ESt10error_codePKc,comdat
.LLSDA1136:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x41
	.4byte	.LEHB8-.LFB1136
	.4byte	.LEHE8-.LEHB8
	.4byte	0
	.byte	0
	.4byte	.LEHB9-.LFB1136
	.4byte	.LEHE9-.LEHB9
	.4byte	.L58-.LFB1136
	.byte	0
	.4byte	.LEHB10-.LFB1136
	.4byte	.LEHE10-.LEHB10
	.4byte	.L59-.LFB1136
	.byte	0
	.4byte	.LEHB11-.LFB1136
	.4byte	.LEHE11-.LEHB11
	.4byte	.L60-.LFB1136
	.byte	0
	.4byte	.LEHB12-.LFB1136
	.4byte	.LEHE12-.LEHB12
	.4byte	0
	.byte	0
	.section	.text._ZNSt12system_errorC2ESt10error_codePKc,"axG",@progbits,_ZNSt12system_errorC5ESt10error_codePKc,comdat
	.size	_ZNSt12system_errorC2ESt10error_codePKc, .-_ZNSt12system_errorC2ESt10error_codePKc
	.weak	_ZNSt12system_errorC1ESt10error_codePKc
	.set	_ZNSt12system_errorC1ESt10error_codePKc,_ZNSt12system_errorC2ESt10error_codePKc
	.section	.text._ZSt17iostream_categoryv,"ax",@progbits
	.align	2
	.globl	_ZSt17iostream_categoryv
	.type	_ZSt17iostream_categoryv, @function
_ZSt17iostream_categoryv:
.LFB1497:
	.cfi_startproc
	lla	a0,.LANCHOR1
	ret
	.cfi_endproc
.LFE1497:
	.size	_ZSt17iostream_categoryv, .-_ZSt17iostream_categoryv
	.section	.text._ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"ax",@progbits
	.align	2
	.globl	_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1499:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	ra,44(sp)
	sw	s0,40(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	sw	a1,12(sp)
	mv	s0,a0
	call	_ZSt17iostream_categoryv@plt
	lw	a3,12(sp)
	mv	a2,a0
	li	a1,1
	mv	a0,s0
	la	t1,_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	jalr	t1
	la	a5,_ZTVNSt8ios_base7failureB5cxx11E
	addi	a5,a5,8
	lw	ra,44(sp)
	.cfi_restore 1
	sw	a5,0(s0)
	lw	s0,40(sp)
	.cfi_restore 8
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1499:
	.size	_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.globl	_ZNSt8ios_base7failureB5cxx11C1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.set	_ZNSt8ios_base7failureB5cxx11C1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.text._ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code,"ax",@progbits
	.align	2
	.globl	_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code
	.type	_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code, @function
_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code:
.LFB1502:
	.cfi_startproc
	mv	a3,a1
	lw	a1,0(a2)
	lw	a2,4(a2)
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	la	t1,_ZNSt12system_errorC2ESt10error_codeRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	sw	s0,8(sp)
	sw	ra,12(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	mv	s0,a0
	jalr	t1
	la	a5,_ZTVNSt8ios_base7failureB5cxx11E
	addi	a5,a5,8
	lw	ra,12(sp)
	.cfi_restore 1
	sw	a5,0(s0)
	lw	s0,8(sp)
	.cfi_restore 8
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1502:
	.size	_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code, .-_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code
	.globl	_ZNSt8ios_base7failureB5cxx11C1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code
	.set	_ZNSt8ios_base7failureB5cxx11C1ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code,_ZNSt8ios_base7failureB5cxx11C2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSt10error_code
	.section	.text._ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code,"ax",@progbits
	.align	2
	.globl	_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code
	.type	_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code, @function
_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code:
.LFB1505:
	.cfi_startproc
	mv	a3,a1
	lw	a1,0(a2)
	lw	a2,4(a2)
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	la	t1,_ZNSt12system_errorC2ESt10error_codePKc
	sw	s0,8(sp)
	sw	ra,12(sp)
	.cfi_offset 8, -8
	.cfi_offset 1, -4
	mv	s0,a0
	jalr	t1
	la	a5,_ZTVNSt8ios_base7failureB5cxx11E
	addi	a5,a5,8
	lw	ra,12(sp)
	.cfi_restore 1
	sw	a5,0(s0)
	lw	s0,8(sp)
	.cfi_restore 8
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1505:
	.size	_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code, .-_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code
	.globl	_ZNSt8ios_base7failureB5cxx11C1EPKcRKSt10error_code
	.set	_ZNSt8ios_base7failureB5cxx11C1EPKcRKSt10error_code,_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code
	.section	.text.unlikely._ZSt19__throw_ios_failurePKc,"ax",@progbits
	.align	2
	.globl	_ZSt19__throw_ios_failurePKc
	.type	_ZSt19__throw_ios_failurePKc, @function
_ZSt19__throw_ios_failurePKc:
.LFB1527:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1527
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	s1,36(sp)
	.cfi_offset 9, -12
	mv	s1,a0
	li	a0,24
	sw	ra,44(sp)
	sw	s0,40(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	call	__cxa_allocate_exception@plt
	mv	s0,a0
	mv	a0,s1
	call	gettext@plt
	sw	a0,12(sp)
	call	_ZSt17iostream_categoryv@plt
	lw	a1,12(sp)
	li	a5,1
	sw	a0,28(sp)
	addi	a2,sp,24
	mv	a0,s0
	sw	a5,24(sp)
.LEHB13:
	call	_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code@plt
.LEHE13:
	la	a5,_ZTVSt13__ios_failure
	addi	a5,a5,8
	mv	a0,s0
	sw	a5,0(s0)
	call	_ZNKSt13runtime_error4whatEv@plt
	mv	a1,a0
	addi	a0,s0,16
.LEHB14:
	call	_ZSt23__construct_ios_failurePvPKc@plt
.LEHE14:
	j	.L78
.L75:
	mv	s1,a0
	mv	a0,s0
	call	_ZNSt8ios_base7failureB5cxx11D2Ev@plt
.L73:
	mv	a0,s0
	call	__cxa_free_exception@plt
	mv	a0,s1
.LEHB15:
	call	_Unwind_Resume@plt
.L78:
	la	a2,_ZNSt13__ios_failureD1Ev
	la	a1,_ZTISt13__ios_failure
	mv	a0,s0
	call	__cxa_throw@plt
.LEHE15:
.L74:
	mv	s1,a0
	j	.L73
	.cfi_endproc
.LFE1527:
	.section	.gcc_except_table._ZSt19__throw_ios_failurePKc,"a",@progbits
.LLSDA1527:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x27
	.4byte	.LEHB13-.LFB1527
	.4byte	.LEHE13-.LEHB13
	.4byte	.L74-.LFB1527
	.byte	0
	.4byte	.LEHB14-.LFB1527
	.4byte	.LEHE14-.LEHB14
	.4byte	.L75-.LFB1527
	.byte	0
	.4byte	.LEHB15-.LFB1527
	.4byte	.LEHE15-.LEHB15
	.4byte	0
	.byte	0
	.section	.text.unlikely._ZSt19__throw_ios_failurePKc
	.size	_ZSt19__throw_ios_failurePKc, .-_ZSt19__throw_ios_failurePKc
	.section	.text.unlikely._ZSt19__throw_ios_failurePKci,"ax",@progbits
	.align	2
	.globl	_ZSt19__throw_ios_failurePKci
	.type	_ZSt19__throw_ios_failurePKci, @function
_ZSt19__throw_ios_failurePKci:
.LFB1537:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1537
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	s2,16(sp)
	.cfi_offset 18, -16
	mv	s2,a0
	li	a0,24
	sw	ra,28(sp)
	sw	s0,24(sp)
	sw	s1,20(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	.cfi_offset 9, -12
	mv	s1,a1
	call	__cxa_allocate_exception@plt
	mv	s0,a0
	mv	a0,s2
	call	gettext@plt
	mv	s2,a0
	beq	s1,zero,.L80
	call	_ZNSt3_V216generic_categoryEv@plt
	sw	s1,8(sp)
.L89:
	sw	a0,12(sp)
	addi	a2,sp,8
	mv	a1,s2
	mv	a0,s0
.LEHB16:
	call	_ZNSt8ios_base7failureB5cxx11C2EPKcRKSt10error_code@plt
.LEHE16:
	j	.L90
.L80:
	call	_ZSt17iostream_categoryv@plt
	li	a5,1
	sw	a5,8(sp)
	j	.L89
.L90:
	la	a5,_ZTVSt13__ios_failure
	addi	a5,a5,8
	mv	a0,s0
	sw	a5,0(s0)
	call	_ZNKSt13runtime_error4whatEv@plt
	mv	a1,a0
	addi	a0,s0,16
.LEHB17:
	call	_ZSt23__construct_ios_failurePvPKc@plt
.LEHE17:
	j	.L91
.L86:
	mv	s1,a0
	mv	a0,s0
	call	_ZNSt8ios_base7failureB5cxx11D2Ev@plt
.L84:
	mv	a0,s0
	call	__cxa_free_exception@plt
	mv	a0,s1
.LEHB18:
	call	_Unwind_Resume@plt
.L91:
	la	a2,_ZNSt13__ios_failureD1Ev
	la	a1,_ZTISt13__ios_failure
	mv	a0,s0
	call	__cxa_throw@plt
.LEHE18:
.L85:
	mv	s1,a0
	j	.L84
	.cfi_endproc
.LFE1537:
	.section	.gcc_except_table._ZSt19__throw_ios_failurePKci,"a",@progbits
.LLSDA1537:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x27
	.4byte	.LEHB16-.LFB1537
	.4byte	.LEHE16-.LEHB16
	.4byte	.L85-.LFB1537
	.byte	0
	.4byte	.LEHB17-.LFB1537
	.4byte	.LEHE17-.LEHB17
	.4byte	.L86-.LFB1537
	.byte	0
	.4byte	.LEHB18-.LFB1537
	.4byte	.LEHE18-.LEHB18
	.4byte	0
	.byte	0
	.section	.text.unlikely._ZSt19__throw_ios_failurePKci
	.size	_ZSt19__throw_ios_failurePKci, .-_ZSt19__throw_ios_failurePKci
	.section	.text.startup._GLOBAL__sub_I_cxx11_ios_failure.cc,"ax",@progbits
	.align	2
	.type	_GLOBAL__sub_I_cxx11_ios_failure.cc, @function
_GLOBAL__sub_I_cxx11_ios_failure.cc:
.LFB1880:
	.cfi_startproc
	lla	a2,__dso_handle
	lla	a1,.LANCHOR1
	lla	a0,_ZN12_GLOBAL__N_113constant_initD1Ev
	tail	__cxa_atexit@plt
	.cfi_endproc
.LFE1880:
	.size	_GLOBAL__sub_I_cxx11_ios_failure.cc, .-_GLOBAL__sub_I_cxx11_ios_failure.cc
	.section	.init_array,"aw"
	.align	2
	.word	_GLOBAL__sub_I_cxx11_ios_failure.cc
	.weak	_ZTSNSt8ios_base7failureB5cxx11E
	.section	.rodata._ZTSNSt8ios_base7failureB5cxx11E,"aG",@progbits,_ZTSNSt8ios_base7failureB5cxx11E,comdat
	.align	2
	.type	_ZTSNSt8ios_base7failureB5cxx11E, @object
	.size	_ZTSNSt8ios_base7failureB5cxx11E, 29
_ZTSNSt8ios_base7failureB5cxx11E:
	.string	"NSt8ios_base7failureB5cxx11E"
	.weak	_ZTINSt8ios_base7failureB5cxx11E
	.section	.data.rel.ro._ZTINSt8ios_base7failureB5cxx11E,"awG",@progbits,_ZTINSt8ios_base7failureB5cxx11E,comdat
	.align	2
	.type	_ZTINSt8ios_base7failureB5cxx11E, @object
	.size	_ZTINSt8ios_base7failureB5cxx11E, 12
_ZTINSt8ios_base7failureB5cxx11E:
	.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word	_ZTSNSt8ios_base7failureB5cxx11E
	.word	_ZTISt12system_error
	.weak	_ZTSSt13__ios_failure
	.section	.rodata._ZTSSt13__ios_failure,"aG",@progbits,_ZTSSt13__ios_failure,comdat
	.align	2
	.type	_ZTSSt13__ios_failure, @object
	.size	_ZTSSt13__ios_failure, 18
_ZTSSt13__ios_failure:
	.string	"St13__ios_failure"
	.weak	_ZTISt13__ios_failure
	.section	.data.rel.ro._ZTISt13__ios_failure,"awG",@progbits,_ZTISt13__ios_failure,comdat
	.align	2
	.type	_ZTISt13__ios_failure, @object
	.size	_ZTISt13__ios_failure, 12
_ZTISt13__ios_failure:
	.word	_ZTVSt19__iosfail_type_info+8
	.word	_ZTSSt13__ios_failure
	.word	_ZTINSt8ios_base7failureB5cxx11E
	.weak	_ZTSSt19__iosfail_type_info
	.section	.rodata._ZTSSt19__iosfail_type_info,"aG",@progbits,_ZTSSt19__iosfail_type_info,comdat
	.align	2
	.type	_ZTSSt19__iosfail_type_info, @object
	.size	_ZTSSt19__iosfail_type_info, 24
_ZTSSt19__iosfail_type_info:
	.string	"St19__iosfail_type_info"
	.weak	_ZTISt19__iosfail_type_info
	.section	.data.rel.ro._ZTISt19__iosfail_type_info,"awG",@progbits,_ZTISt19__iosfail_type_info,comdat
	.align	2
	.type	_ZTISt19__iosfail_type_info, @object
	.size	_ZTISt19__iosfail_type_info, 24
_ZTISt19__iosfail_type_info:
	.word	_ZTVN10__cxxabiv121__vmi_class_type_infoE+8
	.word	_ZTSSt19__iosfail_type_info
	.word	0
	.word	1
	.word	_ZTIN10__cxxabiv120__si_class_type_infoE
	.word	0
	.weak	_ZTVNSt8ios_base7failureB5cxx11E
	.section	.data.rel.ro._ZTVNSt8ios_base7failureB5cxx11E,"awG",@progbits,_ZTVNSt8ios_base7failureB5cxx11E,comdat
	.align	2
	.type	_ZTVNSt8ios_base7failureB5cxx11E, @object
	.size	_ZTVNSt8ios_base7failureB5cxx11E, 20
_ZTVNSt8ios_base7failureB5cxx11E:
	.word	0
	.word	_ZTINSt8ios_base7failureB5cxx11E
	.word	_ZNSt8ios_base7failureB5cxx11D1Ev
	.word	_ZNSt8ios_base7failureB5cxx11D0Ev
	.word	_ZNKSt8ios_base7failureB5cxx114whatEv
	.weak	_ZTVSt13__ios_failure
	.section	.data.rel.ro._ZTVSt13__ios_failure,"awG",@progbits,_ZTVSt13__ios_failure,comdat
	.align	2
	.type	_ZTVSt13__ios_failure, @object
	.size	_ZTVSt13__ios_failure, 20
_ZTVSt13__ios_failure:
	.word	0
	.word	_ZTISt13__ios_failure
	.word	_ZNSt13__ios_failureD1Ev
	.word	_ZNSt13__ios_failureD0Ev
	.word	_ZNKSt8ios_base7failureB5cxx114whatEv
	.weak	_ZTVSt19__iosfail_type_info
	.section	.data.rel.ro._ZTVSt19__iosfail_type_info,"awG",@progbits,_ZTVSt19__iosfail_type_info,comdat
	.align	2
	.type	_ZTVSt19__iosfail_type_info, @object
	.size	_ZTVSt19__iosfail_type_info, 44
_ZTVSt19__iosfail_type_info:
	.word	0
	.word	_ZTISt19__iosfail_type_info
	.word	_ZNSt19__iosfail_type_infoD1Ev
	.word	_ZNSt19__iosfail_type_infoD0Ev
	.word	_ZNKSt9type_info14__is_pointer_pEv
	.word	_ZNKSt9type_info15__is_function_pEv
	.word	_ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj
	.word	_ZNKSt19__iosfail_type_info11__do_upcastEPKN10__cxxabiv117__class_type_infoEPPv
	.word	_ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE
	.word	_ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE
	.word	_ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_
	.section	.data.rel.local._ZN12_GLOBAL__N_120io_category_instanceE,"aw"
	.align	2
	.set	.LANCHOR1,. + 0
	.type	_ZN12_GLOBAL__N_120io_category_instanceE, @object
	.size	_ZN12_GLOBAL__N_120io_category_instanceE, 4
_ZN12_GLOBAL__N_120io_category_instanceE:
	.word	_ZTVN12_GLOBAL__N_117io_error_categoryE+8
	.section	.data.rel.ro._ZTIN12_GLOBAL__N_117io_error_categoryE,"aw"
	.align	2
	.type	_ZTIN12_GLOBAL__N_117io_error_categoryE, @object
	.size	_ZTIN12_GLOBAL__N_117io_error_categoryE, 12
_ZTIN12_GLOBAL__N_117io_error_categoryE:
	.word	_ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word	_ZTSN12_GLOBAL__N_117io_error_categoryE
	.word	_ZTINSt3_V214error_categoryE
	.section	.data.rel.ro._ZTVN12_GLOBAL__N_117io_error_categoryE,"aw"
	.align	2
	.set	.LANCHOR0,. + 0
	.type	_ZTVN12_GLOBAL__N_117io_error_categoryE, @object
	.size	_ZTVN12_GLOBAL__N_117io_error_categoryE, 40
_ZTVN12_GLOBAL__N_117io_error_categoryE:
	.word	0
	.word	_ZTIN12_GLOBAL__N_117io_error_categoryE
	.word	_ZN12_GLOBAL__N_117io_error_categoryD1Ev
	.word	_ZN12_GLOBAL__N_117io_error_categoryD0Ev
	.word	_ZNK12_GLOBAL__N_117io_error_category4nameEv
	.word	_ZNKSt3_V214error_category10_M_messageB5cxx11Ei
	.word	_ZNK12_GLOBAL__N_117io_error_category7messageB5cxx11Ei
	.word	_ZNKSt3_V214error_category23default_error_conditionEi
	.word	_ZNKSt3_V214error_category10equivalentEiRKSt15error_condition
	.word	_ZNKSt3_V214error_category10equivalentERKSt10error_codei
	.section	.rodata._ZTSN12_GLOBAL__N_117io_error_categoryE,"a"
	.align	2
	.type	_ZTSN12_GLOBAL__N_117io_error_categoryE, @object
	.size	_ZTSN12_GLOBAL__N_117io_error_categoryE, 37
_ZTSN12_GLOBAL__N_117io_error_categoryE:
	.string	"*N12_GLOBAL__N_117io_error_categoryE"
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align	2
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 4
DW.ref.__gxx_personality_v0:
	.word	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Buildroot 2023.02.5) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
