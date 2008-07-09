/*
 *	basis.c
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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "scalar.h"


void print4(unsigned long *a)
{
	printf("%lu + %lu*2^64 + %lu*2^128 + %lu*2^192",
						a[0], a[1], a[2], a[3]);
}

void set4_C(unsigned long *A, unsigned long *B)
{
	A[0] = B[0];
	A[1] = B[1];
	A[2] = B[2];
	A[3] = B[3];
}

void chop_C(unsigned long *couple, unsigned long a)
{
	couple[0] = (a << 32) >> 32;
	couple[1] = a >> 32;
}

void add_C(unsigned long *triple, unsigned long a, unsigned long b)
{
	unsigned long temp;
	unsigned long ac[2], bc[2], tempc[2];

	chop_C(ac, a);
	chop_C(bc, b);
	temp = ac[0] + bc[0];
	chop_C(tempc, temp);
	triple[0] = tempc[0];
	temp = tempc[1] + ac[1] + bc[1];
	chop_C(tempc, temp);
	triple[1] = tempc[0];
	triple[2] = tempc[1];
}

void add4_C(unsigned long *S, unsigned long *A, unsigned long *B)
{
	unsigned long couple[2];
	unsigned long triple[3];
	unsigned long s[8];
	
	add_C(triple, A[0], B[0]);
	s[0] = triple[0];
	s[1] = triple[1];
	s[2] = triple[2];
	add_C(triple, A[1], B[1]);
	s[2] += triple[0];
	s[3] = triple[1];
	s[4] = triple[2];
	add_C(triple, A[2], B[2]);
	s[4] += triple[0];
	s[5] = triple[1];
	s[6] = triple[2];
	add_C(triple, A[3], B[3]);
	s[6] += triple[0];
	s[7] = triple[1];
	chop_C(couple, s[2]);
	s[2] = couple[0];
	s[3] += couple[1];
	chop_C(couple, s[3]);
	s[3] = couple[0];
	s[4] += couple[1];
	chop_C(couple, s[4]);
	s[4] = couple[0];
	s[5] += couple[1];
	chop_C(couple, s[5]);
	s[5] = couple[0];
	s[6] += couple[1];
	chop_C(couple, s[6]);
	s[6] = couple[0];
	s[7] += couple[1];
	S[0] = s[0] + (s[1] << 32);
	S[1] = s[2] + (s[3] << 32);
	S[2] = s[4] + (s[5] << 32);
	S[3] = s[6] + (s[7] << 32);
}

void div4_C(unsigned long *A, unsigned int k)
{
	A[0] = (A[0] >> k) | (A[1] << (64 - k));
	A[1] = (A[1] >> k) | (A[2] << (64 - k));
	A[2] = (A[2] >> k) | (A[3] << (64 - k));
	A[3] = A[3] >> k;
}

void rand4_C(unsigned long *A)
{
	A[0] = (unsigned long) rand() + ((unsigned long) rand() << 1) + ((unsigned long) rand() << 32) + ((unsigned long) rand() << 33);
	A[1] = (unsigned long) rand() + ((unsigned long) rand() << 1) + ((unsigned long) rand() << 32) + ((unsigned long) rand() << 33);
	A[2] = (unsigned long) rand() + ((unsigned long) rand() << 1) + ((unsigned long) rand() << 32) + ((unsigned long) rand() << 33);
	A[3] = (unsigned long) rand() + ((unsigned long) rand() << 1) + ((unsigned long) rand() << 32) + ((unsigned long) rand() << 33);
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
		: "rax", "rdx"				\
	);
	return;
}

unsigned long my_rdtsc_inline_asm_C(void )
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

#define DIV4(a,b)	div4_xmms(a,b)

void test_div4(void )
{
	int i,j,k;
	unsigned long A[4], B[4], C[4];

	k = 33;

	for(j = 1; j <= 1000000; j++) {
		for(i = 0; i <= 3; i++) {
			A[i] = j + i + j*i*j*j;
		}
		set4_C(B, A);
		div4_C(A, k);
		DIV4(B, k);
		neg4(B);
		add4(C, A, B);
		if ((C[0] != 0) | (C[1] != 0) | (C[2] != 0) | (C[3] != 0)) {
			printf("A = "); print4(A); printf("\n");
			printf("B = "); print4(B); printf("\n");
			printf("SUM = "); print4(C); printf("\n");
			return;
		}
	}
	printf("------------------------------------\n");
}

void test_my_rdtsc(unsigned long *A)
{
	unsigned long before, after;
	before = my_rdtsc_inline_asm_C();
	DIV4(A, 21);
	after = my_rdtsc_inline_asm_C();
	printf("before = %lu and after = %lu difference = %lu.\n",
						before, after, after - before);
}

void test_time_div4(void )
{
	int i, j;
	unsigned long A[4], B[4], C[4];
	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 5;
	B[0] = 16;
	B[1] = 2;
	B[2] = 3;
	B[3] = 5;
	C[0] = 11;
	C[1] = 12;
	C[2] = 13;
	C[3] = 15;
	for (j = 1; j <= 10000000; j++) {		
		for (i = 0; i <= 3; i++) {
			B[i] = 7*B[i] + i;
			A[i] = B[i];
		}
		for (i = 1; i <= 129; i++) {
			div4(A, 1);
		}
/*		if (A[3] != D[3]) {
			printf("B = "); print4(B); printf("\n");
			printf("C = "); print4(C); printf("\n");
			printf("A = "); print4(A); printf("\n");
			printf("D = "); print4(D); printf("\n");
			return;
		} */

	}
	print4(A);
	printf("\n");
}	


