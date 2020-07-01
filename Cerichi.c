#include <stdio.h>

int main()
{
int c, b;
b='r';
while((c=getchar())!=EOF)
{
    if (c!=' ' || b!=' ')
    {
        putchar(c);
        b=c;
    }
}
}
