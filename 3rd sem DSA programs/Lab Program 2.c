/// In a system, resources are shared among multiple consumers for optimal performance.
/// Considering jobs submitted to the printer have to be printed in the order of arrival.
/// In print spooling, documents are loaded into a buffer and then the printer pulls them off the buffer at its own rate.
/// Spooling also lets you place a number of print jobs on a queue instead of waiting for each one to finish before specifying the next one.
/// Develop a program for such scheduling using appropriate data structure.

#include<stdio.h>
#define sz 100
#include<stdlib.h>
int cq[sz],rear=-1,count=0,front=0,i,j;

void insert(int item)
{
    rear=(rear+1)%sz;
    cq[rear]=item;
    count++;
}

void deletion()
{
    if(count==0)
    {
        printf("\nNo job in print spool!\n");
    }
    else
    {
        printf("\n%d is exiting print spool\n",cq[front]);
        front=(front+1)%sz;
        count--;
    }
}

void display()
{
    if(count==0)
    {
        printf("\nPrint spool is empty!\n");
    }
    else
    {
        printf("\nContent of print Spool\n");
        j=front;
        for(i=j;i<count;i++)
        {
            printf("%d is printing...\n",cq[j]);
            j=(j+1)%sz;
        }
    }
}

int main()
{
    int item,ch;
    for(;;)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the print job in spool:\n");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: deletion();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Enter a valid number!\n");
        }
    }
    return (0);
}

