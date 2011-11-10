#! /bin/bash
#mpcc -o parbench bspbench.c bspedupack.c -lbsponmpi
cd ../..
make seq
time ./sieve $1 
