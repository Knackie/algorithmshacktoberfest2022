/* Author : G Pala Venki Reddy */

/* prims-algo.c : Prim's algorithm for finding minimum spanning tree */

/* 
    problem Description : 

    Given a connected and undirected graph, find the minimum spanning Tree and its corresponding weight.

    A spanning tree of that graph is a subgraph that is a tree and connects all the vertices together.
    A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight 
    spanning tree for a weighted, connected and undirected graph is a spanning tree with weight less than or equal 
    to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to 
    each edge of the spanning tree.

*/

/* 
    Input :

    1. First line is the number of vertices.
    2. Second line is the number of edges.
    3. Next lines are the edges and their weights.

*/

/* output :

    1. Minimum spanning tree and its corresponding weight.

*/

/* 
    Sample Input :

    6
    9
    0 1 4
    0 2 4
    1 2 2
    1 3 3
    2 3 4
    2 4 2
    3 4 3
    3 5 2
    4 5 3

    Sample Output :

    0 1 4
    1 2 2
    2 4 2
    1 3 3
    3 5 2
    13

    Explanation :

    The Edges in the output are the edges in the minimum spanning tree and the last line is the weight of the tree.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INFINITY 9999
#define NIL -1

int graph[MAX][MAX], n, m;
int selected[MAX];

void create_graph();
void prims();

int main()
{
    int i, j;
    create_graph();
    prims();
    return 0;
}

void create_graph()
{
    int i, max_edges, origin, destin, weight;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    printf("Enter number of Edges : ");
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &origin, &destin, &weight);
        graph[origin][destin] = weight;
    }
}

void prims()
{
    int i, j, ne = 0, a, b, u, v, min;
    int mincost = 0;
    int cost[MAX][MAX];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = graph[i][j];
            }
            selected[i] = 0;
        }
    }

    selected[0] = 1;
    while (ne < n - 1)
    {
        min = INFINITY;
        for (i = 0; i < n; i++)
        {
            if (selected[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (selected[j] == 0)
                    {
                        if (min > cost[i][j])
                        {
                            min = cost[i][j];
                            a = u = i;
                            b = v = j;
                        }
                    }
                }
            }
        }
        if (min != INFINITY)
        {
            printf("Edge %d:(%d %d) cost:%d ", ne++, a, b, min);
            mincost += min;
            selected[b] = 1;
        }
        cost[a][b] = cost[b][a] = INFINITY;
    }
    printf(" Minimum cost = %d \n", mincost);
}
