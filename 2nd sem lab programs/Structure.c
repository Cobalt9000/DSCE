#include<stdio.h>
struct employee
{
    int eid, eage;
    char ename[20];
    float esal;
};
int main()
{
    struct employee e[50];
    int n,i;
    printf("Enter the number of employees:\n");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the details of employee %d: \n",i+1);
        printf("\nEnter eid:\t");
        scanf("%d",&e[i].eid);
        printf("\nEnter ename:\t");
        scanf("%s",e[i].ename);
        printf("\nEnter eage:\t");
        scanf("%d",&e[i].eage);
        printf("\nEnter esal:\t");
        scanf("%f",&e[i].esal);
        printf("\n");
    }
    printf("\n***********************************\n");
    printf("\nDetails of %d employees are as follows: \n",n);
    printf("\n***********************************\n");
    printf("\nEmpid\tEmpname\tEmpage\tEmpsal\n");
    printf("\n----------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%s\t%d\t%f\n",e[i].eid,e[i].ename,e[i].eage,e[i].esal);
    }
    printf("\n-----------------------------------\n");
    
    return 0;
}
