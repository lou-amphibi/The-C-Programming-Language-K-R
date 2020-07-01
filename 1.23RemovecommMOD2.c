#include <stdio.h>
#define MAX 9000
FILE *fptr;

void removecomm(char b[], int a);

int main()
{
    int i=0;
    char ac[MAX];
    fptr=fopen("1.23Test.c", "r");
    if (fptr!=0)
    {
        while(!feof(fptr))
        {
            ac[i]=fgetc(fptr);
            i++;
        }
        ac[i-1]=0;
    }
    else
    {
        printf("Error\n");
    }
    removecomm(ac, i);
    fclose(fptr);
    fptr=fopen("1.23Test.c", "w");
    for (int b=0; b<i; b++)
    {
        if (ac[b]!=0)
        {
        fprintf(fptr,"%c", ac[b]);
        }
    }
    fclose(fptr);
}


void removecomm(char b[], int a)
{
    int i=0, count=0, j, t;
    char c='y', jok='i';
    for (i=0; i<a; i++)
    {
    // Проверяем находимся ли мы в кавычках
        if (b[i]==c && count==1)
            {
                count=0;
            }
        else if ((b[i]=='\"' || b[i]=='\'') && b[i-1]!='\\')
            {
            count=1;
            c=b[i];
            }
        // Работаем с комментариями
        if ((b[i]=='/' && b[i+1]=='*' && count==0) || (b[i]=='/' && b[i+1]=='/' && count==0))
        {
            // Работаем с табуляциями и переносами строчек. Это оказался пробел, а не таблуяция, сраный компилятор
        if (b[i-1]==' ')
        {
            int tab=i-1;
            while(b[tab]==' ')
                {
                    tab--;
                }
            if (b[tab]=='\n')
            {
                while(tab<i)
                {
                    b[tab]=0;
                    tab++;
                }
            }
        }
            // Продолжаем работу с комментами вида звездочка бекслеш
        if (b[i]=='/' && b[i+1]=='*' && count==0)
        {
            j=i;
            while(!(b[j]=='*' && b[j+1]=='/'))
            {
                b[j]=0;
                j++;
            }
            if (b[j]=='*' && b[j+1]=='/')
            {
                b[j]=0;
                b[j+1]=0;
            }
        }
        // Работаем с комментариями через два бекслеша
        else if (b[i]=='/' && b[i+1]=='/' && count==0)
        {
            t=i;
            while(b[t]!='\n')
            {
                b[t]=0;
                t++;
            }
        }
        }
    }
}

