#include "bspedupack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "seq.c"

  int P;  

void parSieve(){
  bsp_begin(P);
  int s = bsp_pid();
  if (s==0){
    printf("Hi! I am processor 0 and I am very pretty!\n");
    } else {
      printf("Hi, i am useless\n");
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

    /* SPMD part */
     parSieve();

    /* sequential part */
    exit(0);

}