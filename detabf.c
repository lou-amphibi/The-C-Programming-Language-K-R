#include <stdio.h>
#define N 10

void detab(char b[]);

int main()
{
    int c, i=0;
    char s[120]=" ";
    while ((c=getchar())!=EOF)
    {
        s[i]=c;
        i++;
    }
    detab(s);
    printf("\n%s-\n", s);
}


void detab(char b[])
{
    int st=0, g=0, i=0, l=0, h=0;
    for (i=0; b[i]!='\0'; i++)
    {
     ;
    }
    for(int j=0; j<i; j++)
    {
        if (b[j]!='\t')
        {
            st++;
            if (st>=N)
            {
                st=0;
            }
        }
        else if (b[j]=='\t')
        {
                h=(N-st)-1;
                l=i-1;
                for (int k=l; k>j; k--)
                {
                    b[l+h]=b[l];
                    l--;
                }
                i+=h;
            for (g=N-st; g>0; g--)
            {
                b[j]='|';
                j++;
            }
            j-=1;
            st=0;
        }
    }
}




