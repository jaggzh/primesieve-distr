all: me

me:
	gcc --std=gnu11 -Wall -o primesieve-distr primesieve-distr.c -O3 \
		-L/usr/local/lib -lprimesieve -Wl,-rpath=/usr/local/lib
	./primesieve-distr

vi:
	vim README.md Makefile primesieve-distr.c
