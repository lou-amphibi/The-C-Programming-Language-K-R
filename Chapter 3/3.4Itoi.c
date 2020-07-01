#include <stdio.h>
#include <string.h>


void itoa(long int n, char s[]);
void reverse(char s[]);

int main()
{
    long int n=-248;
    char s[400]=" ";
    itoa(n, s);
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

void itoa(long int n, char s[])
{
    long int i, sign;
    if ((sign = n) < 0) /* сохраняем знак */
    n = ~n-1;                 /* делаем n положительным */
    i = 0;
    do { /* генерируем цифры в обратном порядке */
    s[i++] = n %10 + '0'; /* следующая цифра */
    } while ((n /= 10) > 0); /* исключить ее */
    if (sign < 0)
    {
        s[i++] = '-';
        s[0]+=2;
    }
    s[i] = '\0';
    reverse(s);
}