#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
 
using namespace std;

int findmin(int arr[],int n)
  {
     int s=0;
     for(int i=0;i<n;i++)
     s+=arr[i];
     bool dp[n+1][s+1];
     for(int i=1;i<s+1;++i)
     dp[0][i]=false;
     for(int i=0;i<n+1;++i)
     dp[i][0]=true;
     for(int i=1;i<n+1;i++)
     {
         for(int j=1;j<s+1;j++)
         {
             if(arr[i-1]<=j)
             dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
             else
             dp[i][j]=dp[i-1][j];
         }
     }
     int dif=INT_MAX;
     vector<int> v;
     
     for(int i=0;i<s/2+1;i++)
     {
         if(dp[n][i]==true)
         {
             v.push_back(i);
         }
     }
     for(int i=0;i<v.size();i++)
     {
         dif=min(dif,s-2*v[i]);
     }
     return dif;
  }
	int minDifference(int arr[], int n)  { 
	    
	   return findmin(arr,n);
	} 

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int arr[]={1,5,6,11};
int x=minDifference(arr,4);
cout<<x<<endl;
return 0;
}