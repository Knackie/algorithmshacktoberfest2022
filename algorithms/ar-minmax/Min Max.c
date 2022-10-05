#include<stdio.h>

void readArray(int[],int);
void displayArray(int[],int);
void minmaxArray(int[],int);

int main()
{
int n,s ;
int arr[100];
printf("Enter the size of Array: ");
scanf("%d",&n);
printf("Enter the elements of array: \n");
readArray(arr,n);
minmaxArray(arr,n);
}

void readArray(int arr[],int n)
{
int i;
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
}

void displayArray(int arr[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
}

void minmaxArray(int arr[],int n)
{
int min, max,i;
min=max=arr[0];
for(i=1; i<n; i++)
{
if(min>arr[i])
min=arr[i];
if(max<arr[i])
max=arr[i];
}
printf("minimum of array is : %d",min);
printf("\nmaximum of array is : %d",max);
}
