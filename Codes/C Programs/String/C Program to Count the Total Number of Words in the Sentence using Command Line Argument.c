/*
 * C Program to Count Number of Words in a given Text Or Sentence
 */
#include <stdio.h>
#include <string.h>

void main()
{
    char s[200];
    int count = 0, i;
    printf("enter the string\n");
    scanf("%[^\n]s", s);
    for (i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == ' ')
                count++;
        }
    printf("number of words in given string are: %d\n", count + 1);
}
/*
*OUTPUT:
enter the string
welcome to sanfoundry's c-programming class!
number of words in given string are: 5
*/