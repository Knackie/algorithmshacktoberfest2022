/*
    The following code implements Knuth-Morris-Prat algorithm for pattern matching.
    The algorithm is implemented in C.
    Runtime complexity: O(n+m)
    Space complexity: O(n+m)
    where n is the length of the text and m is the length of the pattern.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Calculates the length of the longest suffix of the pattern that is also a prefix.
 * Since the prefix contains the pattern itself, ending with a '#' character,
 * a match is found when length of the longest suffix is equal to the length of the pattern.
 * Returns the start index of the pattern in the text (is match found) or -1 (if no match found).
*/
int prefix_function(char *str, int m) {
    int n=strlen(str);
    int *lps = (int *)malloc((n+1) * sizeof(int));
    lps[0] = -1;
    int i = 1, j = 0;

    while(i<n)
    {
        while(j != -1 && str[i]!=str[j])
            j = lps[j];
        j++, i++;
        lps[i] = j;

        if(lps[i] == m)
            return i-2*m;
    }

    return -1;
}

/*
 * Calls the prefix function with appropiate parameters (pattern + '#' + text and length of the pattern).
 * Returns the start index of the pattern in the text (is match found) or -1 (if no match found).
*/
int find_pattern(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    char *s = (char *)malloc(sizeof(char) * (n + m + 1));
    for(int i=0; i<m; ++i)
        s[i] = pattern[i];
    s[m] = '#';
    for(int i=0; i<n; ++i)
        s[m+1+i] = text[i];
    
    return prefix_function(s, m);
}

int main()
{
    printf("%d\n", find_pattern("abcd", "abcd"));
    printf("%d\n", find_pattern("abcd", "abc"));
    printf("%d\n", find_pattern("abcd", "bcd"));
    printf("%d\n", find_pattern("abcd", "bacd"));

    return 0;
}
