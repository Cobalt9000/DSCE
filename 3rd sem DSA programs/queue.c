#include<stdio.h>
#include <stdlib.h>
#define size 20
int q[100],front=0,rear=-1,choice;
int insert();
int deleted();
int display();
int main()
{
 while(c!=4)
 {
   printf(" 1. Insert() /n 2. Deleted() /n 3. Display() /n 4. Exit()); 
   printf("/nenter the choice: ");
   scanf("%d",&choice);
   switch (choice)
   {
     case 1:
       insert();
       break;
     case 2:
       deleted();
       break;
     case 3:
       display();
       break;
     default:
       printf("Please enter a vaild input from 1 to 5.");
   }
 }
 return 0;
}   

int insert()
{
    if(rear==size-1)
    {
        printf("queue is full");
    }
    else{
        int data;
        printf("enter the data: ");
        scanf("%d",&data);
        q[++rear]=data;
    }
}

int deleted()
{
    if(rear==front)
    {
        printf("queue is empty");
    }
    int ele;
    ele=q[front++];
    printf("deleted element is %d",ele);
}
int display()
{
    if(rear==front)
    {
        printf("queue is empty");
    }
    else{
        printf("elements of queue are: \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
            // exit(0);
        }
    }
}
