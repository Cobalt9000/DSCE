//Transpose of Sparse Matrix
#include<stdio.h>
void transpose();
struct smatrix
{
    int row,col,val;
};
int i,j,n,k=1;
struct smatrix a[10], b[10];

int main()
{
    printf("Enter the size of matrix:\n");
    printf("Row:\n");
    scanf("%d",&a[0].row);
    printf("Column:\n");
    scanf("%d",&a[0].col);
    printf("Enter the number of the non zero elements:\n");
    scanf("%d",&n);
    a[0].val = n;
    printf("Enter the position and value of the non-zero elements:\n");
    for(i=1;i<=n;i++)
    {
        printf("Row:\n");
        scanf("%d",&a[i].row);
        printf("Column:\n");
        scanf("%d",&a[i].col);
        printf("Value:\n");
        scanf("%d",&a[i].val);
    }
    printf("The entered matrix in abstract form:\n");
    printf("\n");
    printf("\tRow\tColumn\tValue\n");
    for(i=0;i<=n;i++)
    {
        printf("\t%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
    }
    transpose();
    printf("The new matrix obtained after transpose is:\n");
    printf("\n");
    printf("\tRow\tColumn\tValue\n");
    for(i=0;i<=n;i++)
    {
        printf("\t%d\t%d\t%d\n",b[i].row,b[i].col,b[i].val);
    }
    return 0;
}

void transpose()
{
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
    for(i=0;i<a[0].val;i++)
    {
        for(j=1;j<=a[0].val;j++)
        {
            if(a[j].col==i)
            {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}
