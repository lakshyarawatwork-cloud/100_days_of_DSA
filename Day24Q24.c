/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
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

struct Node* deleteKey(struct Node* head,int key){
    struct Node *temp=head,*prev=NULL;

    while(temp){
        if(temp->data==key){
            if(prev==NULL)
                head=temp->next;
            else
                prev->next=temp->next;

            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

void printList(struct Node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    int n,key;
    scanf("%d",&n);

    struct Node* head=createList(n);

    scanf("%d",&key);

    head=deleteKey(head,key);

    printList(head);

    return 0;
}