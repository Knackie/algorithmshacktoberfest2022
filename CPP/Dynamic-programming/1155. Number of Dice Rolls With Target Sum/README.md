
<h2><a href="https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/">1155. Number of Dice Rolls With Target Sum</a></h2>
<h3>Medium</h3>
<hr>
<div><p>
You have n dice and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
</p>


<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 1, k = 6, target = 3
<strong>Output:</strong> 1
</pre>
<pre>
You throw one die with 6 faces.
There is only one way to get a sum of 3.
</pre>
  
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 30, k = 30, target = 500
<strong>Output:</strong>  222616187
</pre>
<pre>
The answer must be returned modulo 109 + 7.
</pre>
 

Constraints:
<pre>
1 <= n, k <= 30
1 <= target <= 1000
</pre>
<hr>
 <h2><strong><b>Solution</b></strong></h2>
 <br>
 <pre>
 // unbounbed knapsack with check that if n==0 and and target==0 the ans++;
class Solution {
public:
    int M=1e9+7;
    int dp[31][1001];
    int solve(int n,int k,int tar)
    {
      if(tar==0 && n==0) return 1;
      if(n==0 || tar<0) return 0;
      
      // dp 
      if(dp[n][tar]!=-1) return dp[n][tar];
      
      int ans=0;
      for(int i=1;i<=k;i++)
      {
        
         ans=(ans+solve(n-1,k,tar-i))%M;
      }
      return dp[n][tar]=ans%M; 
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
        
    }
};
          
 </pre>

