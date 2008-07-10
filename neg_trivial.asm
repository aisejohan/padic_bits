.globl neg4
	.type	neg4, @function
neg4:
# Input 1: rdi <--- A
	notq	(%rdi)
	notq	8(%rdi)
	notq	16(%rdi)
	notq	24(%rdi)
	addq	$1, (%rdi)
	adcq	$0, 8(%rdi)
	adcq	$0, 16(%rdi)
	adcq	$0, 24(%rdi)
	ret
