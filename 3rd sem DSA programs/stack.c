// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define size 10
int s[size],top=-1;
void isempty();
void isfull();
void push();
void pop();
void display();

void main() { int d;
    printf("1:isempty,2:isfull,3:push,4:pop,5:display\n");
    while(1)
    {
        printf("enter the character\n");
    scanf("%d",&d);
    switch(d)
   { case 1:isempty();
    break;
    case 2:isfull();
    break;
    case 3:push();
    display();
    break;
    case 4:pop();
    display();
    break;
    case 5:display();
       exit(0);
   }}}
    
    void isempty()
    {if (top==-1)
    printf("stack is empty\n");
    else
    return;
    }
    
    void isfull()
    {
        if(top==size-1)
        printf("stack is full\n");
        else 
        return;
    }
    
    void push()
    {
       int ele;
       if(top==size-1)
       printf("stack is full\n");
       else
       {
           printf("enter element to be inserted\n");
           scanf("%d",&ele);
           top=top+1;
           s[top]=ele;
       }
    }
    
    void pop()
    {
        int val;
        if (top==-1)
        printf("stack is empty\n");
        else
        {
            val=s[top];
            printf("the deleted element is %d\n",val);
            top=top-1;
        }
    }
    
    void display()
    { int i;
        isempty();
        for(i=top;i>=0;i--)
        printf("%d\t",s[i]);
    }
