#include<iostream>
using namespace std;

void selection_sort(int n,int A[])
{
 
	for(int i=0; i<n-1; i++)
	{
	int	iMin=i;//Enter the index of i we are checking now
		
		for(int j=i+1; j<n ; j++)//check the value of array with the next value (so put j=i+1;)
		{
			if(A[j]<A[iMin])//to check Array's value of the next index is less than tvalue of the present index
			{
				iMin=j; //so put value of j in mininum index variale
			}
		}
		//now swap the value of i index woith the value of minimum index
		int t= A[i];
		A[i]=A[iMin];
		A[iMin]=t ;
	}
	
	cout<<"\n After sort";
	
		for(int i=0; i<n ; i++)
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
	selection_sort(size,A);
	return 0;
}
