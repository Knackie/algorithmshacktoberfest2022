#include <bits/stdc++.h>
using namespace std;
void longestsubstring(string s)
{
    int mx = 1;
    int start = 0;
    int low, high;
    for (int i = 1; i < s.size(); i++)
    {
        // even length substring
        low = i - 1, high = i;
        while (low >= 0 and high < s.size() and s[low] == s[high])
        {
            low--, high++;
        }
        low++, high--;
        if (s[low] == s[high])
        {
            if (mx < high - low + 1)
            {
                start = low;
                mx = high - low + 1;
            }
        }
        low = i - 1, high = i + 1;
        // odd length substring
        while (low >= 0 and high < s.size() and s[low] == s[high])
        {
            low--;
            high++;
        }
        low++, high--;
        if (s[low] == s[high])
        {
            if (mx < high - low + 1)
            {
                start = low;
                mx = high - low + 1;
            }
        }
    }
    cout << "Length of longest substring is:";
    cout << mx << endl;
    cout << "Substring is:";
    cout<<s.substr(start,mx)<<" ";
    /* while (mx--)
    {
        cout << s[start++];
    } */
}

int main()
{
    string s;
    cin >> s;
    longestsubstring(s);

    return 0;
}