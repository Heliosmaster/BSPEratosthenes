#include "BSPedupack/bspedupack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "seqSieve.c"

  int P;
  int N;
  int q;

void parSieve(N){
  bsp_begin(P);
  int s = bsp_pid();  
  int p = bsp_nprocs();
  double time0,time1,time2;
  /*
  if (s==0){
    printf("Enter a bound for primes:\n"); fflush(stdout);
    scanf("%d",&N);
    } */
  bsp_push_reg(&N,SZINT);
  bsp_sync();
  bsp_get(0,&N,0,&N,SZINT);  
  bsp_sync();
  bsp_pop_reg(&N);
  
  time0 = bsp_time();
  
  int q = floor(sqrt(N));
  seqSieve(q);
  time2 = bsp_time();
  
  double v = N-q;
    
  int m = ceil(v/(2*p));  
  
  // printf("%d: to perform the sequential part up to %d i needed %.6lf sec\n",s,q,time2-time1);
    
  int *localList;
  localList = vecalloci(m);

  int i=0;
  int j=2*m*s+q+1;  
  
  if(j%2 == 0) j++;
  
  //  printf("%d: from %d to %d\n",s,j,2*m*(s+1)+q-1);

while(i<m && j<=N){
    localList[i] = j;
    i++;
    j+=2;

  } 
  
  while(i<m){
    localList[i]=0;
    i++;
  }
  /* 
  if(s==0){
      for(i=0;i<count;i++) printf("%d: primes[%d]=%d\n",s,i,primes[i]);  
    }
  for(i=0;i<m;i++)printf("%d: localList[%d]=%d\n",s,i,localList[i]);
  */
  int count2 =0;
  
  /*  
  for(i=1;i<count;i++){
    printf("I'm considering multiples of %lld\n",primes[i]);
    for(j=0;j<m;j++){
      if(localList[j]==0) continue;
      if(localList[j]%primes[i]==0){
        printf("%d: I'm removing ll[%d]=%d\n",s,j,localList[j]);
        localList[j]=0;
      }
    }
    }*/
    
    // i=1 because it skips multiples of 2    
    int k;    
    
    for(i=1;i<count;i++){
      k = primes[count-i];
       if (2*m*(s+1)+q < k*k) {
        // printf("%d: skipped %d because of %d\n",s,k,k*k);
        continue;
        }
      // printf("I'm considering multiples of %d\n",k);
      for(j=0;j<m;j++){
        // printf("%d: Checking %d\n",s,localList[j]);
        if(localList[j]==0) continue;
        if(localList[j]%k==0) {
          //printf("%d: Ha! I found that the first index is %d\n",s,j);
          break;
        }
      }
      while(j<m){
        //if (s==0) printf("%d: I am removing ll[%d]=%d\n",s,j,localList[j]);
       localList[j] = 0;
        j+=k;
      }
    } 
    
  
  for(j=0;j<m;j++){
    if (localList[j] !=0) count2++;
  }
  
  if (s==0){
    count2 += count;
  }
  /* 
  int *finalList;
  finalList = vecalloci(count2);
  //  int finalList[count2];
  j =0;
  
  if (s==0){
    for(i=0;i<count;i++){
      finalList[j] = primes[i];
      j++;
    }
  }
  
  i =0;
    
  while(i<m){
    if (localList[i]!=0){
      finalList[j] = localList[i];
      j++;
    }
    i++;
  }
  */
  int *globalCount;
  
  globalCount = vecalloci(p);
  bsp_push_reg(globalCount,p*SZINT);
  bsp_sync();
  int t;
  for(t=0;t<p;t++){
    bsp_put(t,&count2,globalCount,s*SZINT,SZINT);
  }

  bsp_sync();
  
  int sum = 0;
  for(i=0;i<p;i++) sum+=globalCount[i];
  /*  
  int *result;
  result = vecalloci(sum);
  bsp_push_reg(result,sum*SZINT);
  bsp_sync();
  
  int g=0;
  
  for(i=0;i<s;i++) g+=globalCount[i];
  
  
   for(t=0;t<p;t++){
    bsp_put(t,&finalList,result,g*SZINT,count2*SZINT);
  }
  bsp_sync();
  */
  time1 = bsp_time();
  // for(i=0;i<sum;i++) printf("proc: %d: result[%d]=%d\n",s,i,result[i]);
  
  //  for(i=0;i<p;i++) printf("proc %d: globalCount[%d] = %d\n",s,i,globalCount[i]);
  //  for(i=0;i<count2;i++) printf("Proc %d: l[%d]=%d\n",s,i,finalList[i]);
  //  for(i=0;i<count;i++) printf("Proc %d: smallList[%d]=%d\n",s,i,primes[i]);
  
  if (s==0){
    printf("We found %d primes in parallel.\n",sum);
    printf("To perform the sequential part up to %d we needed %.6lf sec\n",q,time2-time0);
  }
  printf("%d: It took %.6lf seconds.\n",s,time1-time0);
  bsp_pop_reg(globalCount);
  // vecfreei(finalList);
  //  bsp_pop_reg(result);
  //  vecfreei(result);
  vecfreei(localList);
  vecfreei(globalCount);
  bsp_end();
}

int main(int argc, char **argv){

    bsp_init(parSieve, argc, argv);  

    /* sequential part */
    P = atoi(argv[1]);
    //printf("argv[1]=%d\n",atoi(argv[1]));
    //    printf("argv[2]=%d\n",atoi(argv[2]));
    /*    printf("How many processors do you want to use?\n"); fflush(stdout);
    scanf("%d",&P);*/
    if (P > bsp_nprocs()){
        printf("Sorry, not enough processors available.\n"); fflush(stdout);
        exit(1);
    }
    
    N = atoi(argv[2]);
    
    /* SPMD part */
     parSieve(N);

    /* sequential part */
    free(primes);
    exit(0);

}
