#include <math.h>
#define ull unsigned long long

ull *primes;
int count = 0;

ull seqSieve(ull N){
  
  ull z = N-N/2;
    
  ull *arr = malloc(z*sizeof(ull));
  if(arr==NULL){
    printf("There was a problem allocating memory for the initial array (of size %lld MB).\n",z*sizeof(ull)/(1024*1024));    
    exit(0);
  }
 
  
  ull i=0;
  ull k=2;
  
  arr[0]=2;
  // Populates the array with only the even numbers
  
  for(i=1;i<z;i++){
    k = 2*i+1;
    arr[i] = k;
  }  
    printf("\n");
  ull len = i;  

  ull j;
  ull bound = ((int)floor(sqrt(2*len+1)))/2;
  ull m;
  //  double h = sqrt(N);  
  
  for(i=1;i<=bound;i++)
  {
    m = arr[i];
    if (m == 0) continue;
    for(j=i+m;j<z;j+=m){
      arr[j] = 0;
    }
    }
    
    //  printf("bound is %d\n",bound);
    //  printf("len is %d\n",len);
  

    for(i=0;i<z;i++){
      if (arr[i]!=0) {
        count++;
      }
    }
  
  //count--;
  primes = (ull *) malloc (count * sizeof(ull));
  if(primes==NULL){
    printf("There was a problem allocating memory for the final array (of size %d MB).\n",count*sizeof(ull)/(1024*1024));    
    exit(0);
  }
  
    j=0;
  
    for(i=0;i<len;i++){
      if(arr[i]!=0){
        primes[j] = arr[i];
        j++;
      }
    }    
    free(arr);
  }