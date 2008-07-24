.globl loop_mul4
	.type	loop_mul4, @function
loop_mul4:
# Input 1: rdi <--- S
# Input 2: rsi <--- A
# Input 3: rdx <--- B
# number of terms 32
	pushq	%r12
	pushq	%r13
	pushq	%r14
	pushq	%r15

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

# multiply

	movq	8(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	72(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	88(%rsi), %rax
	mulq	8(%rcx)
	movq	%rax, %mm2
	movq	%rdx, %mm3

	movq	104(%rsi), %rax
	mulq	8(%rcx)

# add results with carry

	addq	%r8, 16(%rdi)
	adcq	%r9, 24(%rdi)
	adcq	%r10, 32(%rdi)
	adcq	%r11, 40(%rdi)
	adcq	%r12, 48(%rdi)
	adcq	%r13, 56(%rdi)
	adcq	%r14, 64(%rdi)
	adcq	%r15, 72(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 80(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 88(%rdi)
	movq	%mm2, %r10
	adcq	%r10, 96(%rdi)
	movq	%mm3, %r11
	adcq	%r11, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	80(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %mm2
	movq	%rdx, %mm3

	movq	96(%rsi), %rax
	mulq	16(%rcx)

# add results with carry

	addq	%r8, 16(%rdi)
	adcq	%r9, 24(%rdi)
	adcq	%r10, 32(%rdi)
	adcq	%r11, 40(%rdi)
	adcq	%r12, 48(%rdi)
	adcq	%r13, 56(%rdi)
	adcq	%r14, 64(%rdi)
	adcq	%r15, 72(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 80(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 88(%rdi)
	movq	%mm2, %r10
	adcq	%r10, 96(%rdi)
	movq	%mm3, %r11
	adcq	%r11, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	72(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	88(%rsi), %rax
	mulq	16(%rcx)
	movq	%rax, %mm2
	movq	%rdx, %mm3

	movq	104(%rsi), %rax
	mulq	16(%rcx)

# add results with carry

	addq	%r8, 24(%rdi)
	adcq	%r9, 32(%rdi)
	adcq	%r10, 40(%rdi)
	adcq	%r11, 48(%rdi)
	adcq	%r12, 56(%rdi)
	adcq	%r13, 64(%rdi)
	adcq	%r14, 72(%rdi)
	adcq	%r15, 80(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 88(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 96(%rdi)
	movq	%mm2, %r10
	adcq	%r10, 104(%rdi)
	movq	%mm3, %r11
	adcq	%r11, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	80(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %mm2
	movq	%rdx, %mm3

	movq	96(%rsi), %rax
	mulq	24(%rcx)

# add results with carry

	addq	%r8, 24(%rdi)
	adcq	%r9, 32(%rdi)
	adcq	%r10, 40(%rdi)
	adcq	%r11, 48(%rdi)
	adcq	%r12, 56(%rdi)
	adcq	%r13, 64(%rdi)
	adcq	%r14, 72(%rdi)
	adcq	%r15, 80(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 88(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 96(%rdi)
	movq	%mm2, %r10
	adcq	%r10, 104(%rdi)
	movq	%mm3, %r11
	adcq	%r11, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	72(%rsi), %rax
	mulq	24(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	88(%rsi), %rax
	mulq	24(%rcx)

# add results with carry

	addq	%r8, 32(%rdi)
	adcq	%r9, 40(%rdi)
	adcq	%r10, 48(%rdi)
	adcq	%r11, 56(%rdi)
	adcq	%r12, 64(%rdi)
	adcq	%r13, 72(%rdi)
	adcq	%r14, 80(%rdi)
	adcq	%r15, 88(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 96(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	80(%rsi), %rax
	mulq	32(%rcx)

# add results with carry

	addq	%r8, 32(%rdi)
	adcq	%r9, 40(%rdi)
	adcq	%r10, 48(%rdi)
	adcq	%r11, 56(%rdi)
	adcq	%r12, 64(%rdi)
	adcq	%r13, 72(%rdi)
	adcq	%r14, 80(%rdi)
	adcq	%r15, 88(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 96(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	72(%rsi), %rax
	mulq	32(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	88(%rsi), %rax
	mulq	32(%rcx)

# add results with carry

	addq	%r8, 40(%rdi)
	adcq	%r9, 48(%rdi)
	adcq	%r10, 56(%rdi)
	adcq	%r11, 64(%rdi)
	adcq	%r12, 72(%rdi)
	adcq	%r13, 80(%rdi)
	adcq	%r14, 88(%rdi)
	adcq	%r15, 96(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 104(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %mm0
	movq	%rdx, %mm1

	movq	80(%rsi), %rax
	mulq	40(%rcx)

# add results with carry

	addq	%r8, 40(%rdi)
	adcq	%r9, 48(%rdi)
	adcq	%r10, 56(%rdi)
	adcq	%r11, 64(%rdi)
	adcq	%r12, 72(%rdi)
	adcq	%r13, 80(%rdi)
	adcq	%r14, 88(%rdi)
	adcq	%r15, 96(%rdi)
	movq	%mm0, %r8
	adcq	%r8, 104(%rdi)
	movq	%mm1, %r9
	adcq	%r9, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	40(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	72(%rsi), %rax
	mulq	40(%rcx)


# add results with carry

	addq	%r8, 48(%rdi)
	adcq	%r9, 56(%rdi)
	adcq	%r10, 64(%rdi)
	adcq	%r11, 72(%rdi)
	adcq	%r12, 80(%rdi)
	adcq	%r13, 88(%rdi)
	adcq	%r14, 96(%rdi)
	adcq	%r15, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	48(%rcx)

# add results with carry

	addq	%r8, 48(%rdi)
	adcq	%r9, 56(%rdi)
	adcq	%r10, 64(%rdi)
	adcq	%r11, 72(%rdi)
	adcq	%r12, 80(%rdi)
	adcq	%r13, 88(%rdi)
	adcq	%r14, 96(%rdi)
	adcq	%r15, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	48(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	72(%rsi), %rax
	mulq	48(%rcx)


# add results with carry

	addq	%r8, 56(%rdi)
	adcq	%r9, 64(%rdi)
	adcq	%r10, 72(%rdi)
	adcq	%r11, 80(%rdi)
	adcq	%r12, 88(%rdi)
	adcq	%r13, 96(%rdi)
	adcq	%r14, 104(%rdi)
	adcq	%r15, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	56(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	56(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	56(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	56(%rcx)
	movq	%rax, %r14
	movq	%rdx, %r15

	movq	64(%rsi), %rax
	mulq	56(%rcx)

# add results with carry

	addq	%r8, 56(%rdi)
	adcq	%r9, 64(%rdi)
	adcq	%r10, 72(%rdi)
	adcq	%r11, 80(%rdi)
	adcq	%r12, 88(%rdi)
	adcq	%r13, 96(%rdi)
	adcq	%r14, 104(%rdi)
	adcq	%r15, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	56(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	56(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	56(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	56(%rcx)

# add results with carry

	addq	%r8, 64(%rdi)
	adcq	%r9, 72(%rdi)
	adcq	%r10, 80(%rdi)
	adcq	%r11, 88(%rdi)
	adcq	%r12, 96(%rdi)
	adcq	%r13, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	64(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	64(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	64(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	64(%rcx)

# add results with carry

	addq	%r8, 64(%rdi)
	adcq	%r9, 72(%rdi)
	adcq	%r10, 80(%rdi)
	adcq	%r11, 88(%rdi)
	adcq	%r12, 96(%rdi)
	adcq	%r13, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	64(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	64(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	64(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	56(%rsi), %rax
	mulq	64(%rcx)

# add results with carry

	addq	%r8, 72(%rdi)
	adcq	%r9, 80(%rdi)
	adcq	%r10, 88(%rdi)
	adcq	%r11, 96(%rdi)
	adcq	%r12, 104(%rdi)
	adcq	%r13, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	72(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	72(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	72(%rcx)
	movq	%rax, %r12
	movq	%rdx, %r13

	movq	48(%rsi), %rax
	mulq	72(%rcx)

# add results with carry

	addq	%r8, 72(%rdi)
	adcq	%r9, 80(%rdi)
	adcq	%r10, 88(%rdi)
	adcq	%r11, 96(%rdi)
	adcq	%r12, 104(%rdi)
	adcq	%r13, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	72(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	72(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	72(%rcx)

# add results with carry

	addq	%r8, 80(%rdi)
	adcq	%r9, 88(%rdi)
	adcq	%r10, 96(%rdi)
	adcq	%r11, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	80(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	80(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	80(%rcx)

# add results with carry

	addq	%r8, 80(%rdi)
	adcq	%r9, 88(%rdi)
	adcq	%r10, 96(%rdi)
	adcq	%r11, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	80(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	80(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	40(%rsi), %rax
	mulq	80(%rcx)

# add results with carry

	addq	%r8, 88(%rdi)
	adcq	%r9, 96(%rdi)
	adcq	%r10, 104(%rdi)
	adcq	%r11, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	88(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	88(%rcx)
	movq	%rax, %r10
	movq	%rdx, %r11

	movq	32(%rsi), %rax
	mulq	88(%rcx)

# add results with carry

	addq	%r8, 88(%rdi)
	adcq	%r9, 96(%rdi)
	adcq	%r10, 104(%rdi)
	adcq	%r11, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	88(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	88(%rcx)

# add results with carry

	addq	%r8, 96(%rdi)
	adcq	%r9, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	96(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	96(%rcx)

# add results with carry

	addq	%r8, 96(%rdi)
	adcq	%r9, 104(%rdi)
	adcq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	96(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	24(%rsi), %rax
	mulq	96(%rcx)

# add results with carry

	addq	%r8, 104(%rdi)
	adcq	%r9, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	104(%rcx)
	movq	%rax, %r8
	movq	%rdx, %r9

	movq	16(%rsi), %rax
	mulq	104(%rcx)

# add results with carry

	addq	%r8, 104(%rdi)
	adcq	%r9, 112(%rdi)
	adcq	%rax, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	104(%rcx)

# add results with carry

	addq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	112(%rcx)

# add results with carry

	addq	%rax, 112(%rdi)
	adcq	%rdx, 120(%rdi)

# multiply

	movq	8(%rsi), %rax
	mulq	112(%rcx)

# add results with carry

	addq	%rax, 120(%rdi)

# multiply

	movq	(%rsi), %rax
	mulq	120(%rcx)

# add results with carry

	addq	%rax, 120(%rdi)

	popq	%r15
	popq	%r14
	popq	%r13
	popq	%r12

	ret
