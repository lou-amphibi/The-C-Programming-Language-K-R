#include <stdio.h>

void reverce(char d[], int g);

int main()
{
    int c, i=0;
    char s[120]=" ";
    while((c=getchar())!=EOF)
    {
        s[i]=c;
        i++;
    }
    printf("\nСтрока без реверса: %s\n", s);
    reverce(s, i);
    printf("Строка после реверса: %s\n", s);
}

void reverce(char d[], int g)
{
    int i;
    char tab;
    g-=1;
    for (i=0; i<=g; i++)
    {
        tab=d[i];
        d[i]=d[g];
        d[g]=tab;
        g--;
    }
}