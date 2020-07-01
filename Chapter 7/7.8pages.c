#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    FILE *fp;
    int string;
    int pages=0;
    int files=1;
    int i;
    while (files<argc)
    {
    if (feof(fp) && i!=0)
        printf("\n___Pages %d\n", ++i);
    i=0;
    fp=fopen(argv[files], "r");
    if (fp==NULL)
    {
        puts("File not found");
        continue;
    }
    printf("\nFILE - %s\n\n", argv[files]);
    while(!feof(fp))
    {
        string=putchar(fgetc(fp));
        if (string=='\n')
            pages++;
        if (pages>20)
        {
            i++;
            pages=0;
            printf("\n   Pages %d\n", i);
        }
    }
    printf("\b \n");
    files++;
    }
    fclose(fp);
    if (pages<=20)
    printf("\n___Pages %d\n", ++i);
    system("date");
}