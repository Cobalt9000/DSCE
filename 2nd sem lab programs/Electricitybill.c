#include <stdio.h>
#include <math.h>

int main()
{
    char name[20];
    int n;
    float amount;
    printf("Enter the consumer name: \n");
    scanf("%s",name);
    printf("Enter the units consumed: \n");
    scanf("%d",&n);
    
    if(n<=200)
    {
        amount = n*80;
    }
    else if(n>200 && n<=300)
    {
        amount = 200*80 + (n-200)*90;
    }
    else
    {
        amount = 200*80 + 100*90 + (n-300)*100;
    }
    amount = amount/100;
    amount = amount + 100;
    if(amount>400)
    {
        amount = amount + (0.15)*amount;
    }
    printf("Name: %s\n",name);
    printf("Units consumed: %d\n",n);
    printf("Amount to be paid: %2f\n",amount);
    
    return 0;
}
