def lcs(string1, string2, get_string=False):
    m = len(string1) 
    n = len(string2) 
   
    dp = [[0]*(n+1) for i in range(m+1)] 
  
    for i in range(1, m+1): 
        for j in range(1, n+1): 
            if string1[i-1] == string2[j-1]: 
                dp[i][j] = dp[i-1][j-1] + 1
            else: 
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) 

    if not get_string:
        return dp[m][n]

    idx = dp[m][n]
    lcs = [""] * (idx + 1) 
    lcs[idx] = "" 
    
    # Backtrack
    i = m 
    j = n 
    while i > 0 and j > 0: 
        if string1[i-1] == string2[j-1]: 
            lcs[idx-1] = string1[i-1] 
            i -= 1
            j -= 1
            idx -= 1
        elif dp[i-1][j] > dp[i][j-1]: 
            i -= 1
        else: 
            j -= 1
    
    return "".join(lcs)

if __name__ == '__main__':
    print(lcs('AGGTAB', 'GXTXAYB'))
    print(lcs('AGGTAB', 'GXTXAYB', get_string=True))