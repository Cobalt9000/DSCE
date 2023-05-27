void reverse()
{
 struct node *curr, *prev=NULL,*next=NULL;
 curr=root;
 while(curr!=NULL)
 {
 next=curr->link;
 curr->link=prev;
 prev=curr;
 curr=next;
 }
 root=prev;
}
