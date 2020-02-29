/*
 * C Program to Count the Number of Bits needed to be Flipped
 * to Integer X to Generate Integer Y
 */
#include <stdio.h>
#include <stdlib.h>
#define NUM_BITS_INT (sizeof(int)*8)

void main()
{
    int n, m, i, count = 0, a, b;
    printf("Enter the number\n");
    scanf("%d", &n);
    printf("Enter another number\n");
    scanf("%d", &m);
    for (i = NUM_BITS_INT-1; i >= 0; i--)
        {
            a = (n >> i)& 1;
            b = (m >> i)& 1;
            if (a != b)
                count++;
        }
    printf("flip count = %d\n", count);
}