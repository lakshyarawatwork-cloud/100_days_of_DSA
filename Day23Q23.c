/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createList(int n){
    struct Node *head=NULL,*temp=NULL,*newnode;
    for(int i=0;i<n;i++){
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head==NULL){
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct Node* merge(struct Node* a, struct Node* b){
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(a && b){
        if(a->data < b->data){
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if(a) tail->next = a;
    if(b) tail->next = b;

    return dummy.next;
}

void printList(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    int n,m;
    scanf("%d",&n);
    struct Node* list1 = createList(n);

    scanf("%d",&m);
    struct Node* list2 = createList(m);

    struct Node* merged = merge(list1,list2);
    printList(merged);

    return 0;
}