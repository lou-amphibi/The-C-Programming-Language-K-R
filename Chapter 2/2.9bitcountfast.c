#include <stdio.h>

int bitcountfast(int x);

int main()
{
    int x=475;
    int a=bitcountfast(x);
    printf("%d\n", a);
}


int bitcountfast(int x)
{
    int b=0;
    while(x!=0)
    {
        x&=(x-1);
        b++;
    }
    return b;
}