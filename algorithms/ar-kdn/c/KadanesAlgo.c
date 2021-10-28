#include<stdio.h>
#include<math.h>

int max(int a1, int a2){
   if(a1>a2)
      return a1;
   return a2;
}

int kadanes (int array[],int length) {
   int highestMax = 0;
   int currentElementMax = 0;
   for(int i = 0; i < length; i++){
      currentElementMax =max(array[i],currentElementMax + array[i]) ;
      highestMax = max(highestMax,currentElementMax);
   }
   return highestMax;
}

int main() {
   printf("Enter the array length: ");
   int l;
   scanf("%d", &l);
   int arr[l];
   printf("Enter the elements of array: ");
   for (int i = 0; i < l; i++) {
      scanf("%d", &arr[i]);
   }
   
printf("The Maximum Sum is: %d\n", kadanes(arr,l));
   return 0;
}