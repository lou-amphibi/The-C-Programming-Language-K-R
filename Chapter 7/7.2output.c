#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c;
    int i=0;
    if (argc<2)
    {
        puts("Error");
        exit(1);
    }
    while((c=getchar())!=EOF)
    {
    if( strcmp(argv[1], "1")==0 )
    {
        printf("%c", c);
        i++;
        if (i>14 && c==' ')
        {
            putchar('\n');
            i=0;
        }
    }
    else if ( strcmp(argv[1], "16")==0 )
    {
        printf("%x", c);
        i++;
        if (c==' ')
        {
            putchar('\n');
            i=0;
        }
    }
    else
        puts("Wrong argment");
    }
}
