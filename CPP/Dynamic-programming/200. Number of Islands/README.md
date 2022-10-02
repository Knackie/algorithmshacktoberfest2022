
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 
</p>


<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
<strong>Output:</strong> 1
</pre>

 <p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> Input:  grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
<strong>Output:</strong> 3
</pre>


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'. 
<strong>solution</strong>
<pre>
// we have to find all the disconnected components in the graph , use dfs anf increse the count in for loop at any 1 mark all its adjected 1's as visited , then move to next component 

class Solution {
public:
    int vis[301][301]={0}; // visted array
    void dfs(int i,int j,vector<vector<char>> &grid)
    {
        vis[i][j]=1;  
        // the the dfs in all four directions
        if(i-1>=0 && grid[i-1][j]=='1' && vis[i-1][j]==0) 
            dfs(i-1,j,grid); 
        if(j-1>=0 && grid[i][j-1]=='1'  && vis[i][j-1]==0) 
            dfs(i,j-1,grid);
        if(i+1<grid.size() && grid[i+1][j]=='1'  && vis[i+1][j]==0)
            dfs(i+1,j,grid);
        if(j+1<grid[0].size() && grid[i][j+1]=='1'  && vis[i][j+1]==0) 
            dfs(i,j+1,grid);
        
        return ;
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
      int n=grid[0].size(), m=grid.size(),count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
</pre>
