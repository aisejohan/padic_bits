static void chop_C(unsigned long *couple, unsigned long a)
{
	couple[0] = (a << 32) >> 32;
	couple[1] = a >> 32;
}

static void add_C(unsigned long *triple, unsigned long a, unsigned long b)
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

void mul4_external_C(unsigned long *S, unsigned long *A, unsigned long *B)
{
	unsigned long t1, t2;
	unsigned long ac[2], bc[2], sc[2];
	unsigned long triple[3];
	unsigned long s[8];

	chop_C(ac, A[0]);
	chop_C(bc, B[0]);
	t1 = ac[0] * bc[0];
	chop_C(sc, t1);
	s[0] = sc[0];
	s[1] = sc[1];
	t1 = ac[0] * bc[1];
	t2 = ac[1] * bc[0];
	add_C(triple, t1, t2);
	s[1] += triple[0];
	s[2] = triple[1];
	s[3] = triple[2];
	t1 = ac[1] * bc[1];
	chop_C(sc, t1);
	s[2] += sc[0];
	s[3] += sc[1];

/*	chop_C(ac, A[0]); */
	chop_C(bc, B[1]);
	t1 = ac[0] * bc[0];
	chop_C(sc, t1);
	s[2] += sc[0];
	s[3] += sc[1];
	t1 = ac[0] * bc[1];
	t2 = ac[1] * bc[0];
	add_C(triple, t1, t2);
	s[3] += triple[0];
	s[4] = triple[1];
	s[5] = triple[2];
	t1 = ac[1] * bc[1];
	chop_C(sc, t1);
	s[4] += sc[0];
	s[5] += sc[1];

/*	chop_C(ac, A[0]); */
	chop_C(bc, B[2]);
	t1 = ac[0] * bc[0];
	chop_C(sc, t1);
	s[4] += sc[0];
	s[5] += sc[1];
	t1 = ac[0] * bc[1];
	t2 = ac[1] * bc[0];
	add_C(triple, t1, t2);
	s[5] += triple[0];
	s[6] = triple[1];
	s[7] = triple[2];
	t1 = ac[1] * bc[1];
	chop_C(sc, t1);
	s[6] += sc[0];
	s[7] += sc[1];

/*	chop_C(ac, A[0]); */
/*	chop_C(bc, B[3]); */
	t1 = A[0] * B[3];
	chop_C(sc, t1);
	s[6] += sc[0];
	s[7] += sc[1];

	chop_C(ac, A[1]);
	chop_C(bc, B[0]);
	t1 = ac[0] * bc[0];
	chop_C(sc, t1);
	s[2] += sc[0];
	s[3] += sc[1];
	t1 = ac[0] * bc[1];
	t2 = ac[1] * bc[0];
	add_C(triple, t1, t2);
	s[3] += triple[0];
	s[4] += triple[1];
	s[5] += triple[2];
	t1 = ac[1] * bc[1];
	chop_C(sc, t1);
	s[4] += sc[0];
	s[5] += sc[1];

/*	chop_C(ac, A[1]); */
	chop_C(bc, B[1]);
	t1 = ac[0] * bc[0];
	chop_C(sc, t1);
	s[4] += sc[0];
	s[5] += sc[1];
	t1 = ac[0] * bc[1];
	t2 = ac[1] * bc[0];
	add_C(triple, t1, t2);
	s[5] += triple[0];
	s[6] += triple[1];
	s[7] += triple[2];
	t1 = ac[1] * bc[1];
	chop_C(sc, t1);
	s[6] += sc[0];
	s[7] += sc[1];

/*	chop_C(ac, A[1]); */
/*	chop_C(bc, B[2]); */
	t1 = A[1] * B[2];
	chop_C(sc, t1);
	s[6] += sc[0];
	s[7] += sc[1];

	chop_C(ac, A[2]);
	chop_C(bc, B[0]);
	t1 = ac[0] * bc[0];
	chop_C(sc, t1);
	s[4] += sc[0];
	s[5] += sc[1];
	t1 = ac[0] * bc[1];
	t2 = ac[1] * bc[0];
	add_C(triple, t1, t2);
	s[5] += triple[0];
	s[6] += triple[1];
	s[7] += triple[2];
	t1 = ac[1] * bc[1];
	chop_C(sc, t1);
	s[6] += sc[0];
	s[7] += sc[1];

/*	chop_C(ac, A[2]); */
/*	chop_C(bc, B[1]); */
	t1 = A[2] * B[1];
	chop_C(sc, t1);
	s[6] += sc[0];
	s[7] += sc[1];

/*	chop_C(ac, A[3]); */
/*	chop_C(bc, B[0]); */
	t1 = A[3] * B[0];
	chop_C(sc, t1);
	s[6] += sc[0];
	s[7] += sc[1];

	chop_C(sc, s[0]);
	s[0] = sc[0];
	s[1] += sc[1];
	chop_C(sc, s[1]);
	s[1] = sc[0];
	s[2] += sc[1];
	chop_C(sc, s[2]);
	s[2] = sc[0];
	s[3] += sc[1];
	chop_C(sc, s[3]);
	s[3] = sc[0];
	s[4] += sc[1];
	chop_C(sc, s[4]);
	s[4] = sc[0];
	s[5] += sc[1];
	chop_C(sc, s[5]);
	s[5] = sc[0];
	s[6] += sc[1];
	chop_C(sc, s[6]);
	s[6] = sc[0];
	s[7] += sc[1];
	chop_C(sc, s[7]);
	s[7] = sc[0];

	S[0] = s[0] + (s[1] << 32);
	S[1] = s[2] + (s[3] << 32);
	S[2] = s[4] + (s[5] << 32);
	S[3] = s[6] + (s[7] << 32);
}
