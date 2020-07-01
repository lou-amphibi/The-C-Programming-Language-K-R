#include <stdio.h>
void recursei(int n, char b[]);

int main()
{
    int a=2456781;
    char astr[15];
    recursei(a, astr);
    printf("%s\n", astr);
}


void recursei(int n, char b[])
{
    static int i=0;
    if (n<0)
    {
        b[0]='-';
        n=-n;
        i++;
    }
    if (n/10)
    {
        recursei(n/10, b);
    }
    b[i++]=n%10+'0';
    b[i]='\0';
}