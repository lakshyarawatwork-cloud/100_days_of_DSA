/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000

typedef struct Edge {
    int dest, weight;
    struct Edge* next;
} Edge;

typedef struct {
    int node, dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size, capacity;
} MinHeap;

Edge* graph[MAX_NODES];

void add_edge(int src, int dest, int weight) {
    Edge* e = malloc(sizeof(Edge));
    e->dest = dest;
    e->weight = weight;
    e->next = graph[src];
    graph[src] = e;
}

MinHeap* create_heap(int capacity) {
    MinHeap* h = malloc(sizeof(MinHeap));
    h->data = malloc(sizeof(HeapNode) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a; *a = *b; *b = t;
}

void push(MinHeap* h, int node, int dist) {
    h->data[h->size++] = (HeapNode){node, dist};
    int i = h->size - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].dist <= h->data[i].dist) break;
        swap(&h->data[p], &h->data[i]);
        i = p;
    }
}

HeapNode pop(MinHeap* h) {
    HeapNode min = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, s = i;
        if (l < h->size && h->data[l].dist < h->data[s].dist) s = l;
        if (r < h->size && h-