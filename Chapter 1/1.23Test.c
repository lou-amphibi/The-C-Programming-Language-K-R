#include <stdio.h>


int main()
{
    int a=5;
    char ro[8]="Gordox";
    int b=a*3;
    printf("Ya ne synapsid %d\n", b);
    b=b/3;
    a=4; 
    printf("%s\n", ro);
    for (int j=0; j<6; j++)
    {
        printf("%c", ro[j]);
    }
    putchar('\n');
    ro[2]=0; 
    ro[3]=0;
    for (int j=0; j<6; j++)
    {
        printf("%c", ro[j]);
    }
    putchar('\n');
    putchar(ro[2]);
    putchar('\n');
    putchar(ro[3]);
    putchar('\n');
    printf("/* коммент*/");
    printf("// коммент 2");
}