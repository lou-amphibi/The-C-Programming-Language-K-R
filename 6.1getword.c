#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NKEYS (sizeof keytab / sizeof(struct key))

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];

    while(getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: найти слово в tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;


    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low + high)/2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getch(void);
void ungetch(int);
int isutility(char c);
int comlit(char c);

int getword (char *word, int lim)
{
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isutility(c))
        return comlit(c);
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w!='_') {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

int isutility(char c)
{
    if (c=='\"' || c=='/' || c=='#')
        return 1;
    else
        return 0;
}

int comlit(char c)
{
    char outside[MAXWORD];
    char *u=outside;
    int a=c;
    // Строковый литерал
    if (a=='\"')
    {
        while( (a=getch())!='\"' )
            *u++=a;
        *u='\0';
        return c;
    }
    // Комментарии
    if (a=='/')
    {
        a=getch();
        if (a=='/')
        {
        while( (a=getch())!='\n' )
            *u++=a;
        *u='\0';
        return c;
        }
        else if (a=='*')
        {
            while( (a=getch())!='*' )
                *u++=a;
            if ( (a=getch())=='/' )
            {
                *u='\0';
                return c;
            }
        }
        else
        {
            ungetch(a);
            return a;
        }
    }
    // Препроцессор
    if (a=='#')
    {
        while( (a=getch())!=' ' )
            *u++=a;
        *u='\0';
        if ( (strcmp("include", outside))==0 || (strcmp("define", outside))==0 )
        {
            while ( (a=getch())!='\n' )
                ;
            return c;
        }
    }
    return 0;
}


#define BUFSIZE 100

char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */

int getch(void)       /* взять (возможно возвращенный) символ */
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
