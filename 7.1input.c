#include <string.h>
#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int c;
    if (argc>1)
    {
         puts("Programm cant have some arguments");
    }
    else
    {
        if(strcmp(argv[0], "./upper")==0)
        {
            while((c=getchar())!=EOF)
                putchar(toupper(c));
        }
        else if(strcmp(argv[0], "./lower")==0)
        {
            while((c=getchar())!=EOF)
                putchar(tolower(c));
        }
        else
         printf("Programm must be named \"upper\" or \"lower\" for do some effect, defolt name is - %s\n", argv[0]);
    }
}