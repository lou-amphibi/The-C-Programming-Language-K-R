#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 10

int main(int argc, char *argv[])
{
    int c, i=0, st=0, g;
    int j, y=1, n=N;
    char s[120]=" ";
    int marg=0, reload=0;
    // первый аргумент
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
    // второй аргумент
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
    // Стоп табуляции
    if (reload!=1)
        n=(argc!=1) ? atof(*(argv+y)) : N;
    // Цикл обработки
    while ((c=getchar())!=EOF)
    {
        if (c!='\t' || i<marg)
        {
            s[i]=c;
            if (i>=marg)
                st++;
            i++;
            if (st>=n)
            {
                st=0;
            }
        }
        else if (c=='\t' && i>marg)
        {
            if (argc!=1 && reload!=1)
            {
                if ((j=atof(*(argv+y)))!=0)
                {
                    n=j;
                    y++;
                    y=(y>argc-1) ? 1 : y;
                }
            }
            for (g=n-st; g>0; g--)
            {
                s[i]='|';
                i++;
            }
            st=0;
        }
    }
    printf("\n%s-\n", s);
}