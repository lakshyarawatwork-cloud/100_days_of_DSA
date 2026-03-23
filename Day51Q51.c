/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val)      root->left  = insert(root->left,  val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

/*
 * LCA in a BST — iterative, O(H) time, O(1) space
 *
 * At each node:
 *   both p,q < cur  → LCA is in left subtree
 *   both p,q > cur  → LCA is in right subtree
 *   otherwise       → cur IS the LCA (paths diverge here)
 */
int lca(Node* root, int p, int q) {
    Node* cur = root;
    while (cur) {
        if (p < cur->val && q < cur->val)
            cur = cur->left;
        else if (p > cur->val && q > cur->val)
            cur = cur->right;
        else
            return cur->val;
    }
    return -1; /* p or q not in tree */
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        root = insert(root, v);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    printf("%d\n", lca(root, p, q));

    freeTree(root);
    return 0;
}