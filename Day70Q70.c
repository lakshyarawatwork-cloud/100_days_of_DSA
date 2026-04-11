/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>
#include <limits.h>

typedef struct { int u, v, w; } Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Edge edges[m];
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    
    long long dist[n];
    for (int i = 0; i < n; i++) dist[i] = LLONG_MAX;
    dist[0] = 0;
    
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (dist[edges[j].u] != LLONG_MAX &&
                dist[edges[j].u] + edges[j].w < dist[edges[j].v])
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
    
    for (int j = 0; j < m; j++)
        if (dist[edges[j].u] != LLONG_MAX &&
            dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    
    for (int i = 0; i < n; i++)
        dist[i] == LLONG_MAX ? printf("INF\n") : printf("%lld\n", dist[i]);
    
    return 0;
}