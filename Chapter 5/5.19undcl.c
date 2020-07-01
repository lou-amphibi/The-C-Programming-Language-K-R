#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};


int gettoken(void);
int tokentype;           /* тип последней лексемы */
char token[MAXTOKEN];    /* текст последней лексемы */
char out[1000];          /* выдаваемый текст */


int main()
{
    int type;
    char temp[MAXTOKEN];
    int prevtype;
    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
        {
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*' ) {
                if (isalpha(*out))
                {
                    sprintf(temp, "*%s", out);
                    strcpy(out, temp);
                }
                else
                {
                    sprintf(temp, "*(%s)", out);
                    strcpy(out, temp);
                }
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf( "неверный элемент %s в фразе\n", token);
        }
        printf("%s\n", out);
    }
    return 0;
}

int gettoken(void) /* возвращает следующую лексему */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c=='{' || c=='}')
    {
        puts("Фигурные скобки не присутствуют в объявлении");
    }
    if (c == '(')
    {
        if ((c = getch())== ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            if (c == ' ')
            {
                while(isspace(c=getch()) )
                ;
                if (c==')')
                {
                    strcpy(token, "()");
                    return tokentype = PARENS;
                }
            }
            else
                ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
        {
            if (*--p=='\n')
                puts("Ожидалась \']\'");
        }
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
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