#include <stdio.h>
#define MAXLINE 10

int getline(char line[], int lim);
void copy(char to[], char from[]);


int main()
{
    int len; /* длина текущей строки */
    int max; /* длина максимальной из просмотренных строк */
    char line[MAXLINE]; /* текущая строка */
    char longest[MAXLINE]; /* самая длинная строка */
    int c;
    max=0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (line[len-1]!='\n')
        {
            while((c=getchar())!=EOF && c!='\n')
            len++;
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max<MAXLINE && max!=0)
    {
        max--;
    }
    if (max > 0)
    {
        printf("Самая длинная строка ");
        if (max>MAXLINE)
        {
            printf("%s\n...", longest);
        }
        else
        {
            printf("%s", longest);
        }
    }
    printf(" В строке %d символов\n", max);
    return 0;
}


/* getline: читает строку в s, возвращает длину */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c != '\n'; ++i)
    s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: копирует из 'from' в 'to'; to достаточно большой */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}