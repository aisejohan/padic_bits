void div4_inline_asm(unsigned long *A, unsigned int k)
{
	__asm__("movq	8(%0), %%rax		\n\t"	\
		"shrdq	%%cl, %%rax, (%0)	\n\t"	\
		"movq	16(%0), %%rdx		\n\t"	\
		"shrdq	%%cl, %%rdx, %%rax	\n\t"	\
		"movq	%%rax, 8(%0)		\n\t"	\
		"movq	24(%0), %%rax		\n\t"	\
		"shrdq	%%cl, %%rax, %%rdx	\n\t"	\
		"movq	%%rdx, 16(%0)		\n\t"	\
		"shrq	%%cl, 24(%0)		\n\t"	\
		:					\
		: "r" (A), "c" (k)			\
	);
	return;
}
