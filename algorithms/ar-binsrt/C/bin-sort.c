#include <stdio.h>
 
/* Function for bucket sort */
void bin_sort(int array[], int n)
{  
    int num_a, num_b;  
    int count[n]; 
    for (num_a = 0; num_a < n; num_a++)
        count[num_a] = 0;
 
    for (num_a = 0; num_a < n; num_a++)
        (count[array[num_a]])++;
 
    for (num_a = 0, num_b = 0; num_a < n; num_a++)  
        for(; count[num_a] > 0; (count[num_a])--)
            array[num_b++] = num_a;
}   
/* End of Bucket_Sort() */
 
/* The main() begins */
int main()
{
    int array[100], num_a, num; 
 
    printf("Enter the size of array : ");   
    scanf("%d", &num);   
    printf("Enter the %d elements to be sorted:\n",num); 
    for (num_a = 0; num_a < num; num_a++)
        scanf("%d", &array[num_a]); 
    printf("\nThe array of elements before sorting : \n");
    for (num_a = 0; num_a < num; num_a++)
        printf("%d ", array[num_a]);  
    printf("\nThe array of elements after sorting : \n"); 
    bin_sort(array, num); 
    for (num_a = 0; num_a < num; num_a++)
        printf("%d ", array[num_a]);   
    printf("\n");     
    return 0;
}