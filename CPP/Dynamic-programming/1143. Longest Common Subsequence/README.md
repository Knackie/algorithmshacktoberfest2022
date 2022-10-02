Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Solution:
// normal lcs code
class Solution {
public:
    int dp[1001][1001];
    string s1,s2;
    int LCS(int n, int m)
    {
        //base case
        if(n==0||m==0) return 0;
        //Memozise
        if(dp[n][m]!=-1) return dp[n][m];
        
        //choice diagram
        int ans=0;
        if(s1[n-1]==s2[m-1]) ans= 1+LCS(n-1,m-1);
        else ans=max(LCS(n-1,m),LCS(n,m-1));
        return dp[n][m]=ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        s1=text1,s2=text2;
        return LCS(text1.size(),text2.size()); 
    }
};
