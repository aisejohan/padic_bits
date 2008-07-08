.globl val4
	.type	val4, @function
val4:
# Input 1: rdi <--- A
	bsfq	(%rdi), %rax		# bit scan forward A[0] into rax
	jnz	.UIT			# if A[0] != 0 then goto UIT
	movl	$64, %edx		# put 64 in edx
	bsfq	8(%rdi), %rax		# bit scan forward A[1] into rax
	jnz	.ADD
	movl	$128, %edx
	bsfq	16(%rdi), %rax
	jnz	.ADD
	movl	$192, %edx
	bsfq	24(%rdi), %rax
	jnz	.ADD
	movl	$256, %eax
	jmp	.UIT
.ADD:
	addq	%rdx, %rax		# add rdx to rax
.UIT:
	ret
