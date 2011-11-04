#! /bin/bash
mpicc -c -o par.o par.c -lm -g
mpicc -c -o bspedupack.o bspedupack.c -g
mpicc -o par_sieve par.o bspedupack.o -lbsponmpi -lm -g
#mpicc -o par_sieve par.c bspedupack.c -lbsponmpi -lm -g
mpirun -np 4 par_sieve $1 $2
rm par.o bspedupack.o
#mpicc -c -o par.o par.c
#mpicc -c -o bspedupack.o bspedupack.c
#mpicc -o par_sieve par.o bspedupack.o -lbsponmpi -lm