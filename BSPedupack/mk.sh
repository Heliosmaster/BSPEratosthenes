#! /bin/bash
 mpicc -o par_sieve par.c bspedupack.c -lbsponmpi -lm
 mpirun -np 4 par_sieve
#mpicc -c -o par.o par.c
#mpicc -c -o bspedupack.o bspedupack.c
#mpicc -o par_sieve par.o bspedupack.o -lbsponmpi -lm