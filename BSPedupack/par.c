#include "bspedupack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "seq.c"

  int P;
  int N;

void parSieve(){
  bsp_begin(P);
  int s = bsp_pid();
  if (s==0){
    int i;
    seqSieve(N);
    for(i=0;i<count;i++){
      printf("%d: %d\n",i,primes[i]);
    }
    }
  bsp_end();
}

int main(int argc, char **argv){

    bsp_init(parSieve, argc, argv);

    /* sequential part */
    printf("How many processors do you want to use?\n"); fflush(stdout);
    scanf("%d",&P);
    if (P > bsp_nprocs()){
        printf("Sorry, not enough processors available.\n"); fflush(stdout);
        exit(1);
    }
    
    printf("Enter a bound for primes:\n"); fflush(stdout);
    scanf("%d",&N);

    /* SPMD part */
     parSieve();

    /* sequential part */
    exit(0);

}