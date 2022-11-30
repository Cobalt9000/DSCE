#include<stdio.h>
#include<math.h>
int main()
    {
        float a[10],*ptr,sum,mean,sd,sumsd;
        int i,n;
        mean=0;
        sum=0;
        sd=0;
        sumsd=0;
        printf("Enter the number of elements:\n");
        scanf("%d",&n);
        printf("Enter the elements:\n");
        for(i=0;i<n;i++)
        {
            scanf("%f",&a[i]);
        }
        ptr=a;
        for(i=0;i<n;i++)
        {
            sum = sum + *ptr;
            ptr++;
        }
        mean=sum/n;
        ptr=a;
        for(i=0;i<n;i++)
        {
            sumsd = sumsd + pow((*ptr-mean),2);
            ptr++;
        }
        sd=sqrt(sumsd/n);
        printf("\nSum=%f",sum);
        printf("\nMean=%f",mean);
        printf("\nStandard Deviation=%f",sd);
        
        return 0;
    }
