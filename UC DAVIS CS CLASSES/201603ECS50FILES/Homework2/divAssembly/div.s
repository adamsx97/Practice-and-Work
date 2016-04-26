	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_good_div
	.align	4, 0x90
_good_div:                              ## @good_div
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
	cmpl	%esi, %edi
	jae	LBB0_2
## BB#1:
	movl	$0, (%rdx)
	movl	%edi, (%rcx)
	popq	%rbp
	retq
LBB0_2:
	jne	LBB0_4
## BB#3:
	movl	$1, (%rdx)
	movl	$0, (%rcx)
	popq	%rbp
	retq
LBB0_4:
	movl	$0, (%rdx)
	movl	$0, (%rcx)
	movl	$32, %r8d
	.align	4, 0x90
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	shll	(%rdx)
	movl	(%rcx), %eax
	shldl	$1, %edi, %eax
	movl	%eax, (%rcx)
	subl	%esi, %eax
	jb	LBB0_7
## BB#6:                                ##   in Loop: Header=BB0_5 Depth=1
	movl	%eax, (%rcx)
	incl	(%rdx)
LBB0_7:                                 ##   in Loop: Header=BB0_5 Depth=1
	addl	%edi, %edi
	decl	%r8d
	jne	LBB0_5
## BB#8:                                ## %.loopexit
	popq	%rbp
	retq
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
	pushq	%r14
	pushq	%rbx
Ltmp6:
	.cfi_offset %rbx, -32
Ltmp7:
	.cfi_offset %r14, -24
	movq	%rsi, %rbx
	movq	8(%rbx), %rdi
	callq	_atoi
	movl	%eax, %r14d
	movq	16(%rbx), %rdi
	callq	_atoi
	movl	%eax, %ebx
	xorl	%ecx, %ecx
	cmpl	%ebx, %r14d
	movl	%r14d, %r8d
	jb	LBB1_4
## BB#1:
	movl	$1, %ecx
	xorl	%r8d, %r8d
	cmpl	%ebx, %r14d
	je	LBB1_4
## BB#2:
	movl	$32, %eax
	xorl	%r9d, %r9d
	xorl	%ecx, %ecx
	movl	%r14d, %edi
	.align	4, 0x90
LBB1_3:                                 ## %.preheader
                                        ## =>This Inner Loop Header: Depth=1
	shldl	$1, %edi, %r8d
	cmpl	%ebx, %r8d
	movl	%ebx, %edx
	cmovbl	%r9d, %edx
	sbbl	%esi, %esi
	subl	%edx, %r8d
	andl	$1, %esi
	leal	(%rsi,%rcx,2), %ecx
	leal	(,%rdi,4), %edx
	shrl	$30, %edi
	andl	$1, %edi
	leal	(%rdi,%r8,2), %r8d
	cmpl	%ebx, %r8d
	movl	%ebx, %esi
	cmovbl	%r9d, %esi
	sbbl	%edi, %edi
	subl	%esi, %r8d
	andl	$1, %edi
	leal	(%rdi,%rcx,2), %ecx
	xorl	$3, %ecx
	addl	$-2, %eax
	movl	%edx, %edi
	jne	LBB1_3
LBB1_4:                                 ## %good_div.exit
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movl	%r14d, %esi
	movl	%ebx, %edx
	callq	_printf
	xorl	%eax, %eax
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%u / %u = %u R %u \n"


.subsections_via_symbols
