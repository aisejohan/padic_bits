void div4(unsigned long *A, unsigned int k)
{
	A[0] = (A[0] >> k) | (A[1] << (64 - k));
	A[1] = (A[1] >> k) | (A[2] << (64 - k));
	A[2] = (A[2] >> k) | (A[3] << (64 - k));
	A[3] = A[3] >> k;
}
