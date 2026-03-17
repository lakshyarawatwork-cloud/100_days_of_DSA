/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left,*right;
}Node;

Node* createNode(int v){
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=v;
    n->left=n->right=NULL;
    return n;
}

Node* buildTree(int arr[],int n){
    if(n==0||arr[0]==-1) return NULL;

    Node* nodes[n];

    for(int i=0;i<n;i++){
        if(arr[i]==-1) nodes[i]=NULL;
        else nodes[i]=createNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;

            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    return nodes[0];
}

int height(Node* root){
    if(root==NULL) return 0;

    int l=height(root->left);
    int r=height(root->right);

    return (l>r?l:r)+1;
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    Node* root=buildTree(arr,n);

    printf("%d",height(root));

    return 0;
}