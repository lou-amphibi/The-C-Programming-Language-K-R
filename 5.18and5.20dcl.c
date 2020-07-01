#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS, ARGUMENTS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;           /* тип последней лексемы */
char token[MAXTOKEN];    /* текст последней лексемы */
char name[MAXTOKEN];     /* имя */
char datatype[MAXTOKEN]; /* тип = char, int и т.д. */
char out[1000];          /* выдаваемый текст */
char farguments[MAXTOKEN];

void deletetoken(char s[], char t[]);
void getdata(void);

int main() /* преобразование объявления в словесное описание */
{
    start:
    getdata();
    while (gettoken() != EOF) {  /* 1-я лексема в строке */
        out[0] = '\0';
        dcl();                   /* разбор остальной части строки */
        if (tokentype != '\n')
          printf("синтаксическая ошибка\n");
        deletetoken(datatype, name);
        if ( !(isalpha(*datatype)))
            strcpy(datatype, "void");
        printf("%s: %s %s %s\n", name, out, datatype, farguments);
        farguments[0] = '\0';
        goto start;
    }
    return 0;
}

int  getch(void);
void ungetch(int);
int dataname=0;
int arg=0;


void getdata(void)
{
    int c;
    char *n=datatype;
    while ((c = getch()) == ' ' || c == '\t')
    ;
    if (isalpha(c) )
    {
        for (*n++ = c; isalpha(c = getch()) || c==' '; )
            *n++ = c;
        *n = '\0';
        dataname=1;
        arg=1;
    }
    else
        datatype[0]='\0';
    ungetch(c);
}

void getname(void)
{
    int i=strlen(datatype);
    int j=0, y=0;
    while (datatype[i]!=' ' && i>0)
        i--;
    for (; datatype[i]!='\0'; i++, y++)
        name[y]=datatype[i];
    name[y]='\0';
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
            else if( (isalpha(c) && arg==1) )
            {
                for (*p++ = c; (c=getch() )!= ')'; )
                {
                *p++ = c;
                }
                *p = '\0';
                arg=0;
                return tokentype = ARGUMENTS;
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
            if (*p=='\n')
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



/* dcl: разбор объявителя */
void dcl(void)
{
    int ns=0;
    int c, a;
    if (tokentype!=NAME && arg==1)
        arg=0;
    if (tokentype=='*')
        ns++;
    if (tokentype==BRACKETS)
    {
    strcat(out, " массив");
    strcat(out, token);
    strcat(out, " из");
    }
    if (tokentype==PARENS)
    {
        strcat(out, "фнкц. возвр.");
    }
    if ( (tokentype=='(' && arg==1) || (tokentype==ARGUMENTS) )
    {
        char steck[MAXTOKEN];
        char *k=steck;
        if ( isalpha(a=getch()) )
        {
            strcat(out, "функц. возвр.");
            strcat(farguments, " аргументы функции ");
            for (*k++ = a; isalpha(a = getch()) || a==' ' || a==','; )
                *k++ = a;
        *k = '\0';
        strcat(farguments, steck);
        arg=0;
        }
        else if (tokentype==ARGUMENTS)
        {
            strcat(out, "функц. возвр.");
            strcat(farguments, "аргументы функции ");
            strcat(farguments, token);
        }
        ungetch(a);
    }
    for (; (c=gettoken()) == '*';) /* подсчет звездочек */
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out, "указ. на");
}



/* dirdcl: разбор собственно объявителя */
void dirdcl(void)
{
    int type;
    int br=0;

    if (tokentype!=NAME && arg==1)
        arg=0;

    if (tokentype == '(') {
        dcl();
        if (tokentype != ')')
        {
          printf("oшибкa: пропущена )\n");
        }
    }
    else if (tokentype == NAME || dataname==1) /* имя переменной */
    {
        arg=1;
        if (dataname==1 && tokentype!=NAME)
        {
            getname();
            dataname=0;
        }
        else
            strcpy(name, token);
    }
    else
    {
        printf("ошибка: должно быть name или (dcl)\n");
    }
    while((type = gettoken()) == PARENS || type == BRACKETS || type == ARGUMENTS)
        if (type == PARENS)
            strcat(out, "функц. возвр.");
        else if (type==ARGUMENTS)
        {
            strcat(out, "функц. возвр.");
            strcat(farguments, "аргументы функции ");
            strcat(farguments, token);
        }
        else {
            strcat(out, " массив");
            strcat(out, token);
            strcat(out, " из");
        }

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


void deletetoken(char s[], char t[])
{
    int i=strlen(s);
    int j=strlen(t);
    while ((s[i]==t[j]) && (i>=0))
    {
        i--;
        j--;
    }
    if (j==-1)
        s[i+1]='\0';
}

