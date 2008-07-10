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
	gcc -o tester add.o mul.o val.o neg.o div.o rdtsc.o rshift.o main.o

older:
	cp add_trivial.asm add.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona add.s
	cp mul_trivial.asm mul.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona mul.s
	cp val_trivial.asm val.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona val.s
	cp neg_trivial.asm neg.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona neg.s
	cp div_trivial.asm div.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona div.s
	cp rdtsc.asm rdtsc.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona rdtsc.s
	cp rshift.asm rshift.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona rshift.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=nocona main.c
	gcc -o tester add.o mul.o val.o neg.o div.o rdtsc.o rshift.o main.o


clean:
	rm -f tester
	rm -f *.o
	rm -f *.s
