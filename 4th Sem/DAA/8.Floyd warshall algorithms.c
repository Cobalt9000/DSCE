#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int cost[10][10],a[10][10];
voidall_paths(int [10][10],int [10][10],int);
int min(int,int);
void main()
{
inti,j,n;
printf("\n Enter no. of vertices : ");
scanf("%d",&n);
printf("\n Enter adjacency matrix : \n");
for(i=1;i<=n;i++)
 {
for(j=1;j<=n;j++)
 {
scanf("%d",&cost[i][j]);
 }
 }
all_paths(cost,a,n);
printf("\n\t The shortest path obtained is : \n ");
for(i=1;i<=n;i++)
 {
for(j=1;j<=n;j++)
 {
printf("\t%d",a[i][j]);
 }
printf("\n");
 }
}
voidall_paths(int cost[10][10],int a[10][10],int n)
{ inti,j,k;
#pragma omp parallel for num_threads(2)
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
a[i][j]=cost[i][j];
}
}
#pragma omp parallel for num_threads(2)
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
int min(inta,int b)
{
return (a<b)?a:b;
}
