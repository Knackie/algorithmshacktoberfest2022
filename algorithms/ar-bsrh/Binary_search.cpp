#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int n,int key)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
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
    
    cout<<"Enter Number of elements\n";
    int n; scanf("%d",&n);
    int arr[n]; // creating an array to store the data
    // binary search is applicable to only pre-sorted  data
    cout<<"Enter data in sorted order\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter key to search in data\n";
    int key; cin>>key;
    int x=binary_search(arr,n,key);
    if(x==-1)
    {
        cout<<"Element is not present\n";
    }
    else{
        cout<<"Element present at location "<<x<<"\n"; 
    }
    
    return 0;
}