.globl neg4
	.type	neg4, @function
neg4:
# Input 1: rdi <--- A
	negq	(%rdi)
	adcq	$0, 8(%rdi)
	adcq	$0, 16(%rdi)
	adcq	$0, 24(%rdi)
	negq	8(%rdi)
	adcq	$0, 16(%rdi)
	adcq	$0, 24(%rdi)
	negq	16(%rdi)
	adcq	$0, 24(%rdi)
	negq	24(%rdi)
	ret
