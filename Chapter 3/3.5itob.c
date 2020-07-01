#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itob(long int n, char s[], int b);

int main()
{
    char s[600]=" ";
    long int c=125;
    itob(c, s, 16);
    printf("%s\n", s);
}


void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(long int n, char s[], int b)
{
    long int i, sign;
    if ((sign = n) < 0)
    {
    n = ~n-1;
    }
    i = 0;
    do {
    s[i++] = n %b + '0';
    if( (n%b)>9)
    {
        s[i-1]+='\'';
    }
    } while ((n /= b) > 0);
    if (sign < 0)
    {
        s[i++] = '-';
        s[0]+=2;
    }
    s[i] = '\0';
    reverse(s);
}