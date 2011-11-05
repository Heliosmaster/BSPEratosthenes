#! /bin/bash
#mpcc -o parbench bspbench.c bspedupack.c -lbsponmpi
cd ..
time ./sieve $1 
