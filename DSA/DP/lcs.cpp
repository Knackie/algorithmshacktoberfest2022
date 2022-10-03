#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int lcs(string s,string t,int n,int m)
{
      int no=s.size(),mo=t.size();
        string ans;
        int dp[no+1][mo+1];
        for(int i=0;i<=no;i++)dp[i][0]=0;

        for(int i=0;i<=mo;i++)dp[0][i]=0;
        
        for(int i=1;i<=no;i++){
            for(int j=1;j<=mo;j++){
                if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
   
        int i=no,j=mo;
        while(i>0 && j>0){    
            if(s[i-1]==t[j-1]){
                ans+=s[i-1];    
             i--;j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j])j--;   
                else i--;
            }
        }
        reverse (ans.begin(),ans.end());    
        cout<<"Longest Common Subsequence is-";
        cout<<ans<<endl;
        return dp[n][m];
   
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<"Enter string:\n";
    string s,t;
    cin>>s>>t;
 int n=lcs(s,t,s.size(),t.size());
 cout<<"The length of Longest Common Subsequence is- ";
 cout<<n<<endl;
}