#! /bin/bash
make par
mpirun -np 4 par_sieve $1 $2
