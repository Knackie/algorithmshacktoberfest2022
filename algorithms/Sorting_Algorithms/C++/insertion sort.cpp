#include<iostream>
using namespace std;

void Insertion_sort(int n,int A[])
// 2 sides ; (1 sotrted ,unsorted/)
{ int value;
int hole;
for(int i=0; i<n ; i++)
{
value = A[i];
hole=i;

while((hole>0) && (A[hole-1]>value))
{
	A[hole]=A[hole-1];
	hole= hole-1;
	
}
A[hole]=value;
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
	Insertion_sort(size,A);
	return 0;
}
