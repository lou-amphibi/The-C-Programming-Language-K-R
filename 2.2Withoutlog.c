#include <stdio.h>
#define MAXLINE 10

int withl1(char s[], int lim);
int getline(char s[], int lim);
void copy(char to[], char from[]);


int main()
{
    int len; /* длина текущей строки */
    int max; /* длина максимальной из просмотренных строк */
    char line[MAXLINE]; /* текущая строка */
    char longest[MAXLINE]; /* самая длинная строка */
    int c;
    max=0;
    while ((len = withl1(line, MAXLINE)) > 0)
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
        printf("\nСамая длинная строка ");
        if (max>MAXLINE)
        {
            printf("%s...\n", longest);
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


// функция getline() с циклом без логических операторов, вариант с break
int withl(char s[], int lim)
{
int i=0, c, b=0;
while((c=getchar())!=EOF)
{
    if (i==lim-1)
    {
        s[i]=c;
        i++;
        break;
    }
    if (c=='\n')
    {
        b=c;
        break;
    }
    s[i]=c;
    i++;
}
if (b == '\n')
    {
    s[i] = b;
    ++i;
    }
s[i] = '\0';
return i;
}
// Вариант без break
int withl1(char s[], int lim)
{
    int i=0, a=0, c;
while(a<lim)
    {
        if (a<lim)
        {
            c=getchar();
            if (c!='\n')
            {
                if(c==EOF)
                {
                    a=lim;
                }
                else
                {
                s[i]=c;
                i++;
                a++;
                }
            }
            else if (c=='\n')
            {
                s[i]=c;
                i++;
                a=lim;
            }
        }
     }
    s[i] = '\0';
    return i;
}



