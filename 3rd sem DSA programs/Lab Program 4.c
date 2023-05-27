/// Colleges maintain the student’s records. As students enroll and graduate, the records have to be updated.
/// It is necessary to access the student’s data whenever required by college. Using suitable data structures develop a program for above scenario.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[30], usn[20];
    int sem;
    struct node *left, *right;
};

typedef struct node* NODE;

NODE insertFront (NODE first)
{
    NODE newnode;
    char name [30], usn [20];
    int sem;
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL;
    printf ("Enter student details: \n");
    printf ("Name:\n");
    scanf ("%s", name);
    printf ("USN:\n");
    scanf ("%s",usn);
    printf ("Semester:\n");
    scanf ("%d",&sem);
    strcpy (newnode->name, name);
    strcpy (newnode->usn, usn);
    newnode->sem = sem;
    if (first == NULL)
    {
        first = newnode;
        return first;
    }
    else
    {
        newnode->right = first;
    }
    first->left=newnode;
    first = newnode;
    return first;
}
void search (NODE first)
{
    NODE pres;
    char usn [20];
    if (first == NULL)
    {
        printf ("Empty Database\n");
        return;
    }
    printf ("Enter USN to be searched: ");
    scanf ("%s", usn);
    pres = first;
    while (pres != NULL && strcmp (usn, pres->usn) != 0)
        pres = pres->right;
    if (pres == NULL)
        printf ("Student not found\n");
    else
        printf ("Student found\n");
}

void display (NODE first)
{
    if (first == NULL)
        printf ("Empty Database\n");
    else
    {
        printf ("Student details: \n");
        printf ("Name\t\tUSN\t\t\tSemester\n");
        while (first != NULL)
        {
            printf ("%s\t\t%s\t\t%d\n", first->name, first->usn, first->sem);
            first = first->right;
        }
    }
}

int main ()
{
    int ch;
    NODE first = NULL; for (;;)
    {
        printf ("1:INSERT 2:SEARCH 3:DISPLAY\n");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 1 : first = insertFront (first); break;
            case 2 : search (first); break;
            case 3 : display (first); break;
            default : exit(0);
        }
    }
    return 0;
}
