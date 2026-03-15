/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n){
    if(n == 0 || arr[0] == -1) return NULL;

    Node* nodes[n];

    for(int i = 0; i < n; i++){
        if(arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = createNode(arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(nodes[i] == NULL) continue;

        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < n) nodes[i]->left = nodes[l];
        if(r < n) nodes[i]->right = nodes[r];
    }

    return nodes[0];
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Node* root = buildTree(arr,n);

    inorder(root);

    return 0;
}