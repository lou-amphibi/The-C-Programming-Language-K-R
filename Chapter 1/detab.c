#include <stdio.h>
#define N 10

int main()
{
    int c, i=0, st=0, g;
    char s[120]=" ";
    while ((c=getchar())!=EOF)
    {
        if (c!='\t')
        {
            s[i]=c;
            st++;
            i++;
            if (st>=N)
            {
                st=0;
            }
        }
        else if (c=='\t')
        {
            for (g=N-st; g>0; g--)
            {
                s[i]='|';
                i++;
            }
            st=0;
        }
    }
    printf("\n%s-\n", s);
}