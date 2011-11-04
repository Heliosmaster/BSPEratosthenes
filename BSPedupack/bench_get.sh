#! /bin/bash
mpcc -o bench_get bspbench_get.c bspedupack.c -lbsponmpi
./bench_get $1
