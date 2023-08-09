/* Write a java program to make rolling a die 10,000 times and counts the number of times each face has rolled Hint: Math.random() */
package edu.aiml;
import java.util.Random;
public class RollDice
{
    public static void main( String[ ] args)
    {
        Random randomNumbers = new Random();
        int frequency1 = 0;
        int frequency2 = 0;
        int frequency3 = 0;
        int frequency4 = 0;
        int frequency5 = 0;
        int frequency6 = 0;
        for ( int roll = 1; roll <= 10000; roll++ )
        {
            int face = 1 + randomNumbers.nextInt(6);
            switch (face) {
                case 1 -> ++frequency1;
                case 2 -> ++frequency2;
                case 3 -> ++frequency3;
                case 4 -> ++frequency4;
                case 5 -> ++frequency5;
                case 6 -> ++frequency6;
            }
        }
        System.out.println( "Face \t Frequency" );
        System.out.printf("1\t%d   \n2\t%d   \n3\t%d     \n4\t%d      \n5\t%d     \n6\t%d \n" , frequency1, frequency2, frequency3, frequency4,frequency5, frequency6 );
    }
}