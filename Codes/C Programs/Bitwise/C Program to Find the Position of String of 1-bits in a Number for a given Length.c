/*
 * C Program to Find the Position of String of 1-bits in a Number
 * for a given Length
 */
#include <stdio.h>

void main()
{
    int n, len, pos = 0, i = 0, count = 0;
    printf("**Finding the position of 1-bits in a number for given length**\n");
    printf("enter a number\n");
    scanf("%d", &n);
    printf("enter the length\n");
    scanf("%d", &len);
    while (i <= 32)
        {
            if ((n & 1) ==  1)    //checking whether there is a 1-bit in the current position
                {
                    count++;//counting the consecutive 1's in the integer
                    pos = i;
                    if (count ==  len)    //checking whether the length matches
                        {
                            break;
                        }
                }
            if ((n & 1) ==  0)
                {
                    count = 0;
                }
            n = n>>1;
            i++;
        }
    printf("the position of 1 in the string : %d\n", pos);
}