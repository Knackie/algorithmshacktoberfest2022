#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of element in array - ";
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i< n;i++)
        cin>>arr[i];

    int ans=INT_MAX;
    for(auto x:arr)
    {
        ans=min(x,ans);
    }    
    cout<<"Minimun number is "<<ans<<endl;

    return 0;
}