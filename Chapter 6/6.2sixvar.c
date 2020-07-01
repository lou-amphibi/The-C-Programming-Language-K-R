#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 100
#define N 3

struct nodes* swim(struct nodes *p, char *c);
void example(struct nodes *p);
int getword (char *word, int lim);
char *cpystr(char *s);
int n;

struct nodes {
    int count;
    char *name;
    struct nodes *left;
    struct nodes *right;
} *pp;


int main(int argc, char *argv[])
{
    struct nodes *root=NULL;
    char names[MAXNAME];
    if (argc==2)
        n=atof(argv[1]);
    else if (argc==1)
    {
        n=N;
    }
    else
    {
        puts("Неверный аргумент");
        exit(1);
    }
    while ( getword(names, MAXNAME)!=EOF)
        root=swim(root, names);
    pp=root;
    example(root);
    free(root);
    free(pp);
}



struct nodes* swim(struct nodes *p, char *c)
{
    int how;
    if (p==NULL)
    {
        p=(struct nodes *) malloc(sizeof(struct nodes));
        p->name=cpystr(c);
        p->count=0;
        p->left = p->right = NULL;
    }
    else
    {
        if ( (how=(strcmp(c, p->name))) < 0)
        {
            p->left=swim(p->left, c);
        }
        else if (how>0)
        {
            p->right=swim(p->right, c);
        }
    }
    return p;
}

int group(struct nodes *p, char *s);
void printnod(struct nodes *p, char *s);
int b=0;

void example(struct nodes *p)
{
    char hood[MAXNAME];
    char *t=hood;
    int i;
    if (p!=NULL)
    {
    example(p->left);
    strcpy(hood, p->name);
    hood[n]='\0';
    if ( (i=group(pp, t))>1)
    {
        printnod(pp, t);
        printf("_____ Group of %d elements\n", b);
        b=0;
    }
    else
        b=0;
    example(p->right);
    }
}


int group(struct nodes *p, char *s)
{
    int how;
    char printhood[MAXNAME];
    if (p!=NULL)
    {
    strcpy(printhood, p->name);
    printhood[n]='\0';
    group(p->left, s);
    if ( (how=strcmp(s, printhood))==0 && p->count==0)
    {
        b++;
    }
    group(p->right, s);
    }
    return b;
}
void printnod(struct nodes *p, char *s)
{
    int how;
    char printhood[MAXNAME];
    if (p!=NULL)
    {
    strcpy(printhood, p->name);
    printhood[n]='\0';
    printnod(p->left, s);
    if ( (how=strcmp(s, printhood))==0 && p->count==0)
    {
            printf("%s\n", p->name);
            p->count++;
    }
    printnod(p->right, s);
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

int getword (char *word, int lim)
{
    int c;
    char *w = word;
    int quile=0;
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
    for ( ; --lim > 0; w++, quile++)
        if (!isalnum(*w = getch()) && *w!='_')
        {
            ungetch(*w);
            break;
        }
    if (quile<=n)
    {
        word[0]='\0';
        return 0;
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


