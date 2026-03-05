/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top=-1;

void push(char x){
    stack[++top]=x;
}

char pop(){
    if(top==-1) return -1;
    return stack[top--];
}

int precedence(char x){
    if(x=='+' || x=='-') return 1;
    if(x=='*' || x=='/') return 2;
    if(x=='^') return 3;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    int i,j=0;
    
    scanf("%s",infix);
    
    for(i=0;i<strlen(infix);i++){
        char c=infix[i];
        
        if(isalnum(c))
            postfix[j++]=c;
        
        else if(c=='(')
            push(c);
        
        else if(c==')'){
            while(stack[top]!='(')
                postfix[j++]=pop();
            pop();
        }
        
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(c))
                postfix[j++]=pop();
            push(c);
        }
    }
    
    while(top!=-1)
        postfix[j++]=pop();
    
    postfix[j]='\0';
    
    printf("%s",postfix);
    
    return 0;
}