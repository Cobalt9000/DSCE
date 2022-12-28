#include<stdlib.h>
struct sparse
{
int row;
int col;
int val;
};
void create();
int main()
{
    create();
}
void create()
{
    struct sparse s[10];
int m,n,value,i,j;
printf("enter the values of m and n:\n");
scanf("%d%d",&m,&n);
s[0].row=m;
s[0].col=n;
s[0].val=6;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
    printf("enter the value\n");
scanf("%d",&value);
if(value==0)
continue;
s[j].row=i;
s[j].col=j;
s[j].val=value;
}
}
for(i=1;i<=s[0].val;i++)
{
    printf("%d\t%d\t%d\t",s[i].row,s[i].col,s[i].val);
}
}
