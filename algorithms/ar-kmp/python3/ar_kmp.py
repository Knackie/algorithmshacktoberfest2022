'''
    The following code implements Knuth-Morris-Prat algorithm for pattern matching.
    The algorithm is implemented in python3.
    Runtime complexity: O(n+m)
    Space complexity: O(n+m)
    where n is the length of the text and m is the length of the pattern.
'''


'''
  prefixFunction - 
    Calculates the length of the longest suffix of the pattern that is also a prefix.
    Since the prefix contains the pattern itself, ending with a '#' character,
    a match is found when length of the longest suffix is equal to the length of the pattern.
    Returns the start index of the pattern in the text (is match found) or -1 (if no match found).
'''

def prefixFunction(str, m):
    n = len(str)
    lps = [0]*(n+1)
    lps[0] = -1
    i, j = 1, 0

    while i < n:
        while j != -1 and str[i] != str[j]:
            j = lps[j]

        j += 1
        i += 1
        lps[i] = j

        if lps[i] == m:
            return i-2*m

    return -1


'''
  findPattern -
    Calls the prefix function with appropiate parameters(pattern + '#' + text and length of the pattern).
    Returns the start index of the pattern in the text ( is match found) or -1 (if no match found).
'''

def findPattern(text, pattern):
    s = pattern + "#" + text
    return prefixFunction(s, len(pattern))


print(findPattern("pqrst", "qrs"))
print(findPattern("pqrst", "st"))
print(findPattern("pqrst", "p"))
print(findPattern("pqrst", "pqast"))
