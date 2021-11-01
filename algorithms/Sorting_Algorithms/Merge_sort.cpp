#include<iostream>
using namespace std;

void Merge(int left[],int nl, int right[],int nr , int A[],int n)
{
	 int size_of_left=nl;
	 int size_of_right=nr;
	 int size_of_main=n;
	 
	 int i=0, j=0,k=0;
	 
	 while((i<size_of_left) && (j<size_of_right))
	 {cout<<"in while";
	 	if(left[i]<right[j])
	 	{
	 		A[k]=left[i];
	 		i=i+1;
		 }
		 
		 	else  
	 	{
	 		A[k]=right[j];
	 		j=j+1;
	 		
		 }
		 
		 k=k+1;
		 
	 
	 }
	 //if any indexes are left
	 if(i<size_of_left)
	 {
	 	A[k]=left[i];
	 	i=i+1;
	 	k=k+1;
	 }
	 else if(j<size_of_right)
	 {
	 	A[k]=right[i];
	 	j=j+1;
	 	k=k+1;
	 }
return;	 
}

void Merge_sort(int A[],int siz)
{
	int length= siz;
	if(length<2)
	{
		return;
	}
	int mid=length/2;
	int left[10];
	int right[10];
	
	int nL=mid;
	int nR=mid-length;
	for(int i=0; i<mid; i++)
	{
		left[i]=A[i];
	 
	}
	int x=mid-length;
	int M= mid;
	for(int i=0; i<(x ); i++)
	{
		right[i]=A[M];
		M++;
	 
	}
	Merge_sort(left,nL);
	Merge_sort(right,nR);
	Merge(left,nL, right,nR, A,length);
	
}
void Print(int A[],int n)
{
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
	Merge_sort(A,size);
	Print(A,size);
	return 0;
}
