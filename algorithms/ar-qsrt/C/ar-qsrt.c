#include<stdio.h>

// function to scan the array
void scan_Array(int array_1[], int size)
{
    printf("Enter the elements of the array: \n");
    for(int i=0; i<size; i++)
    {
        printf("Element [%d]: ",i);
        scanf("%d", &array_1[i]);
    }
}

// fucntion to print the array
void print_Array(int array_1[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", array_1[i]);
    }
}

// function to swap the elements
void swap_elements(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}

// function to perform partiition in array
int partition(int array_1[], int p, int r)
{
    int i = p - 1;
    int x = array_1[r];
    for(int j = p; j <= r-1; j++)
    {
        if(array_1[j] <= x)
        {
            i ++;
            swap_elements(&array_1[i], &array_1[j]);
        }
    }
    swap_elements(&array_1[i+1], &array_1[r]);
    return i+1;
}

// function to perform quick sort 
int quick_sort(int array_1[], int p, int r)
{
    if(p < r)
    {
        int q = partition(array_1, p, r);
        quick_sort(array_1, p, q-1);
        quick_sort(array_1, q+1, r);
    }
}

int main()
{
    int size, array_1[100];
    
    // scanning the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // scanning the elements of the array
    scan_Array(array_1, size);

    // assigning the zeroth index to p
    int p = 0;

    // assigning the last index to r
    int r = size-1;

    // printing the scanned array
    printf("\nArray: \n");
    print_Array(array_1, size);
  
    // calling quick_sort function
    quick_sort(array_1, p, r);
  
    // printing the sorted array
    printf("\nSorted Array:\n");
    print_Array(array_1, size);
  
    return 0;
}
