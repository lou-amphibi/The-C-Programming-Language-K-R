#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned int x=46;
    unsigned int y=162;
    unsigned int a=setbits(x, 4, 3, y);
    printf("%d\n", a);

}



unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned int a, b, r;
    y=(y & ~(~0<<n))<<(p-(n-1));
    a=(x&(~0<<(p+1)))|y;
    b=x& ~(~0<< (p-(n-1)));
    r=a|b;
    return r;
}