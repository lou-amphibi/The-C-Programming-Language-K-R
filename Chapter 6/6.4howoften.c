#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAME 100

struct nodes* swim(struct nodes *p, char *c);

int getword (char *word, int lim);
char *cpystr(char *s);
void printnod(struct nodes *p);
int biggest=1;

struct nodes {
    int count;
    char *name;
    struct nodes *left;
    struct nodes *right;
};


int main()
{
    struct nodes *root=NULL;
    char names[MAXNAME];
    while (getword(names, MAXNAME)!=EOF)
    {
        root=swim(root, names);
    }
    while (biggest>0)
    {
        printnod(root);
        biggest--;
    }
    free(root);
}


struct nodes* swim(struct nodes *p, char *c)
{
    int how;
    char dblstr[MAXNAME];
    if (p==NULL)
    {
        p=(struct nodes *) malloc(sizeof(struct nodes));
        p->name=cpystr(c);
        p->count=1;
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
        else
        {
            p->count++;
            biggest=(p->count > biggest) ? p->count : biggest;
        }

    }
    return p;
}


void printnod(struct nodes *p)
{
    if (p!=NULL)
    {
        printnod(p->left);
        if (p->count==biggest)
            printf("%s встретилась %d\n", p->name, p->count);
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
