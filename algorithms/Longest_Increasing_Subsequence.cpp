#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {
        vector<int> dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j]<nums[i] && dp[i]<dp[j])
                    dp[i]=dp[j];
            }
            dp[i]++;
            ans=max(ans,dp[i]);
        }
        return ans;

    }
};

int main()
{
    int n;
    //taking size of array
    cin>>n;
    int a[n];

    //inserting elements to the array
    for(int i=0; i<n; i++)
        cin>>a[i];
    Solution ob;
    //calling method longestSubsequence()
    cout << ob.longestSubsequence(n, a) << endl;
}
