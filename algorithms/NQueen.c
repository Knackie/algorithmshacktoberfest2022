#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int c_board[20], count;
void display(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);
    for (i = 1; i <= n; ++i)
        printf("\t%d", i);
    for (i = 1; i <= n; ++i)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; ++j)
        {
            if (c_board[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
}
int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; ++i)
    {
        if (c_board[i] == column)
            return 0;
        else if (abs(c_board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}
void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; ++column)
    {
        if (place(row, column))
        {
            c_board[row] = column;
            if (row == n)
                display(n);
            else
                queen(row + 1, n);
        }
    }
}

int main()
{
    int n, i, j;
    printf("N-Queens Problem Using Backtracking:");
    printf("\n\nEnter number of Queens:");
    scanf("%d", &n);
    queen(1, n);
    return 0;
}