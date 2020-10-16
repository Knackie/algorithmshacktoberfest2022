#include <iostream>
using namespace std;
int index(int *x,int length,int target)
{
	for (int i=0;i<length;i++)
	{
		if (x[i]==target)
		{
			return i;	
		}
	}
	return -1;	
}
int main()
{
	int a[9]={6,4,1,9,4,3,1,0,5};
	int target= 0,length=sizeof(a)/sizeof(int);
	int position =index(a,length,target);  
	if(position==-1)
	cout<<"value not found";
	else
	cout<<"position: "<<position+1;
	
	return 0;
}
