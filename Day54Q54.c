/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *new_node(int val) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val  = val;
    node->left = node->right = NULL;
    return node;
}

typedef struct {
    TreeNode **data;
    int front, rear, size, capacity;
} Queue;

Queue *create_queue(int cap) {
    Queue *q    = (Queue *)malloc(sizeof(Queue));
    q->data     = (TreeNode **)malloc(cap * sizeof(TreeNode *));
    q->front    = q->rear = q->size = 0;
    q->capacity = cap;
    return q;
}
void  enqueue(Queue *q, TreeNode *node) { q->data[q->rear++] = node; q->size++; }
TreeNode *dequeue(Queue *q)             { q->size--; return q->data[q->front++]; }
int   is_empty(Queue *q)                { return q->size == 0; }


TreeNode *build_tree(int *nodes, int n) {
    if (n == 0 || nodes[0] == -1) return NULL;

    TreeNode *root = new_node(nodes[0]);
    Queue    *q    = create_queue(n);
    enqueue(q, root);
    int i = 1;

    while (!is_empty(q) && i < n) {
        TreeNode *node = dequeue(q);

        if (i < n && nodes[i] != -1) {
            node->left = new_node(nodes[i]);
            enqueue(q, node->left);
        }
        i++;

        if (i < n && nodes[i] != -1) {
            node->right = new_node(nodes[i]);
            enqueue(q, node->right);
        }
        i++;
    }
    free(q->data); free(q);
    return root;
}


typedef struct {
    int *data;
    int front, rear, size, capacity;
} Deque;

Deque *create_deque(int cap) {
    Deque *d    = (Deque *)malloc(sizeof(Deque));
    d->data     = (int *)malloc(cap * sizeof(int));
    d->front    = cap / 2;   /* start in the middle */
    d->rear     = cap / 2;
    d->size     = 0;
    d->capacity = cap;
    return d;
}
void push_back (Deque *d, int v) { d->data[d->rear++]  = v; d->size++; }
void push_front(Deque *d, int v) { d->data[--d->front] = v; d->size++; }

void zigzag_traversal(TreeNode *root, int n) {
    if (!root) return;

    Queue *q        = create_queue(n + 1);
    Deque *level    = create_deque(n + 2);
    int    l2r      = 1;   /* Level 1: left→right */

    enqueue(q, root);

    while (!is_empty(q)) {
        int sz      = q->size;
        level->front = level->rear = (n + 2) / 2;
        level->size  = 0;

        for (int i = 0; i < sz; i++) {
            TreeNode *node = dequeue(q);

            if (l2r) push_back (level, node->val);
            else     push_front(level, node->val);

            if (node->left)  enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

       
        for (int i = 0; i < level->size; i++) {
            if (i) printf(" ");
            printf("%d", level->data[level->front + i]);
        }

        l2r = !l2r;   
    }
    printf("\n");

    free(q->data); free(q);
    free(level->data); free(level);
}


int main() {
    int n;
    scanf("%d", &n);

    int *nodes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &nodes[i]);

    TreeNode *root = build_tree(nodes, n);
    zigzag_traversal(root, n);

    free(nodes);
    return 0;
}