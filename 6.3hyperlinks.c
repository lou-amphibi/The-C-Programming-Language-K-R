#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 100

struct nodes* swim(struct nodes *p, char *c, int i);

int getword (char *word, int lim);
char *cpystr(char *s);
void printnod(struct nodes *p);

struct nodes {
    int string;
    char *dbl;
    char *name;
    struct nodes *left;
    struct nodes *right;
};


int main()
{
    int str;
    int i=1;
    struct nodes *root=NULL;
    char names[MAXNAME];
    while ( (str=getword(names, MAXNAME))!=EOF)
    {
        root=swim(root, names, i);
        if (str=='\n')
            i++;
    }
    printnod(root);
    free(root);
}

void itoa(int n, char s[]);
struct nodes* swim(struct nodes *p, char *c, int i)
{
    int how;
    char dblstr[MAXNAME];
    if (p==NULL)
    {
        p=(struct nodes *) malloc(sizeof(struct nodes));
        p->name=cpystr(c);
        p->string=i;
        p->dbl=malloc(strlen(dblstr)+1);
        p->dbl[0]='\0';
        p->left = p->right = NULL;
    }
    else
    {
        if ( (how=(strcmp(c, p->name))) < 0)
        {
            p->left=swim(p->left, c, i);
        }
        else if (how>0)
        {
            p->right=swim(p->right, c, i);
        }
        else
        {
            itoa(i, dblstr);
            strcat(p->dbl, ",");
            strcat(p->dbl, dblstr);
        }

    }
    return p;
}


void printnod(struct nodes *p)
{
    if (p!=NULL)
    {
        printnod(p->left);
        if (p->name[0]!='\0')
            printf("%s - строка %d%s\n", p->name, p->string, p->dbl);
        printnod(p->right);
    }
}



char *cpystr(char *s)
{
    char *p;
    p=(char *) malloc(strlen(s)+1);
    strcpy(p, s);
    return p;
}

int getch(void);
void ungetch(int);
int isutility(char c);
int comlit(char c);
int noizewords(char *s);

int getword (char *word, int lim)
{
    int c;
    int n;
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
        if (!isalnum(*w = getch()) && *w!='_')
        {
            ungetch(*w);
            break;
        }
    n=*w;
    *w = '\0';
    if (noizewords(word))
        word[0]='\0';
    if (n=='\n')
        return n;
    return word[0];
}

int noizewords(char *s)
{
    if ( strcmp("or", s)==0  || strcmp(s, "and")==0 || strcmp(s, "the")==0 || strcmp(s, "a")==0 || strcmp(s, "an")==0 || strcmp(s, "is")==0 )
    {
        return 1;
    }
    else
        return 0;
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
    char outside[MAXNAME];
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

void reverse(char s[]);
void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }