#include <stdio.h>

int G[20][20];
int visited[20];
int q[20];
int n;
int f = 0, r = -1;

void bfs(int start)
{
    int i, curr;

    q[++r] = start;
    visited[start] = 1;

    while (f <= r)
    {
        curr = q[f++];
        printf("%d ", curr);

        for (i = 0; i < n; i++)
        {
            if (G[curr][i] == 1 && visited[i] == 0)
            {
                q[++r] = i;
                visited[i] = 1;
            }
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

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
