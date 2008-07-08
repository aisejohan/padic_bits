.globl my_rdtsc
	.type	my_rdtsc, @function
my_rdtsc:
	rdtsc
	shl	$32, %rdx
	or	%rdx, %rax
	ret
