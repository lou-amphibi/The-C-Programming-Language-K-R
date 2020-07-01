#include <stdio.h>

void reverce(char mass[], int a);

int main()
{
    int c, i=0;
    char s[120]=" ";
    while((c=getchar())!=EOF)
    {
        s[i]=c;
        i++;
    }
    reverce(s, i);
    putchar('\n');
}

void reverce(char mass[], int a)
{
    int g;
    if (mass[a-1]!='\n')
    {
        mass[a]='\n';
    }
    else if (mass[a-1]=='\n')
    {
        a-=2;
    }
    for(g=a; g>=0; g--)
    {
        putchar(mass[g]);
    }
}

/*
    if (s[i-1]!='\n')
    {
        s[i]='\n';
    }
    else if (s[i-1]=='\n')
    {
        i-=2;
    }
    for(g=i; g>=0; g--)
    {
        putchar(s[g]);
        */