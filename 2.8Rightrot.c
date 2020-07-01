#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main()
{
    unsigned int x=101;
    unsigned int j=rightrot(x, 5);
    printf("%d\n", j);
}

unsigned int rightrot(unsigned int x, int n)
{
    unsigned int a, b, c;
    int y=1;
    unsigned int f=x;
    b=x>>1;
    while(b!=0)
    {
        f=f|b;
        b=b>>1;
    }
    a=1;
    a=(f^a)>>1;
    a=a^f;
    for (int i=n; i>0; i--)
    {
        c=x& ~(~0<< y);
        if (c==1)
        {
            x=x>>1;
            x=x|a;
        }
        else if(c==0)
        {
            x=x>>1;
        }
    }
    return x;
}