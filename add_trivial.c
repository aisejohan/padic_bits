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
