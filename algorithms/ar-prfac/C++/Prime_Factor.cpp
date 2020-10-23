#include<bits/stdc++.h>
using namespace std;
void primefactor(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                cout << i << " "; //printing i till n is divisible by i
                n = n / i;

            }
        }

    }

}
int main()
{
    int n; cin >> n;//taking input from user
    primefactor(n);// calling function to print prime factor
    cout << "\n";
    return 0;
}


// input : 100005
// output: 3 5 59 113
