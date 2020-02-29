/*
 * C program to find the simple interest, given principal,
 * rate of interest and time.
 */
#include <stdio.h>

void main()
{
    float principal_amt, rate, simple_interest;
    int time;
    printf("Enter the values of principal_amt, rate and time \n");
    scanf("%f %f %d", &principal_amt, &rate, &time);
    simple_interest = (principal_amt * rate * time) / 100.0;
    printf("Amount = Rs. %5.2f\n", principal_amt);
    printf("Rate = Rs. %5.2f%\n", rate);
    printf("Time = %d years\n", time);
    printf("Simple interest = %5.2f\n", simple_interest);
}