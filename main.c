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

#define add_ssaaaa(sh, sl, ah, al, bh, bl)				\
  __asm__ ("addq %5,%q1\n\tadcq %3,%q0"					\
	   : "=r" (sh), "=&r" (sl)					\
	   : "0"  (ah), "rme" (bh),					\
	     "%1" (al), "rme" (bl))

#define sub_ddmmss(sh, sl, ah, al, bh, bl) 				\
  __asm__ ("subq %5,%q1\n\tsbbq %3,%q0"					\
	   : "=r" (sh), "=&r" (sl)					\
	   : "0" (ah), "rme" (bh),					\
	     "1" (al), "rme" (bl))

/* Found on a blog */
#define blog(l, h, a, b)						\
  __asm__ ("mulq %3" : "=a" (l), "=d" (h) : "a" (a), "rm" (b))

#define udiv_qrnnd(q, r, n1, n0, dx) 					\
  __asm__ ("divq %4"							\
	   : "=a" (q), "=d" (r)						\
	   : "0" (n0), "1" (n1), "rm" (dx))

#define ffs(count, x)							\
  do {									\
        __asm__ ("bsfq %1,%0\n\t"					\
            "cmovzq %2,%0"						\
            : "=r" (count) : "rm" (x), "rm" ((unsigned long)(64)));	\
  } while(0)

#define fls(count, x)							\
  do {									\
        __asm__ ("bsrq %1,%0\n\t"					\
            "cmovzq %2,%0"						\
            : "=r" (count) : "rm" (x), "rm" ((unsigned long)(64)));	\
  } while(0)



void print4(unsigned long *a)
{
	printf("[%lu, %lu, %lu, %lu]", a[0], a[1], a[2], a[3]);
}

#ifdef TOTOOTO
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

		printf("A = "); print4(A); printf("\n");
		printf("B = "); print4(B); printf("\n");
		printf("C = "); print4(C); printf("\n");
		add4(A,B,C);
		printf("A = "); print4(A); printf("\n");
		printf("B = "); print4(B); printf("\n");
		printf("C = "); print4(C); printf("\n");
	}
}
#endif

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




#ifdef TOTOOTO
void test_mul(void )
{
	int i;
	unsigned long A,B,C,D;
	A = 1;
	B = 2;
	C = 3;
	D = 4;
	printf("HERE %lu %lu %lu %lu.\n", A, B, C, D);
	for(i = 1; i <= 100; i++) {
		blog(A, B, C, D);
		printf("HERE %lu %lu %lu %lu.\n", A, B, C, D);
		C = C + i;
		D = i*D + i*i + 1;
	}

}


void test_valuation(void )
{
	int i;
	unsigned long A,B,C,D,E,F;

	A = 2;
	B = 1;
	C = 3;
	D = -1;
	E = 5;
	F = -1;

	printf("HERE %lu %lu %lu %lu %lu %lu.\n", A, B, C, D, E, F);
	for(i=1; i<=100; i++) {
		B = B * i;
		printf("Here B = %lu.\n", B);

		ffs(A, B);
		printf("ffs of B : %lu.\n", A);

		fls(A, B);
		printf("fls of B : %lu.\n", A);
	}
}

void empty(void )
{
	unsigned long A,B,C,D,E,F;

	A = 2;
	B = 1;
	C = 3;
	D = -1;
	E = 5;
	F = -1;

	add_ssaaaa(A, B, C, D, E, F);
	printf("HERE %lu %lu %lu %lu %lu %lu.\n", A, B, C, D, E, F);

	sub_ddmmss(A, B, C, D, E, F);
	printf("HERE %lu %lu %lu %lu %lu %lu.\n", A, B, C, D, E, F);

	udiv_qrnnd(A, B, C, D, E);
	printf("HERE %lu %lu %lu %lu %lu %lu.\n", A, B, C, D, E, F);
}
#endif

int main(void )
{
	test_mul4();
	return(0);
}
