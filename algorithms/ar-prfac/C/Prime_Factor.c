#include<stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);// taking input from user
    for (i = 2; i <= n; i++) // starting from 2 because prime number starts from 2
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                printf("%d ", i);
                n = n / i;

            }
        }

    }
    return 0;
}

// input : 100005
// output: 3 5 59 113
