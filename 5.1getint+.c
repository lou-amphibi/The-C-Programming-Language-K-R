#include <stdio.h>
#define SIZE 100


int main()
{
    int n, getint (int *);
    int array[SIZE];
    for (n = 0; n < SIZE && getint (&array[n]) != EOF; n++)
        ;
    for(int i=0; i<=n; i++)
        printf("\n array - %d\n", array[i]);
}


#include <ctype.h>

int getch (void);
void ungetch (int);
/* getint: читает следующее целое из ввода в *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ; /* пропуск символов-разделителей */
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
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