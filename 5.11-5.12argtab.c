#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 3

void entab(char b[], int a, int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int c, i=0;
    char s[120]=" ";
    while ((c=getchar())!=EOF)
    {
        s[i]=c;
        i++;
    }
    putchar('\n');
    entab(s, i, argc, argv);
}

void entab(char b[], int a, int argc, char *argv[])
{
 int j=0, h, k=0;
 int n=N, c;
 int y=1;

 int marg=0, reload=0;
 // Первый аргумент
 if (argc!=1)
 {
 if( (*(argv+1))[0]=='-')
 {
    if( isdigit( (*(argv+1))[1]))
    {
        marg=( (*(argv+1))[1])-'0';
        reload=1;
    }
    else
        puts("Неверная команда");
 }
 }
 // Второй аргумент
 if (argc!=2)
 {
 if( (*(argv+2))[0]=='+')
 {
    if( isdigit( (*(argv+2))[1]))
    {
        n=( (*(argv+2))[1])-'0';
    }
    else
        puts("Неверная команда");
 }
 else if (reload==1 &&  isdigit( (*(argv+2))[0]))
    puts("Необходим + перед вторым аргументом иначе set to default");
 }

 for (int i=0; i<a; i++)
 {
     if (b[i]==' ' && i>marg)
     {
        if (argc!=1 && reload!=1)
        {
            if ((c=atof(*(argv+y)))!=0)
            {
                n=c;
                y++;
                y=(y>argc-1) ? 1 : y;
            }
        }
         for (j=0; b[i]==' '; i++)
         {
          j++;
          if (j%n==0 && j>0)
          {
              putchar('^');
          }
         }
         if (j%n!=0 && j>0)
         {
             h=j%n;
             for (k=h; k>0; k--)
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



