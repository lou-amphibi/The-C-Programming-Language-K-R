#include <stdio.h>
#define N 3

void entab(char b[], int a);

int main()
{
    int c, i=0;
    char s[120]=" ";
    while ((c=getchar())!=EOF)
    {
        s[i]=c;
        i++;
    }
    putchar('\n');
    entab(s, i);
}

void entab(char b[], int a)
{
 int j=0, h, k;
 for (int i=0; i<a; i++)
 {
     if (b[i]==' ')
     {
         for (j=0; b[i]==' '; j++)
         {
          i++;
         }
         h=j/N;
         k=j-(h*N);
        if (h>0)
        {
            for (int g=h; g>0; g--)
        {
                putchar('^');
        }
        }
        if (k>0)
        {
            for (int y=k; y>0; y--)
            {
                putchar(' ');
            }
        }
     j=0;
     i--;
     }
     else
     {
         putchar(b[i]);
     }
    }
putchar('\n');
}