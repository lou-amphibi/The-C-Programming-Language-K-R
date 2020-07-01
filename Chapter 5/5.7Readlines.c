#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 /* максимальное число строк */
#define MAXLEN 1000 /* максимальная длина строки */
char *lineptr[MAXLINES]; /* указатели на строки */

int readlines(char *lineptr1[], int maxlines, char *redl, int maxlen);
void writelines(char *lineptr1[], int nlines);


int main()
{
    char redl[MAXLEN];
    int nlines=0;
    if ((nlines=readlines(lineptr, MAXLINES, redl, MAXLEN))>=0)
    {
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("ошибка: слишком много строк\n");
        return 1;
    }
}

int getline(char *s, int lim);
/* readlines: чтение строк */
int readlines(char *lineptr1[], int maxlines, char *redl, int maxlen)
{
    int len, nlines;
    char line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || i > MAXLEN)
            return -1;
        else {
            line[len-1] = '\0'; /* убираем символ \n */
            strcpy(redl, line);
            lineptr1[nlines++] = redl;
            redl+=len;
        }
    return nlines;
}

/* writelines: печать строк */
void writelines(char *lineptr1[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr1[i]);
}




int getline(char *s, int lim)
{
    int c, i;
    for (i=0; --lim > 0 && (c=getchar()) != EOF && c != '\n'; i++)
        *s++ = c;
    if (c == '\n') {
        *s++ = c;
         i++;
    }
    *s = '\0';
    return i;
}


