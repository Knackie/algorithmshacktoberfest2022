#include<bits/stdc++.h>

using namespace std;

int modular_exponentiation(int base,int power,int mod)
{
    int result=1;
    while(power>0)
    {
	if(power&1)
	{
	    result=(result*base)%mod;
	}
	base=(base*base)%mod;
	power>>=1;
    }
    return result;	
}

int main()
{
	cout<<modular_exponentiation(2,3,5)<<endl;
}