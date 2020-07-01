#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct nlist *lookup(char *);
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
#define MAX 400


struct nlist {          /* элемент таблицы */
    struct nlist *next; /* указатель на следующий элемент */
     char *name;        /* определенное имя */
     char *defn;        /* замещающий текст */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* таблица указателей */
void preprocessor(char s[]);

int main()
{
    int c;
    int i=0;
    char programm[MAX];
    while((c=getchar())!=EOF)
        programm[i++]=c;
    preprocessor(programm);
}

int isutility(char c);
int isutilityp(char c);
void defines(char s[]);

void preprocessor(char s[])
{
    int i, j=0;
    char proc[MAX];
    char name[MAX];
    char def[MAX];
    char *n=name;
    char *d=def;
    for (i=0; s[i]!='\0'; i++)
    {
        if (isutility(s[i]))
        {
            if(s[i]=='\"')
            {
            i++;
            while(s[i]!='\"' && s[i]!='\0')
                i++;
            }
            else if(s[i]=='/')
            {
                if(s[i+1]=='/')
                {
                i+=2;
                while(s[i]!='\n' && s[i]!='\0')
                    i++;
                }
                else if(s[i+1]=='*')
                {
                    i++;
                    while((s[i]!='*' && s[i+1]!='/') && s[i]!='\0')
                        i++;
                    i++;
                }
            }
        }
        else if (s[i]=='#')
        {
            while(s[i]!=' ' && s[i]!='\0')
                proc[j++]=s[i++];
            proc[j]='\0';
            if (strcmp("#define", proc)==0 )
            {
                i++;
                while(s[i]!=' ' && s[i]!='\n' && s[i]!='\0')
                    *n++=s[i++];
                *n='\0';
                i++;
                while(s[i]!=' ' && s[i]!='\n' && s[i]!='\0')
                    *d++=s[i++];
                *d='\0';
                install(name, def);
                n=name;
                d=def;
                j=0;
                i--;
            }
        }
    }
    defines(s);
}


void defines(char s[])
{
    char complit[MAX];
    char cword[MAX];
    struct nlist *pm;
    int i, j;
    for (i=0, j=0; s[i]!='\0'; i++, j++)
    {
        if (isutilityp(s[i]))
        {
            if(s[i]=='\"')
            {
            complit[j++]=s[i++];
            while(s[i]!='\"' && s[i]!='\0')
                complit[j++]=s[i++];
            complit[j]=s[i];
            }
            else if(s[i]=='/')
            {
                complit[j++]=s[i++];
                if(s[i]=='/')
                {
                complit[j++]=s[i++];
                while(s[i]!='\n' && s[i]!='\0')
                    complit[j++]=s[i++];
                complit[j]=s[i];
                }
                else if(s[i]=='*')
                {
                    complit[j++]=s[i++];
                    while((s[i]!='*' && s[i+1]!='/') && s[i]!='\0')
                        complit[j++]=s[i++];
                    complit[j++]=s[i++];
                    complit[j]=s[i];
                }
                else
                {
                    i--;
                    j--;
                }
            }
            else if(s[i]=='#')
            {
                complit[j++]=s[i++];
                while(s[i]!='\n' && s[i]!='\0')
                    complit[j++]=s[i++];
                complit[j]=s[i];
            }
        }
        else if (isalpha(s[i]))
        {
            int y=0;
            cword[y++]=s[i++];
            while(isalnum(s[i]) && s[i]!='\0')
            {
                cword[y++]=s[i++];
            }
            cword[y]='\0';
            if ((pm=lookup(cword))!=NULL)
            {
                strcat(complit, pm->defn);
                j+=strlen(pm->defn)-1;
                i--;
            }
            else
            {
                strcat(complit, cword);
                j+=strlen(cword)-1;
                i--;
            }
        }
        else
            complit[j]=s[i];
    }
    complit[j]='\0';
    printf("\n%s\n", complit);
}


int isutilityp(char c)
{
    if (c=='\"' || c=='/' || c=='#')
        return 1;
    else
        return 0;
}


int isutility(char c)
{
    if (c=='\"' || c=='/')
        return 1;
    else
        return 0;
}

/* hash: получает хэш-код для строки s */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}


/* lookup: ищет s */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* нашли */
    return NULL; /* не нашли */
}


char *strdup(char *);

/* install: заносит имя и текст (name, defn) в таблицу */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* не найден */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* уже имеется */
        free((void *) np->defn); /* освобождаем прежний defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

char *strdup(char *s) /* делает дубликат s */
{
    char *p;

    p = (char *) malloc(strlen(s)+1); /* +1 для '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}