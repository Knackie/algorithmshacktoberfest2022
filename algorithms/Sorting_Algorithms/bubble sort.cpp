#include<iostream>
using namespace std;

void Bubble_sort(int size,int A[])	//bubble up
{
	for(int i=0; i<size; i++)
	{
	 	int flag=0;
		for(int j=0; j<((size-1)-i); j++)
		{
			if(A[j]>A[j+1])
			{
				int temp=A[j];
			    A[j]=A[j+1];
				A[j+1]=temp;
			    flag=1;	
			}
			
		}
		if(flag==0)
		 {  break;
				
			}
	 
	}
 
		cout<<"\n After sort";
	
		for(int i=0; i<size ; i++)
	{
	cout<<"\t"<<A[i];
		
	}
	
}
int main()
{
	
	int size;
	cout<<"Enter size of arrray: ";
	cin>>size;
	int A[10];
	cout<<"Enter the values of aray\n";
	for(int i=0; i<size ; i++)
	{
		cout<<"value "<<i<<" : ";
		cin>>A[i];
	}
	Bubble_sort(size,A);
	return 0;
}
