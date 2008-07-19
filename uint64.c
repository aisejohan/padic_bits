#include <stddef.h>
#include <stdio.h>


void test_uint128_add(unsigned long *S, unsigned long *A, unsigned long *B)
{
	__uint64_t a, b, c;
	__uint128_t aa, bb, cc;

	aa = (__uint128_t) A[0] + ((__uint128_t) A[1] << 64);
	bb = (__uint128_t) B[0] + ((__uint128_t) B[1] << 64);
	cc = aa + bb;
	S[0] = (__uint64_t) cc;
	S[1] = (__uint64_t) (cc >> 64);
	return;
}

