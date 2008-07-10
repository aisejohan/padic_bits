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

void inv4_C(unsigned long *A)
{
	int e;
	unsigned long B[4], C[4], D[4];

	C[0] = A[0];
	C[1] = A[1];
	C[2] = A[2];
	C[3] = A[3];
	A[0]--;
	if (A[0]) {
		__asm__ ("bsfq %1,%0" : "=r" (e) : "rm" (A[0]));
	} else {
		e = 64;
	}
	neg4_C(A);
	A[0]++; /* No overflow as A[0] is even. Now A = 1 - 2^e x */
	mul4_C(D, C, A);
	set4_C(C, D);
	e = 2*e;

	while (e < 256) {
		set4_C(B, C); /* What is left over */
		B[0]--;
		neg4_C(B);
		B[0]++; /* Now B = 1 - 2^{2e} y */ 
		mul4_C(D, C, B);
		set4_C(C, D); /* C is updated. */
		mul4_C(D, A, B);
		set4_C(A, D); /* A is updated. */
		e = 2*e;
	}
}
