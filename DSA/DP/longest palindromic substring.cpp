#include<bits/stdc++.h>
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
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define  uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());
#define all(x)      (x).begin(), (x).end()
#define inp(x) for(ll&i:x) cin>>i;
#define f(i,x,n) for(ll i=x;i<n;i++)
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

 string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        int start=0,len=0;
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;j++,i++)
            {
                if(g==0)
                    dp[i][j]=1;
                if(g==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                if(g>1)
                {
                    if(s[i]==s[j] and dp[i+1][j-1]==1)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                    
                }
                  if(dp[i][j])
            {
                start=i;
                len=j-i+1;
            }
            }
          
        }
        return s.substr(start,len);
    } 
int main()
{
IOS();
FAST;
ll t;
cin>>t;
while(t--)
{
string s;
cin>>s;
string ans=longestPalindrome(s);
cout<<ans<<endl;
}
return 0;
}