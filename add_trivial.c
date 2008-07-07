void add4(unsigned long *S, unsigned long *A, unsigned long *B)
{
	unsigned long s, a, b;
	a = A[0];
	b = B[0];
	s = a + b;
	S[0]=s;
	a = A[1];
	b = B[1];
	s = a + b;
	S[1]=s;
	a = A[2];
	b = B[2];
	s = a + b;
	S[2]=s;
	a = A[3];
	b = B[3];
	s = a + b;
	S[3]=s;
}
