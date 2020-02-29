/*
 * C Program to Find the Number of Non Repeated Elements in an Array
 */
#include <stdio.h>
int main()
{
    int array[50];
    int *ptr;
    int i, j, k, size, n;
    printf("\n Enter size of the array: ");
    scanf("%d", &n);
    printf("\n Enter %d elements of an array: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    size = n;
    ptr = array;
    for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
                {
                    if (i == j)
                        {
                            continue;
                        }
                    else if (*(ptr + i) == *(ptr + j))
                        {
                            k = j;
                            size--;
                            while (k < size)
                                {
                                    *(ptr + k) = *(ptr + k + 1);
                                    k++;
                                }
                            j = 0;
                        }
                }
        }
    printf("\n The array after removing duplicates is: ");
    for (i = 0; i < size; i++)
        {
            printf(" %d", array[i]);
        }
    return 0;
}

/*

Enter size of the array: 6

Enter 6 elements of an array: 12
10
4
10
12
56

The array after removing duplicates is:  12 10 4 56