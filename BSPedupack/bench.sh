#! /bin/bash
mpcc -o bench bspbench.c bspedupack.c -lbsponmpi
./bench 32
