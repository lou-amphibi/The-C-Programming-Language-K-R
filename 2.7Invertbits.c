#include <stdio.h>

unsigned int invertbit(unsigned int x, int p, int n);

int main()
{
    unsigned int x=101;
    unsigned int a=invertbit(x, 5, 4);
    printf("%d\n", a);
}


unsigned int invertbit(unsigned int x, int p, int n)
{
    unsigned a, b, c, r;
    a=(x>>(p-(n-1)))& ~(~0 << n);
    a=(~a)& ~(~0 << n);
    a=a<<(p-(n-1));
    b=(x&(~0<<(p+1)))|a;
    c=x& ~(~0<< (p-(n-1)));
    r=b|c;
    return r;
}