#include <stdio.h>

void strcatp(char *s, char *t);

int main()
{
    char s[20]="May!";
    char t[10]="Cloud me?";
    strcatp(s, t);
    printf("%s\n", s);
}


void strcatp(char *s, char *t)
{
    while(*t!='\0')
    {
        while(*s!='\0')
        {
            s++;
        }
        *s++=*t++;
    }
}