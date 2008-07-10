.globl mul4
	.type	mul4, @function
mul4:
# Input 1: rdi <--- S
# Input 2: rsi <--- A
# Input 3: rdx <--- B
	movq	%rdx, %rcx		# move address B to rcx
	movq	(%rsi), %rax		# move A[0] into rax
	mulq	(%rcx)			# multiply B[0] with A[0]
	movq	%rax, (%rdi)		# move low into S[0]
	movq	%rdx, 8(%rdi)		# move high into S[1]
	movq	8(%rsi), %rax		# move A[1] into rax
	mulq	(%rcx)			# multiply B[0] with A[1]
	movq	%rax, %r8		# move low into r8
	movq	%rdx, %r9		# move high into r9
	movq	16(%rsi), %rax		# move A[2] into rax
	mulq	(%rcx)			# multiply B[0] with A[2]
	movq	%rax, 16(%rdi)		# move low into S[2]
	movq	%rdx, 24(%rdi)		# move high into S[3]
	movq	24(%rsi), %rax		# move A[3] into rax
	mulq	(%rcx)			# multiply B[0] with A[3]
# add results with carry
	addq	%r8, 8(%rdi)
	adcq	%r9, 16(%rdi)
	adcq	%rax, 24(%rdi)
	movq	(%rsi), %rax		# move A[0] into rax
	mulq	8(%rcx)			# multiply B[1] with A[0]
	movq	%rax, %r8		# move low into r8
	movq	%rdx, %r9		# move high into r9
	movq	8(%rsi), %rax		# move A[1] into rax
	mulq	8(%rcx)			# multiply B[1] with A[1]
	movq	%rax, %r10		# move low into r10
# add some of the results with carry
	addq	%r8, 8(%rdi)
	adcq	%r9, 16(%rdi)
	adcq	%rdx, 24(%rdi)
	movq	16(%rsi), %rax		# move A[2] into rax
	mulq	8(%rcx)			# multiply B[1] with A[2]
# add results with carry
	addq	%r10, 16(%rdi)
	adcq	%rax, 24(%rdi)
	movq	(%rsi), %rax		# move A[0] into rax
	mulq	16(%rcx)		# multiply B[2] with A[0]
# add results with carry
	addq	%rax, 16(%rdi)
	adcq	%rdx, 24(%rdi)
	movq	8(%rsi), %rax		# move A[1] into rax
	mulq	16(%rcx)		# multiply B[2] with A[1]
# add result
	addq	%rax, 24(%rdi)
	movq	(%rsi), %rax		# move A[0] into rax
	mulq	24(%rcx)		# multiply B[3] with A[0]
# add result
	addq	%rax, 24(%rdi)
	ret
