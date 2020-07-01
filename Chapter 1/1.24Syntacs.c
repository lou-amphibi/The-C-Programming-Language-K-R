#include <stdio.h>
#include <stdlib.h>
#define MAX 9000
FILE *fptr;

void syntacs(char b[], int a);

int main()
{
    int i=0;
    char bak[MAX];
    fptr=fopen("1.24Test.c", "r");
    if (fptr!=0)
    {
        while(!feof(fptr))
        {
            bak[i]=fgetc(fptr);
            i++;
        }
        bak[i-1]='\0';
    }
    else
    {
        printf("Error\n");
    }
    syntacs(bak, i);
    putchar('\n');
    fclose(fptr);
}


void syntacs(char b[], int a)
{
    int count=0, comm=0, comm1=0, scb=0, sdb=0, szb=0, flag=0, r, j;
    char c='c';
    for (int i=0; i<a; i++)
    {
        //Проверяем кавычки
        if (b[i]==c && count==1)
            {
                count=0;
            }
        else if ((b[i]=='\"' || b[i]=='\'') && b[i-1]!='\\')
            {
            count=1;
            c=b[i];
            }
        //Проверяем комменты
        if (b[i]=='/' && b[i+1]=='*')
        {
            comm=1;
        }
        else if ((b[i]=='*' && b[i+1]=='/') && comm==1)
        {
            comm=0;
        }
        // Еще комменты
        if (b[i]=='/' && b[i+1]=='/')
        {
            comm1=1;
        }
        else if (b[i]=='\n' && comm1==1)
        {
            comm1=0;
        }
        // Работаем со скобками вида ()
        if ((b[i]=='(') && (count==0 && comm==0 && comm1==0))
        {
            scb++;
        }
        else if ((b[i]==')') && (count==0 && comm==0 && comm1==0))
        {
            scb--;
        }
        if (scb>1 && b[i]=='\n')
        {
            printf(" *EXT*(*, %d times", scb);
            scb=0;
        }
        else if (scb<0)
        {
            printf(" *EXT*)*");
            scb=0;
        }
        else if (scb>0 && b[i]=='\n')
        {
            printf(" *EXP*)*");
            scb=0;
        }
        // Работаем со скобками вида []
        if ((b[i]=='[') && (count==0 && comm==0 && comm1==0))
        {
            sdb++;
        }
        else if ((b[i]==']') && (count==0 && comm==0 && comm1==0))
        {
            sdb--;
        }
        if (sdb>1)
        {
            printf(" EXT*[*");
            sdb--;
        }
        else if (sdb<0)
        {
            printf(" EXT*]*");
            sdb++;
        }
        else if (sdb>0 && b[i]=='\n')
        {
            printf(" EXP*]*");
            sdb=0;
        }
        // Работаем со скобками вида {}
        if ((b[i]=='{') && (count==0 && comm==0 && comm1==0))
        {
            int gb=0;
            r=i;
            szb++;
            while((b[r]!='}' && r<a) || (gb!=0))
            {
                if (b[r+1]=='{')
                {
                    gb++;
                }
                else if (b[r]=='}' && gb>0)
                {
                    gb--;
                }
                r++;
            }
            if (b[r]=='}' && (gb==0))
            {
            ;
            }
            else
            {
                printf(" EXP*}*");
            }
        }
        else if ((b[i]=='}') && (count==0 && comm==0 && comm1==0))
        {
            szb--;
            if (szb<0)
            {
                printf(" EXT*}*");
                szb++;
            }
        }
        putchar(b[i]);
    }
}
