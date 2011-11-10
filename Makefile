seq:
	gcc -o sieve seq.c -lm
par:
	mpicc -o par_sieve par.c BSPedupack/bspedupack.c -lbsponmpi -lm #-g
all: seq par

