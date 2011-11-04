#include <math.h>
#define ull unsigned long long

int *primes;
int count = 0;

int seqSieve(int N){
  
  int z = N-N/2;
  int *arr = malloc(z*sizeof(int));
  if(arr==NULL){
    printf("There was a problem allocating memory for the initial array (of size %d MB).\n",z*sizeof(int)/(1024*1024));    
    exit(0);
  }
 
  
  int i=0;
  int k=2;
  
  arr[0]=2;
  // Populates the array with only the even numbers
  
  for(i=1;i<z;i++){
    k = 2*i+1;
    arr[i] = k;
    //  printf("arr[%lld]=%lld\n",i,k);
  }   
  int j;
  int bound = ((int)ceil(sqrt(2*z+1)))/2;  
  int m;
  //  printf("bound:%lld\n",bound);
  
  for(i=1;i<bound;i++)
  {    
    m = arr[i];
    //    printf("Looking for multiples of arr[%lld]=%lld\n",i,m);
    if (m == 0) continue;
     for(j=i*(m+1);j<z;j+=m){
      //printf("Considering arr[%lld]=%lld\n",j,arr[j]);
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
  primes = (int *)malloc(count * sizeof(int));
  if(primes==NULL){
    printf("There was a problem allocating memory for the final array (of size %d MB).\n",count*sizeof(int)/(1024*1024));    
    exit(0);
  }
    
    j=0;
  
    for(i=0;i<z;i++){
      if(arr[i]!=0){
        primes[j] = arr[i];
        j++;
      }
    }
    //  count = (int)j;
    free(arr);
  }