.globl add4
	.type	add4, @function
add4:
# Input 1: rdi <--- S
# Input 2: rsi <--- A
# Input 3: rdx <--- B
	movq	(%rdx), %rax
	addq	(%rsi), %rax
	movq	%rax, (%rdi)
	movq	8(%rdx), %rax
	adcq	8(%rsi), %rax
	movq	%rax, 8(%rdi)
	movq	16(%rdx), %rax
	adcq	16(%rsi), %rax
	movq	%rax, 16(%rdi)
	movq	24(%rdx), %rax
	adcq	24(%rsi), %rax
	movq	%rax, 24(%rdi)
	ret
