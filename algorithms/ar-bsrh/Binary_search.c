#include<stdio.h>
int binary_search(int arr[],int n,int key)
{
    int low=0,high=n-1;
    int mid=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        return mid+1;
        else if(arr[mid]<key)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}
int main()
{
    int n=0,i,key=0,x=0;
    int arr[10000];
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter elements in sorted order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter key to search: ");
    scanf("%d",&key);
    x=binary_search(arr,n,key);
    if(x==-1)
    printf("Entered Element is not found\n");
    else
    printf("Entered element is at position %d\n",x);
    return 0;
}