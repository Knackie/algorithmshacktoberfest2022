#include <stdio.h>
#include <windows.h>
#include <process.h>
void routine(void *a)
{
	int n = *(int *) a;
	Sleep(n);
	printf("%d ", n);
}
void sleepSort(int arr[], int n)
{
	HANDLE threads[n];
	for (int i = 0; i < n; i++)
		threads[i] = (HANDLE)_beginthread(&routine, 0, &arr[i]);
	WaitForMultipleObjects(n, threads, TRUE, INFINITE);
	return;
}

int main()
{
	printf("Enter Number of elements");
	scanf("%d",n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",arr[i]);
	}
	sleepSort (arr, n);
	return(0);
}
