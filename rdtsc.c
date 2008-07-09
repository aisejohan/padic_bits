unsigned long my_rdtsc_inline_asm(void )
{
	unsigned long uit;

	__asm__ __volatile__ ("rdtsc	\n\t"	\
		"shl	$32, %%rdx	\n\t"	\
		"or	%%rdx, %%rax	\n\t"	\
		: "=a" (uit)			\
		:				\
		: "rdx");
	return(uit);
}
