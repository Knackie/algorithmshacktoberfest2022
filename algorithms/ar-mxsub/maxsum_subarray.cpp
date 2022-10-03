#include<iostream.h>
int main()
{   int n, a[1000],sum=0,csum[1000],max_sum=0;
  //int max_sum=0;
    //int sum=0;
   // int csum[1000];

cout<<"enter the value of n";
    cin>>n;
    cout<<"enter the array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    csum[0]=a[0];
    for(int j=1;j<n;j++)
    {
        csum[j]=csum[j-1]+a[j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {   sum=0;
            sum=csum[j]-csum[i-1];
            if(sum>max_sum)
            {
                max_sum=sum;
            }
        }
    }
cout<<"max sum of the subarray"<<max_sum;
return 0;
}
