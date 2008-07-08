void neg4(unsigned long *A)
{
	A[0] = -A[0];
	A[1] = -A[1] + (A[0] != 0);
	A[2] = -A[2] + (A[1] != 0);
	A[3] = -A[3] + (A[2] != 0);
}
