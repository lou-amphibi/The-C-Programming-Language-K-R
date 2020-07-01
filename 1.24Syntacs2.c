#include <stdio.h>
#include <stdlib.h>
#define MAX 9000
FILE *fptr;
char c='q';
int count=0, comm=0, comm1=0;

void syntacs(char b[], int a);
int quotes(char b[], int i);
int commets(char b[], int i);
int comes(char b[], int i);

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
    int scb=0, sdb=0, szb=0, flag=0, r, j, esc=0;
    for (int i=0; i<a; i++)
    {
        //Проверяем кавычки
        int quo=quotes(b, i);
        //Проверяем комменты
        int com=commets(b, i);
        // Еще комменты
        int com1=comes(b, i);
        // Работаем со скобками вида ()
        if ((b[i]=='(') && (quo==0 && com==0 && com1==0))
        {
            scb++;
        }
        else if ((b[i]==')') && (quo==0 && com==0 && com1==0))
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
        if ((b[i]=='[') && (quo==0 && com==0 && com1==0))
        {
            sdb++;
        }
        else if ((b[i]==']') && (quo==0 && com==0 && com1==0))
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
        if ((b[i]=='{') && (quo==0 && com==0 && com1==0))
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
        else if ((b[i]=='}') && (quo==0 && com==0 && com1==0))
        {
            szb--;
            if (szb<0)
            {
                printf(" EXT*}*");
                szb++;
            }
        }
        // Работаем с переносом строки
        if ((b[i]=='n' && b[i-1]=='\\') && (quo==0 && com==0 && com1==0))
        {
            esc++;
        }
        putchar(b[i]);
    }
    if (esc>0)
    {
        printf ("\nEXT ESCAPE \\n, times - %d", esc);
    }
    // Счетчик парности кавычек
    if (count>0)
    {
        printf("\nEXT QUOTES, times - %d", count);
    }
}



int quotes(char b[], int i)
{
    if (b[i]==c && count==1)
    {
        count=0;

    }
    else if ((b[i]=='\"' || b[i]=='\'') && b[i-1]!='\\')
    {
        count=1;
        c=b[i];
    }
    return count;
}

int commets(char b[], int i)
{
    if (b[i]=='/' && b[i+1]=='*')
    {
        comm=1;
    }
    else if ((b[i]=='*' && b[i+1]=='/') && comm==1)
    {
        comm=0;
    }
    return comm;
}

int comes(char b[], int i)
{
    if (b[i]=='/' && b[i+1]=='/')
    {
        comm1=1;
    }
    else if (b[i]=='\n' && comm1==1)
    {
        comm1=0;
    }
    return comm1;
}
