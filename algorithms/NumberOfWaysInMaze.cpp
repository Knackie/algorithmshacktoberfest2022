#include <iostream>

using namespace std;

// Number of ways to end in a maze, where you can move only down or right, using recursion

int mat[20][20];

int c = 0;

void numWays(int i, int j, int n)
{
    if (i == n - 1 && j == n - 1)
    {
        c++;
        return;
    }
    // down
    if (i + 1 < n)
    {
        numWays(i + 1, j, n);
    }
    // right
    if (j + 1 < n)
    {
        numWays(i, j + 1, n);
    }
}

int main()
{
    cout << "Enter input:";
    int n;
    cin >> n;

    numWays(0, 0, n);

    cout << "Number of ways from start to end are " << c << endl;
    return 0;
}
