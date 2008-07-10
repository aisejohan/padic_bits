all:
	cp add_trivial.asm add.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native add.s
	cp mul_trivial.asm mul.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native mul.s
	cp val_trivial.asm val.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native val.s
	cp neg_trivial.asm neg.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native neg.s
	cp div_trivial.asm div.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native div.s
	cp rdtsc.asm rdtsc.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native rdtsc.s
	cp rshift.asm rshift.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native rshift.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native main.c
	gcc -o tester add.o mul.o val.o neg.o div.o rdtsc.o div_trivial.o rshift.o main.o

older_gcc:
	cp add_trivial.s.gcc432 add.s
	gcc -Wall -pedantic -std=c99 -c -O3 add.s
	cp mul_trivial.s.gcc432 mul.s
	gcc -Wall -pedantic -std=c99 -c -O3 mul.s
	cp val_trivial.s.gcc432 val.s
	gcc -Wall -pedantic -std=c99 -c -O3 val.s
	cp neg_trivial.s.gcc412 neg.s
	gcc -Wall -pedantic -std=c99 -c -O3 neg.s
	cp div_trivial.s.gcc412 div.s
	gcc -Wall -pedantic -std=c99 -c -O3 div.s
	cp rdtsc.s.gcc432 rdtsc.s
	gcc -Wall -pedantic -std=c99 -c -O3 rdtsc.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona div_trivial.c
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona mul_trivial.c
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona div_inline_asm.c
	cp rshift.s.gcc432 rshift.s
	gcc -Wall -pedantic -std=c99 -c -O3 rshift.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona main.c
	gcc -o tester add.o mul.o val.o neg.o div.o rdtsc.o mul_trivial.o div_trivial.o rshift.o div_inline_asm.o main.o

clean:
	rm -f tester
	rm -f *.o
	rm -f *.s
