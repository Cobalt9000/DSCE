// Write a Java program to display fibonacci series using method overloading
package edu.aiml;
import java.util.*;

public class FibonacciSeries
{
    public static void main(String[] args)
    {
        int terms, last = 1, secondLast = 0, current;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter number of terms in Fibonacci Series");
        terms = in.nextInt();
        for(int i = 0; i < terms; i++)
        {
            if(i < 2)
            {
                current = i;
            }
            else
            {
                current = last + secondLast;
                secondLast = last;
                last = current;
            }
            System.out.print(current + " ");
        }
    }
}
