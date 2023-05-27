/// Compilers use expression trees to represent mathematical expressions where the leaf nodes represent the operands and the internal nodes represent the operators.
/// Develop a program to evaluate such an expression tree with non-negative integers as operands and the arithmetic operators ‘+’, ‘-‘, ‘*’and ‘/’.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main ()
{
    char a[100],ch;
    int t1,t2,res,i,count=0;
    printf ("Enter Expression Tree of the form (a+b)*(c/d)\n"); scanf ("%s",a);
    for (i=0;i<strlen(a);i++)
    {
        ch = a[i];
        if (isdigit(ch))
            break;
        else
            count = count+1;
    }
    count = count-1;
    while (count >= 0)
    {
        t1 = a[2*count+1]-48;
        t2 = a[2*count+2]-48;
        if (a[count] == '/')
            res = t1/t2;
        else if (a[count] == '*')
            res = t1*t2;
        else if (a[count] == '+')
            res = t1+t2;
        else if (a[count] == '-')
            res = t1-t2;
        else
            printf ("Invalid Expression\n");
        a[count] = res+48;
        count = count-1;
    }
    printf ("Evaluated Result from Expression Tree is %d\n",res);
}
