#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 200


int main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    int str;
    char file1[MAXLEN]="a";
    char file2[MAXLEN]="a";
    char *c, *b;
    if (argc!=3)
    {
     puts("Используйте имена файлов как аргументы");
     exit(1);
    }
    else
    {
        fp1=fopen(argv[1], "r");
        fp2=fopen(argv[2], "r");
        if (fp1==NULL || fp2==NULL)
        {
            puts("Не удалось открыть фаил");
            exit(2);
        }
        while( (str=strcmp(file1, file2))==0)
        {
        c=fgets(file1, MAXLEN, fp1);
        b=fgets(file2, MAXLEN, fp2);
        if (c==NULL || b==NULL)
            break;
        }
        if (str!=0)
            printf("%sand\n%s", file1, file2);
        fclose(fp1);
        fclose(fp2);
    }
}