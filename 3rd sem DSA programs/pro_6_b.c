#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
int eid;
char ename [10];
float lt;
struct node *left;
struct node *right;
};
typedef struct node *NODE;
NODE insert (NODE root,int eid,char ename [10],float lt)
{
NODE newnode,prev,pres;
newnode = (NODE)malloc(sizeof(struct node));
newnode->left = newnode->right = NULL;
newnode->eid = eid;
strcpy (newnode->ename,ename);
newnode->lt = lt;
if (root == NULL)
{
root = newnode;
return root;
}
pres = root;
while (pres != NULL)
{
prev = pres;
if (eid < pres->eid)
pres = pres->left;
else if (eid > pres->eid)
pres = pres->right;
else
{

printf ("Duplicate\n");
return root;
}
}
if (eid < prev->eid)
prev->left = newnode;
else
prev->right = newnode;
return root;
}
void inorder (NODE root)
{
if (root != NULL)
{
inorder (root->left);
printf
("%d\t%s\t\t%.2f\n",root->eid,root->ename,root->lt);
inorder (root->right);
}
}
int main ()
{
NODE root = NULL;
int ch,eid;
char ename [10];
float lt;
for (;;)
{
printf ("1:INSERT 2:INORDER\n");
scanf ("%d",&ch);
switch (ch)
{
case 1: printf ("Enter Employee Details:\n");
printf ("Employee ID\n");
scanf ("%d",&eid);
printf ("Employee Name\n");
scanf ("%s",ename);
printf ("Login Time\n");
scanf ("%f",&lt);
root = insert(root, eid, ename, lt);
break;
case 2: if (root == NULL)
printf ("Employee Details Absent\n");
else
{
printf("Eid\tEname\tLT\n");
inorder(root);
}
break;
default: exit(0);
}
}
}
