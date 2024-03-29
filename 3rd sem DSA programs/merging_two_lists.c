#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}node;
node *merge(node *p , node *q , node *sorting)
{
  node *head3;
  if(p == NULL)
    return q;
  if(q == NULL)
    return p;
  if(p && q)
  {
    if(p->data <= q->data)
    {
      sorting = p;
      p = sorting->next;
    }
    else
    {
      sorting = q;
      q = sorting->next;
    }
  }
  head3 = sorting;
  while(p && q)
  {
    if(p->data <= q->data)
    {
      sorting->next = p;
      sorting = p;
      p = sorting->next;
    }
    else
    {
      sorting->next = q;
      sorting = q;
      q = sorting->next;
    }
  }
  if(p==NULL)
  {
    sorting->next = q;
  }
  if(q==NULL)
  {
    sorting->next = p;
  }
  return head3;
}

int main()
{
node *p=NULL , *q=NULL , *head1=NULL , *head2=NULL , *sorting = NULL, *t;
int n1 , n2 , a , i;
printf("Enter the number of nodes in the First Linked List");
scanf("%d",&n1);
printf("Enter the number of nodes in the second Linked List");
scanf("%d",&n2);
printf("Enter the first Linked List");
for(i=1;i<=n1;i++)
{
  scanf("%d",&a);
  p= (node*)malloc(sizeof(node));
  p->data = a;
  p->next = NULL;
  if(head1==NULL)
    head1=p;
  else
  {
    t=head1;
    while(t->next!=NULL)
      t=t->next;
    t->next = p;
  }
}
printf("Enter the second Linked List");
for(i=1;i<=n2;i++)
{
  scanf("%d",&a);
  q= (node*)malloc(sizeof(node));
  q->data = a;
  q->next = NULL;
  if(head2==NULL)
    head2=q;
  else
  {
    t=head2;
    while(t->next!=NULL)
      t=t->next;
    t->next = q;
 }
}
p = head1;
q = head2;
printf("\n First Linked List => ");
while(p!=NULL)
{
  printf("%d ",p->data);
  p = p->next;
}
printf("\n Second Linked List =>");
while(q!=NULL)
{
  printf("%d ",q->data);
  q = q->next;
}
p = head1;
q = head2;
sorting = merge(p , q , sorting);
printf("\n Sorted Merged Linked List =>");
while(sorting!=NULL)
{
  printf("%d ",sorting->data);
  sorting = sorting->next;
}
return 0;
}

