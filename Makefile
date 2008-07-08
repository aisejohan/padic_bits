all:
	cp add_trivial.s.gcc432 add.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native add.s
	cp mul_trivial.s.gcc432 mul.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native mul.s
	cp val_trivial.s.gcc432 val.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native val.s
	cp neg_trivial.s.gcc412 neg.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native neg.s
	cp div_trivial.s.gcc412 div.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native div.s
	gcc -Wall -pedantic -std=c99 -c -O3 -march=native main.c
	gcc -o tester add.o mul.o val.o neg.o div.o main.o

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
	gcc -Wall -pedantic -std=c99 -c -O3 main.c
	gcc -o tester add.o mul.o val.o neg.o div.o main.o

clean:
	rm -f tester
	rm -f *.o
	rm -f *.s
