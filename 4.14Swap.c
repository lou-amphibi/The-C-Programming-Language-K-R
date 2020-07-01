#include <stdio.h>
#define swap(t,x,y) t temp=x; x=y; y=temp;

int main()
{
    int x=3;
    int y=4;
    swap(int, x, y);
    printf("x - %d и y - %d\n", x, y);
}



