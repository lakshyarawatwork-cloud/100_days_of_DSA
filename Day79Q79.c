/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int v, w;
} Node;

typedef struct {
    Node* arr;
    int size;
} Heap;

void swap(Node* a, Node* b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(Heap* h, int i) {
    while (i && h->arr[(i - 1) / 2].w > h->arr[i].w) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(Heap* h, int i) {
    int l, r, smallest;
    while (1) {
        l = 2 * i + 1;
        r = 2 * i + 2;
        smallest = i;
        if (l < h->size && h->arr[l].w < h->arr[smallest].w) smallest = l;
        if (r < h->size && h->arr[r].w < h->arr[smallest].w) smallest = r;
        if (smallest == i) break;
        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }
}

void push(Heap* h, int v, int w) {
    h->arr[h->size].v = v;
    h->arr[h->size].w = w;
    heapifyUp(h, h->size++);
}

Node pop(Heap* h) {
    Node root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

int isEmpty(Heap* h) {
    return h->size == 0;
}

typedef struct Adj {
    int v, w;
    struct Adj* next;
} Adj;

Adj* addEdge(Adj* head, int v, int w) {
    Adj* node = (Adj*)malloc(sizeof(Adj));
    node->v = v;
    node->w = w;
    node->next = head;
    return node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Adj** graph = (Adj**)calloc(n + 1, sizeof(Adj*));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u] = addEdge(graph[u], v, w);
        graph[v] = addEdge(graph[v], u, w);
    }

    int src;
    scanf("%d", &src);

    int* dist = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    Heap h;
    h.arr = (Node*)malloc((n * m + 5) * sizeof(Node));
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (!isEmpty(&h)) {
        Node cur = pop(&h);
        int u = cur.v;
        int d = cur.w;

        if (d > dist[u]) continue;

        Adj* temp = graph[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}