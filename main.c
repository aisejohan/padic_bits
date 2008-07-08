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
	printf("[%lu, %lu, %lu, %lu]", a[0], a[1], a[2], a[3]);
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

void test_time_add(void )
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
	for (j = 1; j <= 10000000; j++) {
/*		for (i = 0; i <= 3; i++) {
			B[i] = 7*B[i] + 1;
			C[i] = A[i];
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
	test_time_add();
	return(0);
}