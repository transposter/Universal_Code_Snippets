/*This C Program inserts an element in a specified position in a given array. Program takes a user input and inserts the desired element in the specified position.*/

/*
 * C program to insert a particular element in a specified position
 * in a given array
 */
#include <stdio.h>

void main()
{
    int array[10];
    int i, j, n, m, temp, key, pos;
    printf("Enter how many elements \n");
    scanf("%d", &n);
    printf("Enter the elements \n");
    for (i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }
    printf("Input array elements are \n");
    for (i = 0; i < n; i++)
        {
            printf("%d\n", array[i]);
        }
    for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
                {
                    if (array[i] > array[j])
                        {
                            temp = array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                }
        }
    printf("Sorted list is \n");
    for (i = 0; i < n; i++)
        {
            printf("%d\n", array[i]);
        }
    printf("Enter the element to be inserted \n");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
        {
            if (key < array[i])
                {
                    pos = i;
                    break;
                }
            if (key > array[n-1])
                {
                    pos = n;
                    break;
                }
        }
    if (pos != n)
        {
            m = n - pos + 1 ;
            for (i = 0; i <= m; i++)
                {
                    array[n - i + 2] = array[n - i + 1] ;
                }
        }
    array[pos] = key;
    printf("Final list is \n");
    for (i = 0; i < n + 1; i++)
        {
            printf("%d\n", array[i]);
        }
}

/*

Enter how many elements
5
Enter the elements
76
90
56
78
12
Input array elements are
76
90
56
78
12
Sorted list is
12
56
76
78
90
Enter the element to be inserted
61
Final list is
12
56
61
76
78
90