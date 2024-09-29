	.file	"arrays.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Primes array: \0"
LC1:
	.ascii "%d \0"
	.align 4
LC2:
	.ascii "Size of primes array in bytes: %d\12\0"
LC3:
	.ascii "Size of array element: %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$2, 20(%esp)
	movl	$3, 24(%esp)
	movl	$4, 28(%esp)
	movl	$6, 32(%esp)
	movl	$8, 36(%esp)
	movl	$20, 40(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, 44(%esp)
	jmp	L2
L3:
	movl	44(%esp), %eax
	movl	20(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	addl	$1, 44(%esp)
L2:
	movl	44(%esp), %eax
	cmpl	$4, %eax
	jbe	L3
	movl	$10, (%esp)
	call	_putchar
	movl	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$4, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
