#include<stdio.h>
#include<conio.h>
void main()
{
inti,j,n,v,k,min,u,c[20][20],s[20],d[20];
clrscr();
printf("\n Enter the no. of vertices : ");
scanf("%d",&n);
printf("\n Enter the cost adjacency matrix : ");
printf("\n Enter 999 for no edge ");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&c[i][j]);
}
}
printf("\n Enter the source vertex : ");
scanf("%d",&v);
for(i=1;i<=n;i++)
{
s[i]=0;
d[i]=c[v][i];
}
d[v]=0;
s[v]=1;
for(k=2;k<=n;k++)
{
min=999;
for(i=1;i<=n;i++)
{
if((s[i]==0)&&(d[i]<min))
{
min=d[i];
u=i;
}
}
s[u]=1;
for(i=1;i<=n;i++)
{
if(s[i]==0)
{
if(d[i]>(d[u]+c[u][i])
{
d[i]=d[u]+c[u][i];
}
}
}
}
printf("\n The shortest distance from %d is ");
for(i=1;i<=n;i++)
{
printf("\n %d --> %d = %d ",v,i,d[i]);
}
getch();
}
