#include <stdio.h>
#include <string.h>
void reversrec(char b[], int i, int j);
void reversbit(int b[], int i, int j);

int main()
{
    char b[10]="12345";
    int i = strlen(b);
    i-=1;
    reversrec(b, i, 0);
    printf("%s\n", b);
    int c[]={2, 3 , 4, 5};
    reversbit(c, i, 0);
    for(int j=0; j<4; j++)
    {
        printf("%d", c[j]);
    }
    putchar('\n');
}

void reversrec(char b[], int i, int j)
{
    int tab;
    if (j<i)
    {
        tab=b[j];
        b[j]=b[i];
        b[i]=tab;
        reversrec(b, --i, ++j);
    }
}

void reversbit(int b[], int i, int j)
{
if (j<(i/2))
{
b[j] ^= b[i-j-1] ^= b[j] ^= b[i-j-1];
j++;
reversbit(b, i, j);
}
}