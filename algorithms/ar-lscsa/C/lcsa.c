#include<stdio.h>

int lcsa(int a[], int s)
{
    int largest_sum=a[0];
    for(int i=0;i<s;i++)
    {
        int sum=0;
        for(int j=i;j<s;j++)
        {
            sum=sum+a[j];
            if(sum>largest_sum)
                largest_sum=sum;
        }
    }
    return largest_sum;
}

int main()
{
    int size;
    printf("What is the lenght of your array\n");
    scanf("%d",&size);
    int array[size];
    printf("Type your elements one by one\n");
    for(int i=0;i<size;i++)
        scanf("%d",&array[i]);
    printf("The largest sum of contiguous subarray for the given array is : %d \n", lcsa(array, size));
    return 0;
}
