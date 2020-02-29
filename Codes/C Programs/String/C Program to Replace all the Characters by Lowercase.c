/*
 * C Program to Replace all the Characters by Lowercase
 */
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[])
{
    FILE *fp1;
    int ch;
    if ((fp1 = fopen(argv[1], "r+")) == NULL)
        {
            printf("\nfile cant be opened");
            exit(0);
        }
    ch = fgetc(fp1);
    while (ch != EOF)
        {
            if (ch >= 65 && ch <= 90)
                {
                    fseek(fp1, -1L, 1);
                    fputc(ch + 32, fp1);
                }
            ch = fgetc(fp1);
        }
}
/*
*OUTPUT:
$ cat file4test
CHANDANA chanikya
rAVELLA
$ cc file4.c
$ a.out file4test
$ cat file4test
chandana chanikya
ravella
*/