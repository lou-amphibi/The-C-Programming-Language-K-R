#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);
/* find: печать строк с образцом, заданным 1-м аргументом */
int main(int argc, char *argv[])
{
    FILE *fp1;
    char file[MAXLINE];

    char line[MAXLINE];
    int found = 0;
    if (argc !=2)
        printf("Используйте в find образец, который должен бьыть именем файла\n");
    else
    {
        fp1=fopen(argv[1], "r");
        if (fp1==NULL)
        {
            puts("Фаил не найден, используется образец");
            while (getline(line, MAXLINE) > 0)
                if (strstr(line, argv[1]) != NULL) {
                    printf ("%s", line);
                    found++;
        }
        }
        else
        {
            fgets(file, MAXLINE, fp1);
            while (getline(line, MAXLINE) > 0)
                if (strstr(line, file) != NULL) {
                    printf ("%s", line);
                    found++;
                }
        }
    fclose(fp1);
    }
    return found;
}

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