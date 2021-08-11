primetest: prime.o primetest.o boolean.o
	gcc -o primetest primetest.o boolean.o prime.o

prime.o: prime.c prime.h
	gcc -c prime.c

primetest.o: primetest.c prime.h
	gcc -c primetest.c

boolean.o: boolean.h boolean.c
	gcc -c boolean.c
