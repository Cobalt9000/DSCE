#include <stdio.h>
#include <math.h>
int main() 
{
   float root_1,root_2,r_part,i_part,a,b,c,d,e;
   printf("Enter the non zero coefficient values of a, b and c of a quadratic equation: \n");
   scanf("%f %f %f",&a,&b,&c);
   d=b*b - 4*a*c;
   e=sqrt(d);
   if(d==0)
   {
       root_1=(-b)/(2*a);
       root_2=root_1;
       printf("Roots are real and equal and are given by %f and %f\n",root_1,root_2);
   }
   else if(d>0)
   {
       root_1=(-b+e)/(2*a);
       root_2=(-b-e)/(2*a);
        printf("Roots are real and distinct and are given by %f and %f\n",root_1,root_2);
   }
   else
   {
       r_part=-b/2*a;
       i_part=sqrt(fabs(d))/2*a;
       printf("Roots are imaginary and are given by %f+%fi and %f-%fi",r_part,i_part,r_part,i_part);
   }
    return 0;
}