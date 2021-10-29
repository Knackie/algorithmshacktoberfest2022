#include<bits/stdc++.h>

using namespace std;

int expo(int base,int exp)
{
	int res=1;
	while(exp>0)
	{
		if(exp%2==1)
			res=res*base;
		base=base*base;
		exp=exp/2;
	}
	return res;
}

int main()
{
	cout<<expo(3,3)<<endl;
}