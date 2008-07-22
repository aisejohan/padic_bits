.globl loop_mul4
	.type	loop_mul4, @function
loop_mul4:
# Input 1: rdi <--- S
# Input 2: rsi <--- A
# Input 3: rdx <--- b
# number of terms 32

	movq	%rdx, %rcx

# multiply

	movq	(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)

	movq	8(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, 16(%rdi)
	movq	%rdx, 24(%rdi)

	movq	24(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, 32(%rdi)
	movq	%rdx, 40(%rdi)

	movq	40(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, 48(%rdi)
	movq	%rdx, 56(%rdi)

	movq	56(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, 64(%rdi)
	movq	%rdx, 72(%rdi)

	movq	72(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	80(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, 80(%rdi)
	movq	%rdx, 88(%rdi)

	movq	88(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, %mm2
	movq	%rdx, %mm3

	movq	96(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, 96(%rdi)
	movq	%rdx, 104(%rdi)

	movq	104(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, %mm4
	movq	%rdx, %mm5

	movq	112(%rsi), %rax
	mulq	(%rcx)
	movq	%rax, 112(%rdi)
	movq	%rdx, 120(%rdi)

	movq	120(%rsi), %rax
	mulq	(%rcx)

# add results with carry

	addq	%r8, 8(%rdi)
	adcq	%r9, 16(%rdi)
	adcq	%r10, 24(%rdi)
	adcq	%r11, 32(%rdi)
	adcq	%r12, 40(%rdi)
	adcq	%r13, 48(%rdi)
	adcq	%r14, 56(%rdi)
	adcq	%r15, 64(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 72(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 80(%rdi)
	movq	%mm2, %r10
	adcq	%r10, 88(%rdi)
	movq	%mm3, %r11
	adcq	%r11, 96(%rdi)
	movq	%mm4, %r12
	adcq	%r12, 104(%rdi)
	movq	%mm5, %r13
	adcq	%r13, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	80(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %mm2
	movq	%rdx, %mm3

	movq	96(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %mm4
	movq	%rdx, %mm5

	movq	112(%rsi), %rax
	mulq	8(%rcx)

# add results with carry

	addq	%r8, 8(%rdi)
	adcq	%r9, 16(%rdi)
	adcq	%r10, 24(%rdi)
	adcq	%r11, 32(%rdi)
	adcq	%r12, 40(%rdi)
	adcq	%r13, 48(%rdi)
	adcq	%r14, 56(%rdi)
	adcq	%r15, 64(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 72(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 80(%rdi)
	movq	%mm2, %r10
	adcq	%r10, 88(%rdi)
	movq	%mm3, %r11
	adcq	%r11, 96(%rdi)
	movq	%mm4, %r12
	adcq	%r12, 104(%rdi)
	movq	%mm5, %r13
	adcq	%r13, 112(%rdi)
	adcq	%rax, 120(%rdi)

	ret
