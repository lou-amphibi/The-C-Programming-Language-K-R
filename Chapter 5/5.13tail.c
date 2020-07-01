#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1000
#define N 2

char *alloc(int n);
void afree(char *p);
int getline(char s[], int lim);

int main(int argc, char *argv[])
{
    char line[MAXLEN];
    int len, i=0, j=0, reload=0;
    char *p;
    char *strings[MAXLEN];
    // Аргументы командной строки
    if (argc==2)
    {
        if ( (*(argv+1))[0]=='-' )
        {
            int y=1;
            if ( isdigit( (*(argv+1))[1]) )
            {
            while (isdigit( (*(argv+1))[y]))
            {
                j=j*10 + ( ( (*(argv+1))[y++])-'0' );
                reload=1;
            }
            }
            else
                puts("После \'-\' должно стоять число");
        }
        else
            puts("Введите аргумент вида \"-n\", где n - целое число");
    }
    else if (argc>2)
    {
        puts("Слишком много аргументов, допустим один аргумент вида \"-n\", где n - целое число");
    }
    // Цикл обработки
    while ( (len=getline(line, MAXLEN))>0)
    {
        if ( (p=alloc(len)) == NULL)
        {
            puts("Слишком много строк, память переполнена");
        }
        else
        {
            line[len-1]='\0';
            strcpy(p, line);
            if (i<MAXLEN)
                strings[i++]= p;
        }
    }
    // Проверка на правильный ввод
    j=(reload==1) ? j : N;
    int all=i, prn=j;
    j=i-j;
    i-=j;
    puts("___________");
    if (all>=prn)
    {
    for (; i>0; i--, j++)
    {
        printf("%s\n", *(strings+j));
    }
    }
    else
        printf("Введено меньше чем %d строк\n", prn);
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