void test_add4(void )
{
	int i,j;
	unsigned long A[4], B[4], C[4];

	for(j = 1; j <= 1000; j++) {
		for(i = 0; i <= 3; i++) {
			A[i] = j + i;
			B[i] = i*i + j*j + 1;
			C[i] = i*i*i + j*j*j*j;
		}

		printf("------------------------------------\n");
		printf("B = "); print4(B); printf("\n");
		printf("C = "); print4(C); printf("\n");
		add4(A,B,C);
		printf("A = "); print4(A); printf("\n");
		add4_C(A,B,C);
		printf("A = "); print4(A); printf("\n");
		printf("------------------------------------\n");
	}
}

void test_neg4(void )
{
	int i,j;
	unsigned long A[4], B[4], C[4], D[4];

	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 5;
	B[0] = 1;
	B[1] = 2;
	B[2] = 3;
	B[3] = 5;
	C[0] = 11;
	C[1] = 12;
	C[2] = 13;
	C[3] = 15;
	D[0] = 11;
	D[1] = 12;
	D[2] = 13;
	D[3] = 15;
	for (j = 1; j <= 10000000; j++) {
		for (i = 0; i <= 3; i++) {
			A[i] = 7*A[i] + 1;
		}
		B[0] = A[0];
		B[1] = A[1];
		B[2] = A[2];
		B[3] = A[3];
		neg4(B);
		add4(C, A, B);
		if ((C[0] != 0) | (C[1] != 0) | (C[2] != 0) | (C[3] != 0)) {
			printf("A = "); print4(A); printf("\n");
			printf("-A = "); print4(B); printf("\n");
			printf("SUM = "); print4(C); printf("\n");
			return;
		}
/*		printf("A = "); print4(A); printf("\n"); */

	}
}

void test_time_add(void )
{
	int j;
	unsigned long A[4], B[4], C[4], D[4];
	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 5;
	B[0] = 1;
	B[1] = 2;
	B[2] = 3;
	B[3] = 5;
	C[0] = 11;
	C[1] = 12;
	C[2] = 13;
	C[3] = 15;
	for (j = 1; j <= 10000000; j++) {
/*		
		{ 
			int i;
			for (i = 0; i <= 3; i++) {
				B[i] = 7*B[i] + 1;
				C[i] = A[i];
			}
		} */
		add4_C(A,B,C);
		add4_C(D,B,C);
/*		if (A[3] != D[3]) {
			printf("B = "); print4(B); printf("\n");
			printf("C = "); print4(C); printf("\n");
			printf("A = "); print4(A); printf("\n");
			printf("D = "); print4(D); printf("\n");
			return;
		} */

	}
	print4(A);
	printf("\n");
}

	

void test_mul4(void )
{
	int i,j;
	unsigned long A[4], B[4], C[4];

	for(j = 1; j <= 1000; j++) {
		for(i = 0; i <= 3; i++) {
			A[i] = j + i + i*j + j*j*j;
			B[i] = i*i + j*j + 1+j*j*j*j*j*j;
			C[i] = 1 + i*i*i + j*j*j*j;
		}
		
		printf("------------------------------------\n");
		printf("B = "); print4(B); printf(";\n");
		printf("C = "); print4(C); printf(";\n");
		mul4(A,B,C);
		printf("A = "); print4(A); printf(";\n");
		printf("test_OK();\n");
		printf("------------------------------------\n");
	}
}


void test_val4(void )
{
	int i;
	unsigned long j;
	unsigned long A[4];

	A[0] = 1;
	A[1] = 1;
	A[2] = 1;
	A[3] = 1;
	for(i=1; i<=500; i++) {
		A[0] = A[0] << 1 ;
		if (i % 2 == 0) A[1] = A[1] << 1 ;
		if (i % 3 == 0) A[2] = A[2] << 1 ;
		if (i % 4 == 0) A[3] = A[3] << 1 ;
		printf("A = "); print4(A); printf(";\n");
		j = val4(A);
		printf("valuation of A : %lu.\n", j);
	}
}


int main(void )
{
	unsigned long A[4];
	test_div4();
	rand4_C(A);
	test_my_rdtsc(A);
	rand4_C(A);
	test_my_rdtsc(A);
	rand4_C(A);
	test_my_rdtsc(A);
	rand4_C(A);
	test_my_rdtsc(A);
	return(0);
}
