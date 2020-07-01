#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct nlist *lookup(char *);
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *s);
void tableprint(void);

struct nlist {          /* элемент таблицы */
    struct nlist *next; /* указатель на следующий элемент */
     char *name;        /* определенное имя */
     char *defn;        /* замещающий текст */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* таблица указателей */



int main()
{
    struct nlist *li;
    li=install("In", "1");
    install("Low", "5");
    char *s=li->name;
    char *b=li->defn;
    printf("%s, %s\n", s, b);
    struct nlist *li2;
    undef("In");
    puts("It's tableprint");
    tableprint();
}


void tableprint(void)
{
    int i=0;
    struct nlist *np;
    while(i<HASHSIZE)
    {
        for (np = hashtab[i]; np!=NULL; np=np->next)
            printf("%s and %s\n", np->name, np->defn);
        i++;
    }
}

void undef(char *s)
{
    struct nlist *np, *prev;
    unsigned h=hash(s);
    prev=NULL;
    for (np = hashtab[h]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
            break;
        prev=np;
    }
    if(np!=NULL)
    {
        if(prev==NULL)
        {
            hashtab[h]=np->next;
        }
        else
        {
            prev->next=np->next;
            free((void *)np->name);
            free((void *)np->defn);
            free((void *) np);
        }
    }
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