/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head,int val){
    struct Node* n=malloc(sizeof(struct Node));
    n->data=val;
    n->next=NULL;
    if(!head) return n;
    struct Node* t=head;
    while(t->next) t=t->next;
    t->next=n;
    return head;
}

int length(struct Node* head){
    int c=0;
    while(head){ c++; head=head->next; }
    return c;
}

int main(){
    int n,m,x;
    struct Node *h1=NULL,*h2=NULL;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){ scanf("%d",&x); h1=append(h1,x); }

    scanf("%d",&m);
    for(int i=0;i<m;i++){ scanf("%d",&x); h2=append(h2,x); }

    int l1=length(h1), l2=length(h2);
    struct Node *p1=h1,*p2=h2;

    if(l1>l2){ for(int i=0;i<l1-l2;i++) p1=p1->next; }
    else{ for(int i=0;i<l2-l1;i++) p2=p2->next; }

    while(p1 && p2){
        if(p1->data==p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }

    printf("No Intersection");
    return 0;
}