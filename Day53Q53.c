/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    struct Node* root = newNode(arr[0]);
    struct Node* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];
        
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

struct QueueItem {
    struct Node* node;
    int hd;
};

int hd_queue[MAX];
int val_queue[MAX];
int col_queue[MAX];

void verticalOrder(struct Node* root) {
    if (!root) return;
    
    struct QueueItem q[MAX];
    int front = 0, rear = 0;
    
    q[rear].node = root;
    q[rear].hd = 0;
    rear++;
    
    int minHD = 0, maxHD = 0;
    int hdArr[MAX];
    int valArr[MAX];
    int size = 0;
    
    while (front < rear) {
        struct QueueItem item = q[front++];
        struct Node* curr = item.node;
        int hd = item.hd;
        
        hdArr[size] = hd;
        valArr[size] = curr->data;
        size++;
        
        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;
        
        if (curr->left) {
            q[rear].node = curr->left;
            q[rear].hd = hd - 1;
            rear++;
        }
        if (curr->right) {
            q[rear].node = curr->right;
            q[rear].hd = hd + 1;
            rear++;
        }
    }
    
    for (int col = minHD; col <= maxHD; col++) {
        int first = 1;
        for (int i = 0; i < size; i++) {
            if (hdArr[i] == col) {
                if (!first) printf(" ");
                printf("%d", valArr[i]);
                first = 0;
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[MAX];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    
    return 0;
}