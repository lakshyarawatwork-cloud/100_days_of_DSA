/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

// Count leaf nodes recursively
int countLeaves(Node* root) {
    if (root == NULL)
        return 0;

    // A leaf has no children
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    /*
     * Example tree:
     *
     *         1
     *        / \
     *       2   3
     *      / \
     *     4   5
     *
     * Leaves: 4, 5, 3  →  count = 3
     */
    Node* root    = newNode(1);
    root->left    = newNode(2);
    root->right   = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Number of leaf nodes: %d\n", countLeaves(root));   // Output: 3

    // Free allocated memory
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}


