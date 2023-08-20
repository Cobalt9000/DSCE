#include<stdio.h>
#include<time.h>
Void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
void main()
{
intn,i,a[500];
clock_t start=0,end=0;
printf("\n Enter the no. of elements : ");
scanf("%d",&n);
for(i=0;i<n;i++) 
a[i]=rand()%200;
printf("\n Generated elements are : \n");
for(i=0;i<n;i++)
printf("\t %d",a[i]);
start=clock();
mergesort(a,0,n-1);
end=clock();
printf("\nThe sorted elements are : \n");
for(i=0;i<n;i++)
printf("\t %d",a[i]);
printf("\n Time taken : %f",(end-start)/(double)CLOCKS_PER_SEC);
}
voidmergesort(int a[],intlow,int high)
{
int mid;
if(low<high)
{
{
mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
}
merge(a,low,mid,high);
}
}
void merge(int a[],intlow,intmid,int high)
{
inti,j,k,t[500];
i=low;
j=mid+1;
k=low;
{
for(;(i<=mid) && (j<=high);)
if(a[i]<a[j])
t[k++]=a[i++];
else
t[k++]=a[j++];
while(i<=mid)
t[k++]=a[i++];
while(j<=high)
t[k++]=a[j++];
for(i=low;i<=high;i++)
a[i]=t[i];
}
}
