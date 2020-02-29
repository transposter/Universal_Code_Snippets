/*
This is a Java Program to Implement Fermat Primality Test Algorithm. Fermat Primality Test is an algorithm which is used to determine if a given number is prime or not.
*/

/**
 ** Java Program to Implement Fermat Primality Test Algorithm
 **/

import java.util.Scanner;
import java.util.Random;

/** Class FermatPrimality **/
public class FermatPrimality
{
    /** Function to check if prime or not **/
    public boolean isPrime(long n, int iteration)
    {
        /** base case **/
        if (n == 0 || n == 1)
            return false;
        /** base case - 2 is prime **/
        if (n == 2)
            return true;
        /** an even number other than 2 is composite **/
        if (n % 2 == 0)
            return false;
        Random rand = new Random();
        for (int i = 0; i < iteration; i++)
            {
                long r = Math.abs(rand.nextLong());
                long a = r % (n - 1) + 1;
                if (modPow(a, n - 1, n) != 1)
                    return false;
            }
        return true;
    }
    /** Function to calculate (a ^ b) % c **/
    public long modPow(long a, long b, long c)
    {
        long res = 1;
        for (int i = 0; i < b; i++)
            {
                res *= a;
                res %= c;
            }
        return res % c;
    }
    /** Main function **/
    public static void main (String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Fermat Primality Algorithm Test\n");
        /** Make an object of FermatPrimality class **/
        FermatPrimality fp = new FermatPrimality();
        /** Accept number **/
        System.out.println("Enter number\n");
        long num = scan.nextLong();
        /** Accept number of iterations **/
        System.out.println("\nEnter number of iterations");
        int k = scan.nextInt();
        /** check if prime **/
        boolean prime = fp.isPrime(num, k);
        if (prime)
            System.out.println("\n"+ num +" is prime");
        else
            System.out.println("\n"+ num +" is composite");
    }
}

/*
Enter number

999983

Enter number of iterations
2

999983 is prime