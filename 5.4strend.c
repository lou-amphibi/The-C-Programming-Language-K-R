#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char s[25]="May!Cloud me?";
    char t[25]="Cloud me?";
    printf("%d\n", strend(s, t));
}


int strend(char *s, char *t)
{
    int i=0;
    while (*s!='\0')
    {
        s++;
    }
    while (*t!='\0')
    {
        t++;
        i++;
    }
    for (; *s == *t; s--, t--, i--)
    {
        if (i==0)
            return 1;
    }
    return 0;
}



