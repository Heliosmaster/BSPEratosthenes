#include <math.h>
#define ull unsigned long long

ull *primes;
int count = 0;

ull seqSieve(ull N){
  
  
  ull arr[N];    
  
  ull i=0;
  ull k=2;
  
  // Populates the array with only the even numbers
  
  while(k<=N){
    arr[i] = k;
    // printf("arr[%d] = %d\n",i,k);
    i++;
    k = 2*i+1;
  }
  
  ull len = i;

  ull j;
  ull bound = ((int)floor(sqrt(2*len+1)))/2;
  ull m;
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
  primes = (ull *) malloc (count * sizeof(ull));
  
    j=0;
  
    for(i=0;i<len;i++){
      if(arr[i]!=0){
        primes[j] = arr[i];
        j++;
      }
    }    
    
  }