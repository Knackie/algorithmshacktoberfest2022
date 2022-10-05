    #include <stdio.h>  

    // function to get maximum element from the given array  
    int getMax(int a[], int n) 
    {  
        int max = a[0];  
        for (int i = 1; i < n; i++)  
            if (a[i] > max)  
                max = a[i];  
        return max;  
    }  
    void bucket(int a[], int n) 
    {  
        int max = getMax(a, n); 
        int bucket[max], i; 

        for (int i = 0; i <= max; i++)  
            bucket[i] = 0;  

    for (int i = 0; i < n; i++)   
        bucket[a[i]]++;   
    for (int i = 0, j = 0; i <= max; i++)  
    {  
        while (bucket[i] > 0)  
        {  
            a[j++] = i;  
            bucket[i]--;  
        }  
    }  
    }

    int main()  
    {  
        int arr[] = {34, 2, 48, 97, 75, 19, 70, 8};  
        int n = sizeof(arr) / sizeof(arr[0]); // n is the size of array 

        printf("Unsorted Array:- ");
        for (int i = 0; i < n; ++i)  
            printf("%d  ", arr[i]);

        bucket(arr, n);  
        printf("\nSorted Array");  
        for (int i = 0; i < n; ++i)  
            printf("%d  ", arr[i]); 
            return 0;
    }  