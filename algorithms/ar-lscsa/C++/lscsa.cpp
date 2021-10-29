#include<bits/stdc++.h>

using namespace std;

int largest_sum_cont_subarray(vector<int>&arr)
{
	int ans=0;
	int sum=0;
	for(int i=0;i<arr.size();i++)
	{
		sum+=arr[i];
		if(sum<0)
			sum=0;
		ans=max(ans,sum);
	}

	return ans;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(3);
	cout<<largest_sum_cont_subarray(v);
}