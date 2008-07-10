.globl div4_xmms
	.type	div4_xmms, @function
div4_xmms:
# Input 1: rdi <--- A
# Input 2: rsi <--- k
	movq	(%rdi), %mm6		# A[0]
	movd	%esi, %mm0		# Shift parameter k
	movl	$64, %eax
	subl	%esi, %eax
	movd	%eax, %mm1		# 64 - k
	movq	8(%rdi), %mm7		# A[1]
	movq	%mm7, %mm5		# copy of A[1]
	psrlq	%mm0, %mm6		# A[0] >> k
	psllq	%mm1, %mm7		# A[1] << (64 -k)
	por	%mm6, %mm7
	movq	%mm7, (%rdi)
# mm5 = A[1]
	movq	16(%rdi), %mm4		# A[2]
	movq	%mm4, %mm2		# copy of A[2]
	psrlq	%mm0, %mm5		# A[1] >> k
	psllq	%mm1, %mm4		# A[2] << (64 - k)
	por	%mm4, %mm5
	movq	%mm5, 8(%rdi)
# mm2 = A[2]
	movq	24(%rdi), %mm7		# A[3]
	movq	%mm7, %mm5		# copy of A[3]
	psrlq	%mm0, %mm2		# A[2] >> k
	psllq	%mm1, %mm7		# A[3] << (64 - k)
	por	%mm2, %mm7
	movq	%mm7, 16(%rdi)
# mm5 = A[3]
	psrlq	%mm0, %mm5
	movq	%mm5, 24(%rdi)
	emms
	ret
