#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;

}
int Selection_Sort(int arr[],int n)
{
   int i,j,min=arr[0];
   for(i=0;i<n-1;i++)
   {
   	min=i;
   	 for(j=i+1;j<n;j++)
   	 {
   		if(arr[j]<arr[min])
   		{
   			min=j;
   			
   		}
   		
   	
    }
    swap(&arr[min],&arr[i]);
 }
}
int dispaly(int arr[],int n)
{
for(int i=0;i<n;i++)
	cout<<arr[i]<<" "<<endl<<endl;
}
int main()
{
	int SIZE;
	
	cout<<"Enter size of an aaray"<<endl;
	cin>>SIZE;
	int arr[SIZE];
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Enter elements for an array"<<endl;
	for(int i=0;i<SIZE;i++)
	{
		cin>>arr[i];
	}
	cout<<"Unsorted Array elements are:"<<endl;
	for(int i=0;i<SIZE;i++)
	{
		cout<<arr[i]<<endl;
	}
	
	Selection_Sort(arr,n);
	cout<<"Sorted array elements are:"<<endl;
	dispaly(arr,n);
	return 0;

}
