#include<bits/stdc++.h>

using namespace std;

int rod_cutting(vector<int>&val)
{
    int n=val.size();
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
	int max_val=INT_MIN;
	for(int j=1;j<=i;j++)
	{
	    max_val=max(max_val,val[j-1]+dp[i-j]);
	}
	dp[i]=max_val;
    }
    return dp[n];	
}

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	cout<<rod_cutting(v);
}