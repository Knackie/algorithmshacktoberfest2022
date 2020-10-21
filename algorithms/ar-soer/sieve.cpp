#include<bits/stdc++.h>
using namespace std;
// Sieve of Eratosthenes is a method to find whether a number is prime or not in O(1) time
bool is_prime[1000001];
void sieve()
{
    int MaxN = 1000000;
    for (int i = 0; i <= MaxN; i++)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0; //number 0 and 1 is not prime we know that
    for (int i = 2; i * i <= MaxN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MaxN; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }

}
int main()
{

    sieve();//preprocessing
    //enter range
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int start, end; cin >> start >> end;
    for (int i = start; i <= end; i++)
    {
        if (is_prime[i])
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}

input: 1 10
output: 2 3 5 7
