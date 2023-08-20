#include<stdio.h>
#include<conio.h>
voidread_adjacency_matrix(int a[10][10],int n)
{
inti,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
}
voidfind_indegree(int a[10][10],intn,intindegree[10])
{
inti,j,sum;
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
{
sum+=a[i][j];
}
indegree[j]=sum;
}
}
voidtopological_order(int a[10][10],int n)
{
intu,v,i,s[10],t[10],top=-1,k=0,indegree[10];
find_indegree(a,n,indegree);
for(i=0;i<n;i++)
{
if(indegree[i]==0)
{
s[++top]=i;
}
}
while(top!=-1)
{
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++)
{
if(a[u][v]==1)
{
indegree[v]--;
if(indegree[v]==0)
{
s[++top]=v;
}
}
}
}
printf("\n\n The topological order is : \n ");
for(i=0;i<n;i++)
{
printf("%d ",t[i]);
}
}
void main()
{
int a[10][10],n;
clrscr();
printf("\n Enter the no. of vertices in the matrix : ");
scanf("%d",&n);
printf("\n Enter the adjacency matrix : \n ");
read_adjacency_matrix(a,n);
topological_order(a,n);
getch();
}
