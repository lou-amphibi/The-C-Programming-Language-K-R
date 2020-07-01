#include <stdio.h>

char *strncpyp(char *s, char *t, int n);
char *strncatp(char *s, char *t, int n);
int stringcmpp(char *s, char *t, int n);

int main()
{
    char s[20]="Matilda";
    char t[20]="Yes or No";
    printf("%s\n", strncpyp(s, t, 3));
    printf("%s\n", strncatp(s, t, 5));
    char a[20]="Boriiis";
    char b[20]="Basta";
    printf("%d\n", stringcmpp(a, b, 3));
}


char *strncpyp(char *s, char *t, int n)
{
    char *r=&s[0];
    while (*s++!='\0')
    ;
    for (s--; n>0; n--)
    {
        *s++=*t++;
    }
    return r;
}


char *strncatp(char *s, char *t, int n)
{
    char *c=&s[0];
    while(*s++!='\0')
    ;
    for (s--; *t!='\0' && n>0; n--)
    {
        *s++=*t++;
    }
    *s='\0';
    return c;
}

int stringcmpp(char *s, char *t, int n)
{
    for(; *s==*t && n>0; s++, t++, n--)
    ;
    if(n==0)
        return 0;
    return *s-*t;
}