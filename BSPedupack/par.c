#include "bspedupack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "seq.c"

  int P;
  int N;
  int q;

void parSieve(){
  bsp_begin(P);
  int s = bsp_pid();  
  int p = bsp_nprocs();
  if (s==0){
     printf("Enter a bound for primes:\n"); fflush(stdout);
     scanf("%d",&N);
  }  
  bsp_push_reg(&N,SZINT);
  bsp_sync();
  bsp_get(0,&N,0,&N,SZINT);  
  bsp_sync();
  bsp_pop_reg(&N);
  
  int m = N/p;
  
  int localList[m];
  int i=0;
  int j=m*s+1;
  

  while(i<m){
    localList[i] = j;
    i++;
    j++;
  }
  
  int q = floor(sqrt(N));
  seqSieve(q);
  
  int count2 =0;
  
  for(i=0;i<count;i++){
    for(j=0;j<m;j++){
      if(localList[j]%primes[i]==0){
        localList[j]=0;
      }
    }
  }
  
  for(j=0;j<m;j++){
    if (localList[j] !=0) count2++;
  }
  
  int *globalCount;
  
  globalCount = vecalloci(p);
  bsp_push_reg(globalCount,p*SZINT);
  bsp_sync();
  int t;
  for(t=0;t<p;t++){
    bsp_put(t,&count2,globalCount,s*SZINT,SZINT);
  }
  bsp_sync();
  
  printf("%d: count2=%d\n",s,count2);
  
  int sum = 0;
  for(i=0;i<p;i++) sum+=globalCount[i];
  
  //int *result;
  //  result = vecalloci(sum);
  
  
  // for(i=0;i<p;i++) printf("proc %d: globalCount[%d] = %d\n",s,i,globalCount[i]);
  //  for(i=0;i<m;i++) printf("Proc %d: l[%d]=%d\n",s,i,localList[i]);
  //  for(i=0;i<count;i++) printf("Proc %d: smallList[%d]=%d\n",s,i,primes[i]);
  bsp_pop_reg(globalCount);
  vecfreei(globalCount);
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