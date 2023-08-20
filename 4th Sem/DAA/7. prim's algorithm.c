#include<stdio.h>
#include<conio.h>
inti,j,n,c[20][20],visited[20];
void prims()
{
inta,b,min,cost=0,count=0;
min=1000;
printf("\n The minimal spanning tree is: \n");
visited[1]=1;
while(count<(n-1))
{
min=999;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(visited[i]&&(!visited[j])&&min>c[i][j])
{
min=c[i][j];
a=i;
b=j;
}
}
}
printf("\n %d --> %d = %d ",a,b,c[a][b]);
cost+=c[a][b];
visited[b]=1;
count++;
}
printf("\n The Total cost is : %d ",cost);
}
void main()
{
clrscr();
printf("\n Enter the no. of vertices : ");
scanf("%d",&n);
printf("\n Enter the cost adjacency matrix : \n ");
for(i=1;i<=n;i++)
{
printf("\n");
for(j=1;j<=n;j++)
{
printf("\t");
scanf("%d",&c[i][j]);
visited[i]=0;
}
}
prims();
getch();
}

