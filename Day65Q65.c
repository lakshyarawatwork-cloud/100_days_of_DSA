/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n, e;

int dfs(int node, int parent) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &e);
    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) { cycle = 1; break; }
        }
    }
    printf("%s\n", cycle ? "YES" : "NO");
    return 0;
}