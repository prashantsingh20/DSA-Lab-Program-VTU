Design, Develop and Implement a Program in C for the following Stack
Applications
a. Evaluation of Suffix expression with single digit operands and 
operators:+, -, *, /, %, ^
b. Solving Tower of Hanoi problem with n disks*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stk[MAX],top=-1;
char pf[MAX];
int pop(){
    return stk[top--];
}
void push(int x){
    stk[++top]=x;
}
int evaluate(char op){
    int a=pop(),b=pop();
    switch(op){
        case '+': return b+a;
        case '-': return b-a;
        case '*': return b*a;
        case '/': return b/a;
        case '^': return b^a;
        case '%': return b%a;
    }
}
int isoperator(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%'||x=='^')
        return 1;
    return 0;
}
int main(){
    int i,d;
    printf("\nEnter the postfix expression to be evaluated\n");
    scanf("%s",pf);
    for(i=0;pf[i]!='\0';i++){
        if(pf[i]>='0'&&pf[i]<='9')
            push(pf[i]-48);
        else if(isoperator(pf[i]))
            push(evaluate(pf[i]));//Push the result into the stack
       else{
            printf("\nNot a valid expression\n");
            return 0;
        }
    }
    if(top==0)
        printf("\nThe result of the postfix expression is %d\n",stk[top]);
    else
        printf("\nNot a valid postfix expression\n");
}

