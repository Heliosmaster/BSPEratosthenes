#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int *primes;
int count = 0;

/*

int main(int argc, char **argv){
  int maxInt = 100;
  if(argc > 1)  maxInt = atoi(argv[1]);
  
  seqSieve(maxInt);
  exit(1);
  } */

  int seqSieve(int N){
  
  
  int arr[N];    
  
  int i=0;
  int k=2;
  
  // Populates the array with only the even numbers
  
  while(k<=N){
    arr[i] = k;
    // printf("arr[%d] = %d\n",i,k);
    i++;
    k = 2*i+1;
  }
  
  int len = i;

  int j;
  int bound = ((int)floor(sqrt(2*len+1)))/2;
  int m;
  //  double h = sqrt(N);  
  
  for(i=1;i<=bound;i++)
  {
    m = arr[i];
    if (m == 0) continue;
    for(j=i+m;j<=len;j+=m){
      arr[j] = 0;
    }
    }
    
    //  printf("bound is %d\n",bound);
    //  printf("len is %d\n",len);
  

    for(i=0;i<=len;i++){
      if (arr[i]!=0) {
        count++;
      }
    }
  
  count--;
  primes = (int *) malloc (count * sizeof(int));
  
    j=0;
  
    for(i=0;i<len;i++){
      if(arr[i]!=0){
        primes[j] = arr[i];
        j++;
      }
    }    
    
  }