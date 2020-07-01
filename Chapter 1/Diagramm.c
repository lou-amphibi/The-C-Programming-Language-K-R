#include <stdio.h>

int main()
{
    int c, len=0;
    while ((c=getchar())!=EOF)
    {
        if (c!=' ' && c!='\t' && c!='\n' && ( ((c>='a' && c<='z') || (c>='A' && c<='Z')) || (c>='0' && c<='9') ))
        {
            putchar('_');
            len++;
        }
        else if(c==' ' || c=='\t' || c=='\n')
        {
            c='\n';
            printf(" %d Символы", len);
            len=0;
            putchar(c);
        }
    }
}

