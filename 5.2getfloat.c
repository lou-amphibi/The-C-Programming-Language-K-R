#include <stdio.h>
#define SIZE 100


int main()
{
    int n;
    int getfloat (float *);
    float array[SIZE];
    for (n = 0; n < SIZE && getfloat (&array[n]) != EOF; n++)
        ;
    for(int i=0; i<=n; i++)
        printf("\n array - %g\n", array[i]);
}


#include <ctype.h>

int getch (void);
void ungetch (int);
/* getint: читает следующее целое из ввода в *pn */
int getfloat(float *pn)
{
    int c, sign, point=1;

    while (isspace(c = getch()))
        ; /* пропуск символов-разделителей */
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c!='.') {
        c=getch(); // Вместе они работают, один ангетч нет.
        ungetch (c);
        return 0;
    }
    sign =(c =='-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c))
        {
            ungetch (c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c -'0');
    if (c=='.')
    {
        c=getch();
        if (!isdigit(c))
        {
            ungetch (c);
            return 0;
        }

    }
    if(isdigit(c)) {
    for (; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c -'0');
        point*=10;
    }
    *pn/=point;
    }
    *pn *= sign;
    if (c!= EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */



int getch(void)
{
   return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)   /* вернуть символ на ввод */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}