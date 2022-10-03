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
void IOS()
{
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE 
  #endif
}
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
string x,y;
int n=x.size(),m=y.size();
int dp[1001][1001];

 int lcs(string x,string y,int n,int m)
 { if(n==0||m==0) return 0;
  if(dp[n][m]!=-1) return dp[n][m];
  if(x[n-1]==y[m-1])
  return dp[n][m]=1+lcs(x,y,n-1,m-1);
  else
  return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
 return dp[n][m];
 }
 int longestCommonSubsequence(string x, string y) {
        int n=x.size(),m=y.size();
        string s;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(x[i-1]==y[j-1])dp[i][j]=1+dp[i-1][j-1];
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        // for printing longest common subsequence
        int i=n,j=m;
        while(i>0 && j>0){    // if any of this i and j becomes 0 means one string is empty 
            if(x[i-1]==y[j-1]){
                s+=x[i-1];    //if character matches then add that to result string and move diagonally up
                i--;j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j])j--;    // else find the max of up and right position of dp table and move accordingly to up or left
                else i--;
            }
        }
        reverse (s.begin(),s.end());    // reverse the string as we started from last
        cout<<s<<endl;
        return dp[n][m];
    }
int main()
{
IOS();
FAST;
memset(dp,-1,sizeof(dp));
cin>>x>>y;
int ans=longestCommonSubsequence(x,y);
cout<<"Length is:";
cout<<ans<<endl;
return 0;
}