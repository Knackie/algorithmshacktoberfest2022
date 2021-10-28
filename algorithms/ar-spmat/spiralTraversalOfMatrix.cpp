
#include<bits/stdc++.h>
using namespace std;


int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int top=0,down=n-1,left=0,right=m-1;
       int d=0;
       int counter=0;
       while(top<=down && left<=right)
       {
           for(int i=left;i<=right && counter<k;i++)
           {
               if(counter==k-1)
               return a[top][i];
               counter++;
           }
           top+=1;
           for(int i=top;i<=down && counter<k;i++)
           {
               if(counter==k-1)
               return a[i][right];
               counter++;
           }
           right-=1;
           for(int i=right;i>=left && counter<k;i--)
           {
               if(counter==k-1)
               return a[down][i];
               counter++;
           }
           down-=1;
           for(int i=down;i>=top && counter<k;i--)
           {
               if(counter==k-1)
               return a[i][left];
               counter++;
           }
           left+=1;
       }
    }
    
