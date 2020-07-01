#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINES 5000 /* максимальное число строк */
char *lineptr[MAXLINES]; /* указатели на строки текста */

int readlines(char *lineptr1[], int nlines, int n);
void writelines(char *lineptr1[], int nlines);
void qsort1(void *lineptr[], int left, int right,
    int (*comp)(void *, void *, int a, int d, int f, int l), int n, int pa, int pd, int pf, int pl);
int numcmp(char *, char *, int n, int a, int f, int l);
int strcmp1(char *s, char *t, int n, int a, int f, int l);

/* сортировка строк */
int main(int argc, char *argv[])
{
    int nlines;        /* количество прочитанных строк */
    int numeric = 0;   /* 1, если сорт. по числ. знач. */
    int c, i=1;
    int reverce=0, lower=0, dstring=0, fields=0;
    int rtab=0;
    if (argc!=1)
    {
    while ( (*(argv+i))[0] == '-')
    {
        c = (*(argv+i))[1];
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverce = 1;
                    break;
                case 'f':
                    lower=1;
                    break;
                case 'd':
                    dstring=1;
                    break;
                case 't':
                    puts("Включен режим работы с полями");
                    c = (*(argv+i))[2];
                    if ( (*(argv+i))[3]=='h' )
                        rtab=1;
                    switch (c) {
                        case 'a':
                            fields=1;
                            break;
                        case 'b':
                            fields=2;
                            break;
                        case 'c':
                            fields=3;
                            break;
                        default:
                            puts("Неверный спецификатор");
                            exit(1);
                     }
                     break;
                default:
                    puts("Неверная команда");
                    break;
            }
    i++;
    if (i==argc)
        break;
    }
    printf("revercr - %d numeric -%d lower - %d dstring - %d fields -%d rtab -%d\n", reverce, numeric, lower, dstring, fields, rtab);
    if ( (*(argv+1))[0] != '-' )
        puts("Неверный аргумент");
    }
    if ((nlines = readlines(lineptr, MAXLINES, lower)) >= 0) {
        qsort1((void **) lineptr, 0, nlines-1,
          (int (*)(void*,void*, int lower, int dstring, int fields, int rtab))(numeric ? numcmp : strcmp1), reverce, lower, dstring, fields, rtab);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Bведено слишком много строк\n");
        return 1;
    }
}



/* qsort: сортирует v[left]...v[right] по возрастанию */
void qsort1(void *v[], int left, int right,
        int (*comp)(void *, void *, int a, int d, int f, int l), int n, int pa, int pd, int pf, int pl)
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) /* ничего не делается, если */
        return;        /* в массиве менее двух элементов */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (n==0)
        {
            if ((*comp)(v[i], v[left], pa, pd, pf, pl) > 0)
                swap(v, ++last, i);
        }
        else
        {
            if ((*comp)(v[i], v[left], pa, pd, pf, pl) < 0)
                swap(v, ++last, i);
        }
    swap(v, left, last);
    qsort1(v, left, last-1, comp, n, pa, pd, pf, pl);
    qsort1(v, last+1, right, comp, n, pa, pd, pf, pl);
}


#define MAXLEN 1000 /* максимальная длина строки */
/* numcmp: сравнивает s1 и s2 как числа */
void alllower(char s[]);
void detchar(char s[]);
int forfiels(char *s, char *t, int n);
void despase(char s[]);

int numcmp(char *s1, char *s2, int n, int a, int f, int l)
{
    double v1, v2;
    char n1[MAXLEN], n2[MAXLEN];
    char *p1=NULL, *p2=NULL;

    if (f>0)
    {
        int i=forfiels(s1, s2, f);
        if (l>0)
        {
            despase(s1);
            despase(s2);
        }
        return i;
    }
    if (n==1)
    {
        strcpy(n1, s1);
        alllower(n1);
        strcpy(n2, s2);
        alllower(n2);
    }
    if (a==1)
    {
        if (n==0)
        {
            strcpy(n1, s1);
            strcpy(n2, s2);
        }
        detchar(n1);
        detchar(n2);
    }
    p1=(n==1 || a==1) ? n1 : s1;
    p2=(n==1 || a==1) ? n2 : s2;

    v1 = atof(p1);
    v2 = atof(p2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmp1(char *s, char *t, int n, int a, int f, int l)
{
    char n1[MAXLEN], n2[MAXLEN];
    char *p1=NULL, *p2=NULL;

    if (f>0)
    {
        int i=forfiels(s, t, f);
        if (l>0)
        {
            despase(s);
            despase(t);
        }
        return i;
    }
    if (n==1)
    {
        strcpy(n1, s);
        alllower(n1);
        strcpy(n2, t);
        alllower(n2);
    }
    p1=(n==1) ? n1 : s;
    p2=(n==1) ? n2 : t;
    for ( ; *p1 == *p2; p1++, p2++)
        if (*p1 == '\0')
            return 0;
    return *p1 - *p2;
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


int getline(char *, int);
char *alloc(int);




/* readlines: чтение строк */
int readlines(char *lineptr1[], int maxlines, int n)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* убираем символ \n */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: печать строк */
void writelines(char *lineptr1[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

// alloc и afree
#define ALLOCSIZE 10000 /* размер доступного пространства */

static char allocbuf[ALLOCSIZE]; /* память для alloc */
static char *allocp = allocbuf;  /* указатель на своб. место */

char *alloc(int n)   /* возвращает указатель на n символов */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;        /* пространство есть */
        return allocp - n;  /* старое p */
    } else     /* пространства нет */
        return 0;
}

void afree(char *p) /* освобождает память, на которую указывает p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}



int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void alllower(char s[])
{
    int i=strlen(s);
    for (int j=0; j<i; j++)
    {
        s[j]=tolower(s[j]);
    }
}


int detchar1(char n)
{
    if (isspace(n) || isdigit(n) || isalpha(n))
        return 1;
    else
        return 0;
}

void detchar(char s[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if ( detchar1(s[i]) )
            s[j++] = s[i];
        s[j] = '\0';
}

int forfiels(char *s, char *t, int n)
{
    int i=0, j=0;
    if (n==1)
    {
        for (; *(s+i)=='\t'; i++)
            ;
        for (; *(t+j)=='\t'; j++)
            ;
        return (i>j) ? 1 : (i==j) ? 0 : -1;
    }
    else if (n==2)
    {
        i=strlen(s);
        j=strlen(t);
        int a=0, b=0;
        for (; *(s+i)=='\t'; i--)
            a++;
        for (; *(t+j)=='\t'; j--)
            b++;
        return (a>b) ? 1 : (a==b) ? 0 : -1;
    }
    else if (n==3)
    {
        int c=0, d=0;
        for (; *(s+i)!='\0'; i++)
            if ( *(s+i)=='\t')
                c++;
        for (; *(t+j)!='\0'; j++)
            if ( *(t+i)=='\t')
                d++;
        return (c>d) ? 1 : (c==d) ? 0 : -1;
    }
    return 0;
}

void despase(char s[])
{
    for (int i=0; s[i]!='\0'; i++)
    {
        if (s[i]=='\t')
            s[i]=' ';
    }
}