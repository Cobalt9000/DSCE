/// In a calculator application, given an expression with parenthesis it is required to flag any parenthesis mismatch.
/// Develop a program for this calculator application using appropriate data  structure.
#include <stdio.h>
#define size 20
#include <string.h>

int top = -1, i;
char input[size], stack[size],ch;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    top--;
}

int main(){
    char ch;
    ch = input[i];
    printf("enter the expression: \n");
    scanf("%s", input);
    push('#');
    for(i=0; i < strlen(input); i++)
    {
        if(input[i] == '(')
            push(ch);
        if(input[i] ==')')
        {
            if(stack[top]!='#')
                pop();
            else
            {
                printf("closing parentheses are not balanced\n");
                return 0;
            }
        }
    }
    if(stack[top]=='#')
        printf("parentheses are balanced\n");
    else
        printf("opening parentheses are not balanced\n");
}
