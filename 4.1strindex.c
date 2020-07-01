#include <stdio.h>
#define MAXLINE 1000 /* максимальный размер вводимой строки */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] ="ould"; /* образец для поиска */

/* найти все строки, содержащие образец */

int main()
{
    int n;
    char line[MAXLINE];
    int found = 0;
    while (getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
                n=strindex(line, pattern)-1;
                printf ("%s%d позиция паттерна\n", line, n);
                found++;
        }
    return found;
}

/* getline: читает строку в s, возвращает длину */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n') /* I.B.: misprint was here -lim instead of --lim */
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: вычисляет место t в s или выдает -1, если t нет в s */
int strindex (char s[], char t[])
{
    int i, j, k;
    int sten=-1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
             ;
        if (k > 0 && t[k] == '\0')
            return j;
    }
    return sten;
}
