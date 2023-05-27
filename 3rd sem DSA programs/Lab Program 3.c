/// Scientific applications involve many polynomials with varied degree.
/// A polynomial  is an expression consisting of variables and coefficients.
/// Choose an appropriate data structure to represent the polynomial and perform addition of two polynomials.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff, exp;
    struct node *link;
};
struct node *read(struct node *head)
{
    int terms, i = 1, coeff, exp;
    printf("Enter the number of terms \n");
    scanf("%d", &terms);
    while (i <= terms)
    {
        printf("Enter the coeff \n");
        scanf("%d", &coeff);
        printf("Enter the exp \n");
        scanf("%d", &exp);
        head = insert(coeff, exp, head);
        i++;
    }
    return (head);
}
struct node *insert(int coeff, int exp, struct node *head)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->link = NULL;
    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newnode;
    }
    return head;
}
struct node *add_poly(struct node *head1, struct node *head2, struct node *head3)
{
    int sum;
    struct node *temp1, *temp2, *temp3;
    temp1 = head1;
    temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp == temp2->exp)
        {
            sum = temp1->coeff + temp2->coeff;
            head3 = insert(sum, temp1->exp, head3);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else if (temp1->exp > temp2->exp)
        {
            head3 = insert(temp1->coeff, temp1->exp, head3);
            temp1 = temp1->link;
        }
        else
        {
            head3 = insert(temp2->coeff, temp2->exp, head3);
            temp2 = temp2->link;
        }
    }
    while (temp1 != NULL)
    {
        head3 = insert(temp1->coeff, temp1->exp, head3);
        temp1 = temp1->link;
    }
    while (temp2 != NULL)
    {
        head3 = insert(temp2->coeff, temp2->exp, head3);
        temp2 = temp2->link;
    }
    return (head3);
}
void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("+%dx^%d", temp->coeff, temp->exp);
        temp = temp->link;
        printf("\t");
    }
}
void main()
{
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    printf("Enter the polynomial 1\n");
    head1 = read(head1);
    printf("Enter the polynomial 2\n");
    head2 = read(head2);
    printf("first polynomial eqn is\n");
    display(head1);
    printf("\nsecond polynomial eqn is\n");
    display(head2);
    printf("\naddition of two polynomial eqn is\n");
    head3 = add_poly(head1, head2, head3);
    display(head3);
}


