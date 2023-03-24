#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[20];
    char usn[10];
    int sem;
    struct node *prev;
    struct node *next;
};
typedef struct node *Node;
Node head=NULL;
void insert()
{
    int s;
    Node newnode;
    newnode=(Node)malloc(sizeof(struct node));
    printf("Enter student name\n");
    scanf("%s",newnode->name);
    printf("Enter student USN\n");
    scanf("%s",newnode->usn);
    printf("Enter semester\n");
    scanf("%d",&s);
    newnode->sem=s;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Node temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void search()
{
    Node temp;
    int found;
    char susn[10];
    printf("Enter USN to be searched\n");
    scanf("%s",&susn);
    if(head==NULL)
        printf("Empty data\n");
    temp=head;
    while((temp!=NULL)&&(strcmp(susn,temp->usn)!=0))
    {
        temp=temp->next;
    }
    if(temp==NULL)
        printf("Entered usn not found\n");
    else
        printf("USN found \nNAME:%s\nUSN:%s\nSEM:%d\n",temp->name,temp->usn,temp->sem);

}
void display()
{
    Node temp;
    if(head==NULL)
        printf("No data to display\n");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("NAME:%s\nUSN:%s\nSEM:%d\n",temp->name,temp->usn,temp->sem);
            temp=temp->next;
        }
    }
}void main()
{
    int opt=0;
    while(opt<4)
    {
        printf("Choose any one of the options below\n1.INSERT\n2.SEARCH\n3.DISPALY\n4.EXIT\n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            insert();
            break;
        case 2:
            search ();
            break;
        case 3:
            display();
            break;
        case 4:
            continue;
        }
    }
}
