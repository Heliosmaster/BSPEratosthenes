#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  int m = 100;
  if(argc > 1) m = atoi(argv[1]);
  
  int N = m+1;
  
  int arr[N];
  int out[N];
  
  int i;
  
  for (i=0;i<=N;i++) arr[i] = i;

  int j;
  
  for(j=2;j<=N;j++){
    if (arr[j]==0) continue;
    else {
      for(i=2;j*i<=N;i++){
        arr[i*j] = 0;
      }
    }
  }
  
  for(i=2;i<=N;i++){    
    if (arr[i] != 0) printf("%d ",i);
  }
   
  printf("\n");
  
  exit(1);
  
}