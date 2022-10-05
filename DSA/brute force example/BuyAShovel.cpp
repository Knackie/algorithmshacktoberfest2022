#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
#define MOD 1000000007

/* notes
brute force
constructive algorithms 
implementation
math 

The shovel that Policarp chooses is sold for k burles
in his pocket Polycarp has an unlimited number of "10-burle coins" and exactly one coin of r burles
What is the minimum number of shovels Polycarp has to buy so that 
    he can pay for the purchase without any change?
It is obvious that he can pay for 10 shovels without any change 
    (by paying the requied amount of 10-burle coins and not using the coin of r burles)
    But perhaps he can buy fewer shovels and pay without any change. 
    Note that Polycarp should buy at least one shovel.
minimal 
https://codeforces.com/contest/732/problem/A
*/

using namespace std;

int main()
{
    fastio;
    int k, r, br(0), i(0), h(1);;
    bool b = true;
    cin >> k >> r;
    // k = the price of one shovel
    // r = the denomination of the coin in Polycarp's pocket that is different from "10-burle coins".
    while (b)
    {
        //  k·x mod 10 = 0 or k·x mod 10 = r.
        i++;
        h = k * i;
        if (h % 10 == 0 || h % 10 == r)
        {
            b = false;
        }
        
    }
    cout << i << endl;
    
    return 0;
}