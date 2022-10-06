#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int SizeOfCabinet(int A[],int n)
{
  long int max = LONG_MIN;
  long int min = LONG_MAX;
  
  for(int i=0;i<n;i++)
  {
    if(max < A[i])
      max = A[i];
    if(min > A[i])
      min = A[i];
  }
  
  return max-min+1;
}

int minOfArray(int A[],int n)
{
  long int min = LONG_MAX;
  
  for(int i=0;i<n;i++)
  {
    if(min > A[i])
      min = A[i];
  }
  
  return min;
  
}

int* PigeonHoleSort(int A[],int n)
{
  int size = SizeOfCabinet(A,n);
  int IndexDecrease = minOfArray(A,n);
  int* Cabinet = (int*) malloc(size * sizeof(int));
  int* sortedItems = (int*) malloc(n * sizeof(int));
  

  for(int i=0;i<size;i++)
  {
    Cabinet[i] = NULL;
  }
  
   //Distribution of the elements
  for(int i=0;i<n;i++)
  {
    Cabinet[A[i]-IndexDecrease] = A[i];
  }
  
  //Recollection of the sorted elements
  int k=0;
  
  for(int i=0;i<size;i++)
  {
  if(Cabinet[i] != NULL)
  {
    sortedItems[k] = Cabinet[i];
    k++;
  }
  }
  return sortedItems;
}
  
int main(void) {
  
  int arr[10] = {100,54,53,52,51,50,49,48,46,45};
  int *p = PigeonHoleSort(arr,10);
  for(int i=0;i<10;i++)
  {
    printf("%d ",p[i]);
  }
  return 0;
}
