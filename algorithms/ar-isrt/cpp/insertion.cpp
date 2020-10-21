#include <iostream>
using namespace std;
void insertionsort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int p=A[i];
        while(j>=0 && A[j]>p)
        {
            A[j+1]=A[j];
            j--;

        }
        A[j+1]=p;
    }
}
int main()
{
    int N;
    cout<<"Enter the size:\n";
    cin>>N;
    int *A=new int[N];
    cout<<"Enter the elements:\n";
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    cout<<"Before Sorting:\n";
    for(int i=0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    insertionsort(A,N);
    cout<<"After Sorting\n";
    for(int i=0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
