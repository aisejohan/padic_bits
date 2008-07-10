/*
 *	scalar.h
 *
 * 	Copyright 2006 Johan de Jong
 *
 *	This file is part of Frobenius
 *
 *	Frobenius is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	Frobenius is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Frobenius; if not, write to the Free Software Foundation, 
 *	Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *									*/

void add4_inline_asm_C(unsigned long *S, unsigned long *A, unsigned long *B)
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
		: "rax", "memory");
	return;
}

void div4_inline_asm_C(unsigned long *A, unsigned int k)
{
	__asm__("movq	8(%0), %%rax		\n\t"	\
		"shrdq	%%cl, %%rax, (%0)	\n\t"	\
		"movq	16(%0), %%rdx		\n\t"	\
		"shrdq	%%cl, %%rdx, %%rax	\n\t"	\
		"movq	%%rax, 8(%0)		\n\t"	\
		"movq	24(%0), %%rax		\n\t"	\
		"shrdq	%%cl, %%rax, %%rdx	\n\t"	\
		"movq	%%rdx, 16(%0)		\n\t"	\
		"shrq	%%cl, 24(%0)"			\
		:					\
		: "r" (A), "c" (k)			\
		: "rax", "rdx", "memory");
	return;
}

unsigned long my_rdtsc_inline_asm_C(void )
{
	unsigned long uit;

	__asm__  __volatile__  ("rdtsc			\n\t"	\
				"shl	$32, %%rdx	\n\t"	\
				"or	%%rdx, %%rax	\n\t"	\
				: "=a" (uit)			\
				:				\
				: "rdx");
	return(uit);
}
