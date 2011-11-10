#! /bin/bash
#cd /home/bissstud/Students11/d.taviani/parAlg/BSPedupack
#mpcc -o bench_get bspbench_get.c bspedupack.c -lbsponmpi
cd ../../../BSPedupack
mpcc -o bench_get bspbench_get.c bspedupack.c -lbsponmpi
./bench_get $1
