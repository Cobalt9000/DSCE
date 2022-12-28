include<stdio.h>
#include<ctype.h>
#define size 10
char infix[20], postfix[20], stack[20];
char symbol;
int top = -1;
int pre(char a);
void infix_postfix();
void push(char b);
char pop();


void main(){
    printf("enter infix expression:\n");
    scanf("%s", infix);
    printf("infix %s", infix);
    infix_postfix();
}

void infix_postfix(){
    int i = 0, k = 0;
    stack[++top] = '#';
    printf("stack[0] = %c\n", stack[top]);
    while((symbol = infix[i++])!='\0')
    {
        printf("symbol = %c\n", symbol);
        if(isalnum(symbol))
            postfix[k++] = symbol;

        else if(symbol=='(')
            push(symbol);

        else if(symbol == ')')
        {
            while(stack[top]!='(')
                    postfix[k++] = pop();
            char ele = pop();
        }

        else
        {
            if(pre(stack[top])>=pre(symbol))
               postfix[k++] = pop();
            push(symbol);
        }
    }
        while(stack[top]!='#')
            postfix[k++] = pop();
    printf("postfix: %s\n", postfix);
}

int pre(char a){
    if(a == '*'|| a == '/' || a == '%')
        return 2;
    else if(a == '+'|| a== '-')
        return 1;
    else
        return 0;
}

void push(char b){
    if(top==size-1)
    {
        return;
    }
    stack[++top] = b;
}

char pop(){
    char val = stack[top];
    top--;
    return(val);
}
