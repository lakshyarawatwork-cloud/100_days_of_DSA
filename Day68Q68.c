/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], inDegree[MAX], queue[MAX];
int n, e, front, rear;

void enqueue(int v) { queue[rear++] = v; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

void kahnTopologicalSort() {
    front = rear = 0;

    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            enqueue(i);

    int count = 0, order[MAX];

    while (!isEmpty()) {
        int v = dequeue();
        order[count++] = v;

        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if (count != n) {
        printf("Cycle detected. Topological sort not possible.\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < count; i++)
        printf("%d ", order[i]);
    printf("\n");
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++)
        inDegree[i] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        inDegree[v]++;
    }

    kahnTopologicalSort();
    return 0;
}