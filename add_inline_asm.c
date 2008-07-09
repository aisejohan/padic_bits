void add4_inline_asm(unsigned long *S, unsigned long *A, unsigned long *B)
{
	__asm__("movq	(%2), %%rax		\n\t"	\
		"addq	(%1), %%rax		\n\t"	\
		"movq	%%rax, (%0)		\n\t"	\
		"movq	8(%2), %%rax		\n\t"	\
		"adcq	8(%1), %%rax		\n\t"	\
		"movq	%%rax, 8(%0)		\n\t"	\
		"movq	16(%2), %%rax		\n\t"	\
		"adcq	16(%1), %%rax		\n\t"	\
		"movq	%%rax, 16(%0)		\n\t"	\
		"movq	24(%2), %%rax		\n\t"	\
		"adcq	24(%1), %%rax		\n\t"	\
		"movq	%%rax, 24(%0)"			\
		: 					\
		: "r" (S), "r" (A), "r" (B)		\
		: "rax");
	return;
}
