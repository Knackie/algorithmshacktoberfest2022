#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define MOD 1000000007
#define ll long long
#define pb push_back
/* notes
Polycarp has 26 tasks. Each task is designated by a capital letter of the Latin alphabet.
if Polycarp began to solve some task, then he must solve it to the end, 
without being distracted by another task. 
After switching to another task, Polycarp cannot return to the previous task.

Polycarp can only solve one task during the day. 

https://codeforces.com/contest/1520/problem/A
*/

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        int first = n;
        int last = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                first = min(first, i);
                last = max(last, i);
            }
        }
        for (int i = first; i <= last; i++)
        {
            if (s[i] != c)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
