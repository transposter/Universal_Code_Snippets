/*
  * C program to find the sum of all digits present in the string
  */
#include <stdio.h>
void main()
{
    char string[80];
    int count, nc = 0, sum = 0;
    printf("Enter the string containing both digits and alphabet
           ");
           scanf("%s", string);
           for (count = 0; string[count] != ''; count++)
    {
        if ((string[count] >= '0') && (string[count] <= '9'))
                {
                    nc += 1;
                    sum += (string[count] - '0');
                }
        }
    printf("NO. of Digits in the string = %d
           ", nc);
           printf("Sum of all digits = %d
                  ", sum);
}

       Enter the string containing both digits and alphabet
       hello100
       NO. of Digits in the string = 3
                                     Sum of all digits = 1 " android:lineSpacingExtra="5dp"