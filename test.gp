t_int(A)=
{
	return(sum(i=1,16,A[i]*2^(64*(i-1))))
}

t_add(A, B, C)=
{
	return(t_int(A) + t_int(B) - t_int(C))
}

t_mul(A, B, C)=
{
	return(t_int(A)*t_int(B) - t_int(C))
}
