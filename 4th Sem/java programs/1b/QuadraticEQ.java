package quadratic_equation;
import java.util.Scanner;
public class QuadraticEQ
{
    public static void main (String[] args)
    {
        System.out.println("Enter the coefficient a,b,c of quadratic equation");
        Scanner scanner =new Scanner(System.in);
        double a=scanner.nextInt();
        if(a==0)
        {
            System.out.println("It is a Linear Equation:");
        }
        else
        {
            double b=scanner.nextInt();
            double c=scanner.nextInt();
            double z=b*b-4*a*c;
            if(z<0)
            {
                System.out.println("No real solutions");
            }
            else if(z==0)
            {
                System.out.println("The solutions are real and equal");
                double x1 = (-b-z)/(2*a);
                double x2 = (-b+z)/(2*a);
                System.out.println(x1);
                System.out.println(x2);
            }
            else
            {
                System.out.println("The solutions are real and distinct");
                double x1 = (-b-z)/(2*a);
                double x2 = (-b+z)/(2*a);
                System.out.println(x1);
                System.out.println(x2);
            }
        }
    }
}
