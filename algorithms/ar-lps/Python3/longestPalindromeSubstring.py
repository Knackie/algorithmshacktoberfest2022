s = input()
dp = [[False]*len(s) for _ in range(len(s))]
longest = ''
for i in range(len(s)):
    for j in range(i+1):
        if s[i] == s[j] and ((i+1-j) <= 3 or dp[i-1][j+1]):
            dp[i][j] = True
            if i+1-j > len(longest):
                longest = s[j:i+1]
print(longest)