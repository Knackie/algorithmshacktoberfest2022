/**
 * @file matrix_chain.c
 * @author https://github.com/ShouryaBrahmastra
 * @brief
 * You are given N number of matrices along with the dimensions of each one.
 * Your task is to find the minimum scalar multiplication using dynamic programming.
 * In the input section, the first line provides the number of matrices followed by
 * their dimensions of N+1 values separated by a space in the next line.
 * In the output section,
 * Display cost matrix
 * Matrix order table
 * Ordering of the matrices with proper  parenthesization
 * Optimal scalar cost
 *
 * Sample Input
 * 4
 * 10 100 20 5 80
 *
 * Sample output
 * 0 20000 15000 19000
 * 0 10000 50000
 * 0 8000
 * 0
 *
 * 1 1 3
 * 2 3
 * 3
 *
 * ((A1(A2 A3))A4)
 * 19000
 *
 * first we are taking the number of matrix input from the user
 * then we are taking 1 more than the input matrix as per demand of the question
 * and then we are calling the matrixchain function to calculate the matrix cost
 * and optimization using the matrix diagonal memory storage.
 * Once we get that if the cost is less than the previous cost we initialize it
 *
 * @version 0.1
 * @date 2022-06-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

void matrixchain(int n, int *m, int **c, int **k)
{
    int i, cos, p, q, minindex, minvalue, cost;
    int max = 99999;
    for (i = 1; i < n; i++)
    {
        c[i][i] = 0;
    }
    cos = 1;

    for (i = 1; i < n; i++)
    {
        p = 1;
        q = 1;
        while (q < n)
        {
            q = p + cos;
            c[p][q] = max;
            for (int x = p; x < q; x++)
            {
                cost = c[p][x] + c[x + 1][q] + (m[p - 1] * m[x] * m[q]);

                if (cost < c[p][q])
                {
                    c[p][q] = cost;
                    k[p][q] = x;
                }
            }
            p++;
        }
        cos++;
    }
}

void printcost(int **c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

void index_print(int **k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", k[i][j]);
        }
        printf(" \n");
    }
}

void parenthesis(int **k, int i, int j)
{
    if (i == j)
    {
        printf("A%d ", i);
    }
    else
    {
        printf("(");

        parenthesis(k, i, k[i][j]);
        parenthesis(k, k[i][j] + 1, j);

        printf(")");
    }
}

// driver code
int main(void)
{
    int n;

    scanf("%d", &n);

    int *m = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &m[i]);
    }

    // duplicating the values

    int **c = (int **)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        c[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    int **k = (int **)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        k[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    matrixchain(n, m, c, k);

    printf("\n");

    printcost(c, n);

    printf("\n");

    index_print(k, n);

    printf("\n");

    parenthesis(k, 1, n);

    printf("\n\n");

    printf("%d", c[1][n]);

    // freeing all the memory space
    free(m);
    free(c);
    free(k);

    return 0;
}