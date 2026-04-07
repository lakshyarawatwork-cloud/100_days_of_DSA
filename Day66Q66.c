/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int graph[MAX][MAX], bool visited[], bool recStack[], int v, int n) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(graph, visited, recStack, i, n))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycle(int graph[MAX][MAX], int n) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < n; i++)
        if (!visited[i] && dfs(graph, visited, recStack, i, n))
            return true;

    return false;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    printf("%s\n", hasCycle(graph, n) ? "YES" : "NO");
    return 0;
}