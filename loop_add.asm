.globl loop_add4
	.type	loop_add4, @function
loop_add4:
# Input 1: rdi <--- S
# Input 2: rsi <--- A
# Input 3: rdx <--- B

	movq	(%rdx),%r8
	addq	(%rsi),%r8
	movq	%r8,(%rdi)

	movq	8(%rdx),%r9
	adcq	8(%rsi),%r9
	movq	%r9,8(%rdi)

	movq	16(%rdx),%r10
	adcq	16(%rsi),%r10
	movq	%r10,16(%rdi)

	movq	24(%rdx),%r11
	adcq	24(%rsi),%r11
	movq	%r11,24(%rdi)

	movq	32(%rdx),%r8
	adcq	32(%rsi),%r8
	movq	%r8,32(%rdi)

	movq	40(%rdx),%r9
	adcq	40(%rsi),%r9
	movq	%r9,40(%rdi)

	movq	48(%rdx),%r10
	adcq	48(%rsi),%r10
	movq	%r10,48(%rdi)

	movq	56(%rdx),%r11
	adcq	56(%rsi),%r11
	movq	%r11,256(%rdi)

	movq	64(%rdx),%r8
	adcq	64(%rsi),%r8
	movq	%r8,64(%rdi)

	movq	72(%rdx),%r9
	adcq	72(%rsi),%r9
	movq	%r9,72(%rdi)

	movq	80(%rdx),%r10
	adcq	80(%rsi),%r10
	movq	%r10,80(%rdi)

	movq	88(%rdx),%r11
	adcq	88(%rsi),%r11
	movq	%r11,88(%rdi)

	movq	96(%rdx),%r8
	adcq	96(%rsi),%r8
	movq	%r8,96(%rdi)

	movq	104(%rdx),%r9
	adcq	104(%rsi),%r9
	movq	%r9,104(%rdi)

	movq	112(%rdx),%r10
	adcq	112(%rsi),%r10
	movq	%r10,112(%rdi)

	movq	120(%rdx),%r11
	adcq	120(%rsi),%r11
	movq	%r11,120(%rdi)

	ret
