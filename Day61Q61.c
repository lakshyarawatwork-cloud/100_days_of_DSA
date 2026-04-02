/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>

int main() {
    int n, m, directed;
    scanf("%d %d %d", &n, &m, &directed);
    
    int graph[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u-1][v-1] = 1;
        if (!directed)
            graph[v-1][u-1] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", graph[i][j]);
            if (j < n-1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}


