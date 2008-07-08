all:
	cp add_trivial.s.gcc432 add.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native add.s
	cp mul_trivial.s.gcc432 mul.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native mul.s
	cp valuation_trivial.s.gcc432 val.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native val.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native main.c
	gcc -o tester add.o mul.o val.o main.o

clean:
	rm -f tester
	rm -f *.o
	rm -f *.s