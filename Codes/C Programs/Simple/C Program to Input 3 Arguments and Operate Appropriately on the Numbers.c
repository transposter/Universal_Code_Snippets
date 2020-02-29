/*
 * C Program to Input 3 Arguments and Operate Appropriately on the
 * Numbers
 */
#include <stdio.h>

void main(int argc, char * argv[])
{
    int a, b, result;
    char ch;
    printf("arguments entered: \n");
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    ch  = *argv[3];
    printf("%d %d %c", a, b, ch);
    switch (ch)
        {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case 'x':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            printf("Enter a valid choice");
        }
    printf("\nThe result of the operation is %d", result);
    printf("\n");
}