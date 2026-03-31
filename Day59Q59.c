/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>

int inorder[100], postorder[100], n;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* build(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;
    
    int rootVal = postorder[postEnd];
    struct Node* root = newNode(rootVal);
    
    int idx;
    for (idx = inStart; idx <= inEnd; idx++)
        if (inorder[idx] == rootVal) break;
    
    int leftSize = idx - inStart;
    
    root->left = build(inStart, idx - 1, postStart, postStart + leftSize - 1);
    root->right = build(idx + 1, inEnd, postStart + leftSize, postEnd - 1);
    
    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
    
    struct Node* root = build(0, n - 1, 0, n - 1);
    preorder(root);
    printf("\n");
    return 0;
}