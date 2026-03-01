/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int x){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

int length(struct Node* head){
    int c = 0;
    while(head){
        c++;
        head = head->next;
    }
    return c;
}

struct Node* rotateRight(struct Node* head,int k){
    if(!head || !head->next || k==0) return head;
    int n = length(head);
    k = k % n;
    if(k==0) return head;

    struct Node* tail = head;
    while(tail->next) tail = tail->next;
    tail->next = head;

    int steps = n - k;
    struct Node* newTail = head;
    for(int i=1;i<steps;i++) newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main(){
    int n,x,k;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        struct Node* nn = createNode(x);
        if(!head) head=temp=nn;
        else{
            temp->next=nn;
            temp=nn;
        }
    }

    scanf("%d",&k);

    head = rotateRight(head,k);

    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    return 0;
}