#include<stdio.h>
#include<conio.h>
void main()
{
inti,j,k,n,a[10][10];
clrscr();
printf("\n Enter the no. of vertices : ");
scanf("%d",&n);
printf("\n Enter the adjacency matrix : \n ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=((a[i][j])||(a[i][k]&&a[k][j]));
}
}
}
printf("\n The transitive closure is : \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("\t%d",a[i][j]);
}
printf("\n");
}
getch();
}
