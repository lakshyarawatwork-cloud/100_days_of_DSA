/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>

int visited[100];

void dfs(int graph[100][100], int n, int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n, s;
    int graph[100][100] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int v, u;
        while (scanf("%d %d", &v, &u) == 2) {
            graph[v][u] = 1;
            graph[u][v] = 1;
        }
    }

    scanf("%d", &s);
    dfs(graph, n, s);
    printf("\n");

    return 0;
}