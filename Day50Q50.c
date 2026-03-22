/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *root, int data) {
    if (!root) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node *search(Node *root, int key) {
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node *root = NULL;
    int keys[] = {8, 3, 10, 1, 6, 9, 14};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    int target;
    printf("Enter key to search: ");
    scanf("%d", &target);

    Node *result = search(root, target);
    if (result)
        printf("Found: %d\n", result->data);
    else
        printf("Not found\n");

    return 0;
}