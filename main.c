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
#include "functions_asm.h"
#include "functions_inline_asm.h"
#include "functions_C.h"
#include <gmp.h>


#define NR_TESTS	100

void test_div4(void )
{
	int j;
	unsigned int k;
	unsigned long A[4], B[4], C[4];

	for(j = 1; j <= 1000000; j++) {
		rand4_C(A);
		k = ((unsigned int) rand()) % 64;
		set4_C(B, A);
		set4_C(C, A);
		div4_C(B, k);
		DIV4(C, k);
		if (!equal4_C(C, B)) {
			printf("A = "); print4_C(A); printf(";\n");
			printf("B = "); print4_C(B); printf(";\n");
			printf("C = "); print4_C(C); printf(";\n");
			printf("and k = %u.\n", k);
			return;
		}
	}
	printf("------------------------------------\n");
}

void test_time_div4(void )
{
	int j;
	unsigned int k;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[4];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {		
		rand4_C(A);
		k = ((unsigned int) rand()) % 64;
		before = my_rdtsc_inline_asm_C();
		DIV4(A, k);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

void test_add4(void )
{
	int j;
	unsigned long A[4], B[4], C[4], D[4];

	for(j = 1; j <= 1000000; j++) {
		rand4_C(A);
		rand4_C(B);
		add4_C(C, A, B);
		ADD4(D, A, B);
		if (!equal4_C(C, D)) {
			printf("A = "); print4_C(A); printf(";\n");
			printf("B = "); print4_C(B); printf(";\n");
			printf("C = "); print4_C(C); printf(";\n");
			printf("D = "); print4_C(D); printf(";\n");
			return;
		}

	}
	printf("------------------------------------\n");
}

void test_time_add4(void )
{
	int j;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[4], B[4], C[4];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {		
		rand4_C(A);
		rand4_C(B);
		rand4_C(C);
		before = my_rdtsc_inline_asm_C();
		ADD4(A, B, C);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

void test_loop_add4(void )
{
	int j;
	unsigned long A[16], B[16], C[16];

	for(j = 1; j <= 2000; j++) {
		rand4_C(A);
		rand4_C(B);
		rand4_C(&(A[4]));
		rand4_C(&(B[4]));
		rand4_C(&(A[8]));
		rand4_C(&(B[8]));
		rand4_C(&(A[12]));
		rand4_C(&(B[12]));
		loop_add4(C, A, B);
		printf("A = "); print16_C(A); printf(";\n");
		printf("B = "); print16_C(B); printf(";\n");
		printf("C = "); print16_C(C); printf(";\n");
		printf("if(valuation(t_add(A,B,C),2) < 1024, error());\n");
	}
}

void test_time_loop_add4(void )
{
	int j;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[16], B[16], C[16];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {
		rand4_C(A);
		rand4_C(B);
		rand4_C(&(A[4]));
		rand4_C(&(B[4]));
		rand4_C(&(A[8]));
		rand4_C(&(B[8]));
		rand4_C(&(A[12]));
		rand4_C(&(B[12]));
		before = my_rdtsc_inline_asm_C();
		loop_add4(C, A, B);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

void test_loop_mul4(void )
{
	int j;
	unsigned long A[16], B[16], C[16];

	for(j = 1; j <= 2000; j++) {
		rand4_C(A);
		rand4_C(B);
		rand4_C(&(A[4]));
		rand4_C(&(B[4]));
		rand4_C(&(A[8]));
		rand4_C(&(B[8]));
		rand4_C(&(A[12]));
		rand4_C(&(B[12]));
		loop_mul4(C, A, B);
		printf("A = "); print16_C(A); printf(";\n");
		printf("B = "); print16_C(B); printf(";\n");
		printf("C = "); print16_C(C); printf(";\n");
		printf("if(valuation(t_mul(A,B,C),2) < 1024, error());\n");
	}
}

void test_time_loop_mul4(void )
{
	int j;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[16], B[16], C[18];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {
		rand4_C(A);
		rand4_C(B);
		rand4_C(&(A[4]));
		rand4_C(&(B[4]));
		rand4_C(&(A[8]));
		rand4_C(&(B[8]));
		rand4_C(&(A[12]));
		rand4_C(&(B[12]));
		before = my_rdtsc_inline_asm_C();
		mul16_C(C, A, B);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

void set_gmp(mpz_t a, unsigned long *A)
{
	int i;
	mpz_t c;

	mpz_init(c);
	mpz_set_ui(a, 0);
	for (i = 0; i <= 15; i++) {
		mpz_set_ui(c, A[i]);
		mpz_mul_2exp(c, c, i*64);
		mpz_add(a, a, c);
	}
	mpz_clear(c);
}


void test_time_gmp_mul4(void )
{
	int j;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[16], B[16];
	mpz_t a, b, c;

	mpz_init(a);
	mpz_init(b);
	mpz_init(c);

	total = 0;
	j = 0;
	while (j < NR_TESTS) {
		rand4_C(A);
		rand4_C(B);
		rand4_C(&(A[4]));
		rand4_C(&(B[4]));
		rand4_C(&(A[8]));
		rand4_C(&(B[8]));
		rand4_C(&(A[12]));
		rand4_C(&(B[12]));
		set_gmp(a, A);
		set_gmp(b, B);
		before = my_rdtsc_inline_asm_C();
		mpz_mul(c, a, b);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);

	mpz_clear(a);
	mpz_clear(b);
	mpz_clear(c);
}




void test_neg4(void )
{
	int j;
	unsigned long A[4], B[4], C[4];

	for (j = 1; j <= 1000000; j++) {
		rand4_C(A);
		set4_C(B, A);
		set4_C(C, A);
		neg4_C(B);
		NEG4(C);
		if (!equal4_C(B, C)) {
			printf("A = "); print4_C(A); printf(";\n");
			printf("B = "); print4_C(B); printf(";\n");
			printf("C = "); print4_C(C); printf(";\n");
			return;
		}
	}
	printf("------------------------------------\n");
}

void test_time_neg4(void )
{
	int j;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[4];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {		
		rand4_C(A);
		before = my_rdtsc_inline_asm_C();
		NEG4(A);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

void test_mul4(void )
{
	int j;
	unsigned long A[4], B[4], C[4], D[4];

	for(j = 1; j <= 1000000; j++) {
		rand4_C(A);
		rand4_C(B);
		mul4_C(C, A, B);
		MUL4(D, A, B);
		if (!equal4_C(C, D)) {
			printf("A = "); print4_C(A); printf(";\n");
			printf("B = "); print4_C(B); printf(";\n");
			printf("C = "); print4_C(C); printf(";\n");
			printf("D = "); print4_C(D); printf(";\n");
			return;
		}
	}
	printf("------------------------------------\n");
}

void test_time_mul4(void )
{
	int j;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[4], B[4], C[4];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {		
		rand4_C(A);
		rand4_C(B);
		rand4_C(C);
		before = my_rdtsc_inline_asm_C();
		MUL4(A, B, C);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

void test_val4(void )
{
	int i, u, e;
	unsigned long j, J;
	unsigned long A[4];

	for (i = 1; i <= 1000000; i++) {
		rand4_C(A);
		for (u = 0; u <= 3; u++) {
			e = ((unsigned int) rand()) % 65;
			A[u] = (e == 64) ? 0 : A[u] << e;
		}
		j = val4_C(A);
		J = VAL4(A);
		if (j != J) {
			printf("A = "); print4_C(A); printf(";\n");
			printf("and j = %lu and J = %lu.\n", j, J);
			return;
		}
	}
	printf("------------------------------------\n");
}

void test_time_val4(void )
{
	int j, u, e;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[4];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {		
		rand4_C(A);
		for (u = 0; u <= 3; u++) {
			e = ((unsigned int) rand()) % 65;
			A[u] = (e == 64) ? 0 : A[u] << e;
		}
		before = my_rdtsc_inline_asm_C();
		VAL4(A);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

void test_inv4(void )
{
	int i;
	unsigned long A[4], B[4], C[4], EEN[4];

	EEN[0] = 1;
	EEN[1] = 0;
	EEN[2] = 0;
	EEN[3] = 0;
	for (i = 1; i <= 1000000; i++) {
		rand4_C(A);
		if (val4_C(A) == 0) {
			set4_C(B, A);
			inv4_C(B);
			mul4_C(C, A, B);
			if (!equal4_C(C, EEN)) {
				printf("A = "); print4_C(A); printf(";\n");
				printf("B = "); print4_C(B); printf(";\n");
				printf("C = "); print4_C(C); printf(";\n");
				return;
			}
		}	
	}
	printf("------------------------------------\n");
}

void test_time_inv4(void )
{
	int j;
	unsigned long before, after;
	unsigned long stats[NR_TESTS];
	unsigned long total;
	unsigned long A[4];

	total = 0;
	j = 0;
	while (j < NR_TESTS) {
		rand4_C(A);
		while (A[0] % 2 == 0) rand4_C(A);
		before = my_rdtsc_inline_asm_C();
		INV4(A);
		after = my_rdtsc_inline_asm_C();
		stats[j] = after - before;
		total += stats[j];
		j++;
	}
	printf("[");
	for (j = 0; j + 1 < NR_TESTS; j++) printf("%lu,", stats[j]);
	printf("%lu]\n", stats[NR_TESTS - 1]);
	printf("Average = %lu.\n", total/NR_TESTS);
}

int main(void )
{
/*	test_loop_mul4();		*/
test_time_gmp_mul4();
	printf("LOOP_ADD4\n");
	test_time_loop_add4();
	printf("LOOP_MUL4\n");
	test_time_loop_mul4();
	test_div4();
	printf("DIV4\n");
	test_time_div4();
	test_add4();
	printf("ADD4\n");
	test_time_add4();
	test_neg4();
	printf("NEG4\n");
	test_time_neg4();
	test_mul4();
	printf("MUL4\n");
	test_time_mul4();
	test_val4();
	printf("VAL4\n");
	test_time_val4();
	test_inv4();
	printf("INV4\n");
	test_time_inv4();
	return(0);
}
