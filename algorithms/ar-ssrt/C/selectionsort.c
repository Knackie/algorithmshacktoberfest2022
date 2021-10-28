#include<stdio.h>

void swap(int n,int arr[n], int t1, int t2){
	int temp;
	temp = arr[t1];
	arr[t1] = arr[t2];
	arr[t2] = temp;
}

int main()
{
int n,iter,i,j,minimum;
scanf("%d", &n);
int arr[n];
for(i=0;i<n;i++)
	scanf("%d", &arr[i]);
for(i=0;i<n-1;i++){
	minimum = i;
	for(j=i+1;j<n;j++){
		if(arr[j]<arr[minimum]){
			minimum = j;
		}
	}
	swap(n,arr,minimum,i);
}
for(i=0;i<n;i++)
	printf("%d ", arr[i]);
}