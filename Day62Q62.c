/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *neighbors;
    int size;
    int capacity;
} AdjList;

typedef struct {
    AdjList *lists;
    int n;
} Graph;

Graph *createGraph(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->n = n;
    g->lists = malloc(n * sizeof(AdjList));
    for (int i = 0; i < n; i++) {
        g->lists[i].neighbors = malloc(2 * sizeof(int));
        g->lists[i].size = 0;
        g->lists[i].capacity = 2;
    }
    return g;
}

void addEdge(Graph *g, int u, int v) {
    AdjList *l = &g->lists[u];
    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->neighbors = realloc(l->neighbors, l->capacity * sizeof(int));
    }
    l->neighbors[l->size++] = v;
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->lists[i].size; j++) {
            printf("%d", g->lists[i].neighbors[j]);
            if (j < g->lists[i].size - 1) printf(" -> ");
        }
        printf("\n");
    }
}

void freeGraph(Graph *g) {
    for (int i = 0; i < g->n; i++)
        free(g->lists[i].neighbors);
    free(g->lists);
    free(g);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
        addEdge(g, v, u);
    }
    printGraph(g);
    freeGraph(g);
    return 0;
}