#include <stdio.h>

int main()
{
    int c, i=0;
    char b='r', act[120]="s";
    while((c=getchar())!=EOF)
    {
        if (c=='\t')
        {
        c=' ';
        }
        if ((c!=' ' || b!= ' ') && (c!='\n' || b!= '\n'))
        {
            act[i]=c;
            b=c;
            i++;
        }
    }
printf("\n%s\n", act);
}