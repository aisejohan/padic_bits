#define ffs(count, x)							\
  do {									\
        __asm__ ("bsfq %1,%0\n\t"					\
            "cmovzq %2,%0"						\
            : "=r" (count) : "rm" (x), "rm" ((unsigned long)(64)));	\
  } while(0)

int val4(unsigned long *A)
{
	register unsigned long count;
	unsigned long a;

	a = A[0];
	if (a) {
		__asm__ ("bsfq %1,%0" : "=r" (count) : "rm" (a));
		goto UIT;
	}
	a = A[1];
	if (a) {
		__asm__ ("bsfq %1,%0" : "=r" (count) : "rm" (a));
		count = count + 64;
		goto UIT;
	}
	a = A[2];
	if (a) {
		__asm__ ("bsfq %1,%0" : "=r" (count) : "rm" (a));
		count = count + 128;
		goto UIT;
	}
	a = A[3];
	if (a) {
		__asm__ ("bsfq %1,%0" : "=r" (count) : "rm" (a));
		count = count + 192;
		goto UIT;
	}
	count = 256;
UIT:
	return((int) count);
}
