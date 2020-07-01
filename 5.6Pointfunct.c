#include <stdio.h>
#define MAXLINE 100

int getline(char *s, int lim);
int atoip(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex (char *s, char *t);
int getop(char *s);

int main()
{
    char str[MAXLINE];
    int c=getline(str, MAXLINE);
    printf("%s", str);
    printf("%d\n", c);

    char a[20]="1235";
    printf("%d\n", atoip(a));

    char b[15];
    itoa(5678, b);
    printf("%s\n", b);
    reverse(a);
    printf("Reverce %s\n", a);

    char co[10]="Krroool";
    char du[10]="ool";
    printf("Место с в d - %d\n", strindex(co, du));

    char get[30];
    int charat=getop(get);
    printf("%d и символ %c\n", charat, charat);


}


int getline(char *s, int lim)
{
    int c, i;
    for (i=0; --lim > 0 && (c=getchar()) != EOF && c != '\n'; i++) /* I.B.: misprint was here -lim instead of --lim */
        *s++ = c;
    if (c == '\n') {
        *s++ = c;
         i++;
    }
    *s = '\0';
    return i;
}

#include <ctype.h>

int atoip(char *s)
{
    int n, sign;
                             /* игнорировать символы-разделители */
    for (; isspace(*s); s++)
        ;
    sign = ( *s == '-' ) ? -1 : 1;
    if (*s == '+' || *s == '-') /* пропуск знака */
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}



void itoa(int n, char *s)
{
    int sign;
    char *r=&s[0];
    if ((sign = n) < 0) /* сохраняем знак */
        n =-n;                 /* делаем n положительным */
    do { /* генерируем цифры в обратном порядке */
    *s++ = n %10 + '0'; /* следующая цифра */
    } while ((n /= 10) > 0); /* исключить ее */
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
   reverse(r);
}



void reverse(char *s)
{
    int c, j=0, i;
    while (*s++!='\0') {
        j++;
    }
    s-=j+1;
    for (i=0, j-=1; i<j; i++, j--)
    {
        c=*(s+i);
        *(s+i)=*(s+j);
        *(s+j)=c;
    }
}


/* strindex: вычисляет место t в s или выдает -1, если t нет в s */
int strindex (char *s, char *t)
{
    int i, j, k;
    int sten=-1;
    for (i = 0; *(s+i) != '\0'; i++) {
        for (j = i, k = 0; *(t+k) != '\0' && *(s+j) == *(t+k); j++, k++)
             ;
        if (k > 0 && *(t+k) == '\0')
            return i;
    }
    return sten;
}


int getch(void);
void ungetch(int);


int getop(char *s)
{
    int i, c;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;    /* не число */
    i = 0;
    if (isdigit(c)) /* накапливаем целую часть */
        while (isdigit(*(s+i) = c = getch()))
            ;
    if (c =='.') /* накапливаем дробную часть */
    while (isdigit(*(s+i) = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return 0;
}

#define BUFSIZE 100
char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;

int getch(void)       /* взять (возможно возвращенный) символ */
{
    int c;
    if (bufp>0)
    {
        return buf[--bufp];  //return (bufp > 0) ? buf[--bufp] : (c!=EOF) ? c=getchar() : EOF;
    }
    else {
    if((c=getchar())!=EOF)
        return c;
    else
        return EOF; }
}


void ungetch(int c)   /* вернуть символ на ввод */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        if (c!=EOF)
        buf[bufp++] = c;
}