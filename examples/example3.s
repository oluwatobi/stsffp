	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_function
	.align	4, 0x90
_function:                              ## @function
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	leaq	-37(%rbp), %rcx
	movq	(%rax), %r8
	movq	%r8, -8(%rbp)
	movl	%edi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	addq	$36, %rcx
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	movl	(%rcx), %edx
	addl	$8, %edx
	movl	%edx, (%rcx)
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	jne	LBB0_2
## BB#1:                                ## %SP_return
	addq	$48, %rsp
	popq	%rbp
	retq
LBB0_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$1, %edi
	movl	$2, %esi
	movl	$3, %edx
	movl	$0, -4(%rbp)
	callq	_function
	leaq	L_.str(%rip), %rdi
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %esi
	movb	$0, %al
	callq	_printf
	xorl	%edx, %edx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%edx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"


.subsections_via_symbols
