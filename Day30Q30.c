/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* insert(struct Node* head,int c,int e){
    struct Node* n=malloc(sizeof(struct Node));
    n->coeff=c;
    n->exp=e;
    n->next=NULL;

    if(!head||e>head->exp){
        n->next=head;
        return n;
    }

    struct Node* t=head;
    while(t->next&&t->next->exp>e)
        t=t->next;

    n->next=t->next;
    t->next=n;
    return head;
}

void print(struct Node* head){
    struct Node* t=head;
    while(t){
        if(t->exp==0) printf("%d",t->coeff);
        else if(t->exp==1) printf("%dx",t->coeff);
        else printf("%dx^%d",t->coeff,t->exp);
        if(t->next) printf(" + ");
        t=t->next;
    }
}

int main(){
    int n,c,e;
    scanf("%d",&n);
    struct Node* head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d%d",&c,&e);
        head=insert(head,c,e);
    }
    print(head);
}