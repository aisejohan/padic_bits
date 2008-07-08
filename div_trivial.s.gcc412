.globl div4
	.type	div4, @function
div4:
# Input 1: rdi <--- A
# Input 2: rsi <--- k
	movl	%esi, %ecx
	movq	8(%rdi), %rax
	shrdq	%cl, %rax, (%rdi)
	movq	16(%rdi), %rdx
	shrdq	%cl, %rdx, %rax
	movq	%rax, 8(%rdi)
	movq	24(%rdi), %rax
	shrdq	%cl, %rax, %rdx
	movq	%rdx, 16(%rdi)
	shrq	%cl, 24(%rdi)
	ret
