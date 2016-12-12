	.file	"overflow1.c"
	.globl	shellcode
	.bss
	.type	shellcode, @object
	.size	shellcode, 1
shellcode:
	.zero	1
	.comm	large_string,128,32
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$136, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	$large_string, -136(%rbp)
	movl	$0, -140(%rbp)
	jmp	.L2
.L3:
	movl	-140(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-136(%rbp), %rax
	addq	%rax, %rdx
	leaq	-128(%rbp), %rax
	cltq
	movq	%rax, (%rdx)
	addl	$1, -140(%rbp)
.L2:
	cmpl	$31, -140(%rbp)
	jle	.L3
	movl	$0, -140(%rbp)
	jmp	.L4
.L5:
	movl	-140(%rbp), %eax
	cltq
	movzbl	shellcode(%rax), %edx
	movl	-140(%rbp), %eax
	cltq
	movb	%dl, large_string(%rax)
	addl	$1, -140(%rbp)
.L4:
	movl	-140(%rbp), %eax
	movslq	%eax, %rbx
	movl	$shellcode, %edi
	call	strlen
	cmpq	%rax, %rbx
	jb	.L5
	leaq	-128(%rbp), %rax
	movl	$large_string, %esi
	movq	%rax, %rdi
	call	strcpy
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L6
	call	__stack_chk_fail
.L6:
	addq	$136, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.1) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
