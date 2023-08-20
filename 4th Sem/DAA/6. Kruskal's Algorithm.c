#include<stdio.h>
#include<conio.h>
inti,j,x,y,n,min,c[20][20],parent[20];
voidfind_min()
{
min=1000;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(min>c[i][j])
{
min=c[i][j];
x=i;
y=j;
}
}
}
}
intcheck_cycle(intx,int y)
{
if((parent[x]==parent[y])&&(parent[x]!=0))
{
return 0;
}
else if(parent[x]==parent[y])
{
parent[x]=parent[y]=x;
}
else if(parent[x]==0)
{
parent[x]=parent[y];
}
else if(parent[y]==0)
{
parent[y]=parent[x];
}
else if(parent[x]!=parent[y])
{
parent[y]=parent[x];
}
return 1;
}
void main()
{
int flag=0,total=0,count=0;
printf("\n Enter the no. of vertices : ");
scanf("%d",&n);
printf("\n Enter the cost adjacency matrix : \n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&c[i][j]);
parent[j]=0;
}
}
printf("\n Minimum Spanning Tree is : \n ");
while((count<=n-1)&&(min!=1000))
{
find_min();
flag=check_cycle(x,y);
if(flag==1)
{
printf("\n %d --> %d = %d ",x,y,c[x][y]);
total=total+c[x][y];
count++;
}
c[x][y]=c[y][x]=1000;
}
printf("\n Total Cost is : %d",total);
getch();
}
