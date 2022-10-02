#include  <stdio.h>
  
int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i],j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}
  
  
int main()
{
    int arr[20],n;
    
	printf("Enter the no. of elements to be inserted:");
	scanf("%d",&n);

	for (int i=0; i<n; i++) scanf("%d",&arr[i]);
		
	printf("Array before Sorting : \n");  
    
	for (int i=0; i<n; i++)printf("%d ",arr[i]);
	
    shellSort(arr, n);
	
	printf("\nArray after sorting\n");
	for (int i=0; i<n; i++)printf("%d ",arr[i]);
 
	return 0;
}

