#include <stdio.h>
int a[50];
int create(int b);
int main()
{
    int a[10],i=0,c=0,n,ele,pos,del;
    while(c!=5)
    {
        printf("The following options you can choose from \n1. Create An Array \n2.  Insert at a position \n3. Delete at a position  \n4. Display the Array \n5. Exit the program\n");
        printf("Enter your choice (Enter the number between 1 to 5): ");
        scanf("%d",&c);
        if(c==1)
        {
            printf("Enter the size of the array: ");
            scanf("%d",&n);
            printf("Enter the elements of the array: \n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
        }
        else if(c==2)
        {
            printf("Enter the element to be inserted: ");
            scanf("%d",&ele);
            printf("Enter the postion to be inserted: ");
            scanf("%d",&pos);
            for(i=n;i>=pos-1;i--)
            {
                a[i+1]=a[i];
            }
            a[pos-1]=ele;
            n=n+1;
        }
        
        else if(c==3)
        {
            printf("Enter the pos of the element to be deleted: ");
            scanf("%d",&pos);
            del=a[pos-1];
            for(i=pos-1;i<n;i++)
            {
                a[i]=a[i+1];
            }
            printf("The element deleted is %d \n",del);
            n=n-1;
        }
        else if(c==4)
        {
            for(i=0;i<n;i++)
            {
                printf("The given array: ");
                for(i=0;i<n;i++)
                {
                    printf("%d ,",a[i]);
                }
                printf("\n");
            }
        }
        else if(c==5)
        {
            printf("the program as successfully ended.");
        }
        else
        {
            printf("please enter a choice between 1 to 5 to make this program work \n");
        }
    }
}
