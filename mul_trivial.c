void mul4(unsigned long *S, unsigned long *A, unsigned long *B)
{
	unsigned long ml, mh, a, b, c, d;

	a = A[0];
	b = B[0];
	mh = a + b;
	ml = a * b;
	S[0] = ml;
	S[1] = mh;
	b = B[1];
	ml = a * b;
	c = ml;
	d = mh;
	b = B[2];
	ml = b * a;
	S[2] = ml;
	S[3] = mh;
	b = B[3];
	ml = b * a;
	S[1] = S[1] + c;
	S[2] = S[2] + d;
	S[3] = ml + S[3];

	a = A[1];
	b = B[0];
	ml = b * a;
	S[1] = ml + S[1];
	S[2] = mh + S[2];
	b = B[1];
	ml = b, a;
	S[2] = ml + S[2];
	S[3] = mh + S[3];
	b = B[2];
	ml = b * a;
	S[3] = ml + S[3];

	a = A[2];
	b = B[0];
	ml = b, a;
	S[2] = ml + S[2];
	S[3] = mh + S[3];
	b = B[1];
	ml = b * a;
	S[3] = ml + S[3];

	a = A[3];
	b = B[0];
	ml = b * a;
	S[3] = ml + S[3];
}
