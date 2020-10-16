public class LongestCommonSubsequence {
    int lcs( String string1, String string2 ) {
        char[] s1 = string1.toCharArray();
        char[] s2 = string2.toCharArray();

        int m = s1.length;
        int n = s2.length;

        int dp[][] = new int[m+1][n+1]; 

        for ( int i=0; i<=m; i++ ) { 
            for ( int j=0; j<=n; j++ ) { 
                if (i == 0 || j == 0) {
                    dp[i][j] = 0; 
                }
                else if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } 
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                } 
            } 
        }

        int idx = dp[m][n];
    
        char[] lcs = new char[idx + 1]; 
        lcs[idx] = '\u0000';

        // Backtrack
        int i = m; 
        int j = n; 
        while (i > 0 && j > 0) { 
            if (s1[i-1] == s2[j-1]) {
                lcs[idx - 1] = s1[i-1];  
                   
                i--;  
                j--;  
                idx--;      
            } 
            else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }

        System.out.print("LCS of " + string1 + " and " + string2 + " is "); 
        for ( int k=0; k <= dp[m][n]; k++ ) {
            System.out.print(lcs[k]);
        }

        System.out.println();

        return dp[m][n];
    }

    int max(int a, int b) { 
        return (a > b)? a : b; 
    } 

    public static void main( String[] args ) { 
        LongestCommonSubsequence lcs = new LongestCommonSubsequence(); 
        String s1 = "AGGTAB"; 
        String s2 = "GXTXAYB"; 

        System.out.println("Length of LCS is" + " " + lcs.lcs( s1, s2 )); 
    } 
}