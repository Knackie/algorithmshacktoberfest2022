/*
    The following code implements Knuth-Morris-Prat algorithm for pattern matching.
    The algorithm is implemented in JavaScript.
    Runtime complexity: O(n+m)
    Space complexity: O(n+m)
    where n is the length of the text and m is the length of the pattern.
*/


/*
 * Calculates the length of the longest suffix of the pattern that is also a prefix.
 * Since the prefix contains the pattern itself, ending with a '#' character,
 * a match is found when length of the longest suffix is equal to the length of the pattern.
 * Returns the start index of the pattern in the text (is match found) or -1 (if no match found).
*/
function prefix_function(str, m) {
    n=str.length;
    const lps = [];
    lps[0] = -1;
    i = 1, j = 0;

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
function find_pattern(text, pattern) {
    s = pattern + "#" + text
    return prefix_function(s, pattern.length);
}

console.log(find_pattern("mnop", "mn"));
console.log(find_pattern("mnop", "nop"));
console.log(find_pattern("mnop", "o"));
console.log(find_pattern("mnop", "op"));
