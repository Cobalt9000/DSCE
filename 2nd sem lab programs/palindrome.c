#include <stdio.h>
#include <math.h>

int main()
{
    int n,rev=0,digit,temp;
    printf("Enter a number:\n");
    scanf("%d",&n);
    temp=n;
    while(n!=0)
    {
        digit = n%10;
        rev = rev*10 + digit;
        n/=10;
    }
    printf("Entered number: %d \n",temp);
    printf("Reversed number: %d \n",rev);
    if(temp==rev)
    {
        printf("Entered number is a palindrome!\n");
    }
    else
    {
        printf("Entered number is not a palindrome!\n");
    }
    
    return 0;
}
