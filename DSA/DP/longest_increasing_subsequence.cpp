#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());

const ll mod = 1e9 + 7;
const ll inf = 1e16;
const ll N = 2e5 + 10;
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

    return *max_element(dp.begin(), dp.end());
}
int lengthOfLIS1(vector<int> &nums)
{
    vector<int> sub;
    for (int x : nums)
    {
        if (sub.empty() || sub[sub.size() - 1] < x)
        {
            sub.push_back(x);

        }
        else
        {
            int ind = lower_bound(sub.begin(), sub.end(), x) - sub.begin();
            sub[ind] = x;

            // auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
            // *it = x; // Replace that number with x
        }
    }
    return sub.size();
}
vector<int> pathOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sub, subIndex; // Store index instead of value for tracing path purpose
    vector<int> path(n, -1);   // path[i] point to the index of previous number in LIS
    for (int i = 0; i < n; ++i)
    {
        if (sub.empty() || sub[sub.size() - 1] < nums[i])
        {
            path[i] = sub.empty() ? -1 : subIndex[sub.size() - 1];
            sub.push_back(nums[i]);
            subIndex.push_back(i);
        }
        else
        {
            int idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
            path[i] = idx == 0 ? -1 : subIndex[idx - 1];
            sub[idx] = nums[i];
            subIndex[idx] = i;
        }
    }
    vector<int> ans;
    int t = subIndex[subIndex.size() - 1];
    while (t != -1)
    {
        ans.push_back(nums[t]);
        t = path[t];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x = lengthOfLIS1(a);
    // O(N) best solution
      multiset<int> s;
       for(int i=0;i<n;i++)
       {
             if(i!=0)
             {
                 auto it=s.lower_bound(a[i]);
                 if(it!=s.end())
                 s.erase(it);
             }
           s.insert(a[i]);
       }
      cout<<"Size is:"<<s.size()<<endl;
    // cout << x << endl;
    vector<int> ans=pathOfLIS(a);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    
    return 0;
}