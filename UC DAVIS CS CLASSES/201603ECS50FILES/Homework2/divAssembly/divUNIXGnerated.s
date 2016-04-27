	.file	"div.c"
	.section	.rodata
.LC0:
	.string	"%u / %u = %u R %u \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-48(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -20(%rbp)
	movq	-48(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -24(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jnb	.L2
	movl	$0, -4(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L3
.L2:
	movl	-12(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jne	.L4
	movl	$1, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L3
.L4:
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L5
.L8:
	sall	-4(%rbp)
	sall	-8(%rbp)
	movl	-12(%rbp), %eax
	testl	%eax, %eax
	jns	.L6
	addl	$1, -8(%rbp)
.L6:
	movl	-8(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jb	.L7
	movl	-24(%rbp), %eax
	subl	%eax, -8(%rbp)
	addl	$1, -4(%rbp)
.L7:
	sall	-12(%rbp)
	addl	$1, -16(%rbp)
.L5:
	cmpl	$31, -16(%rbp)
	jle	.L8
.L3:
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %ecx
	movl	-24(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.3.1 20160406 (Red Hat 5.3.1-6)"
	.section	.note.GNU-stack,"",@progbits
