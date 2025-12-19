#include <stdio.h>

int G[20][20];
int visited[20];
int n;

void dfs(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (G[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int edges, u, v, start;
    int i, j;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    /* Initialize adjacency matrix and visited array */
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;   // undirected graph
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
