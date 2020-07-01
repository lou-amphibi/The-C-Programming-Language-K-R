#include <stdio.h>
char *_fseek(FILE *fp, long offset, int origin);

int main()
{
    FILE *fp;
    fp=fopen("test.c" , "r");
    _fseek(fp, 3, 0);
    printf("%c\n", fgetc(fp));
}


char *_fseek(FILE *fp, long offset, int origin)
{
    if (origin==SEEK_SET)
    {
        fp->ptr = fp->base; // Везде тут нужна работа с cnt и прочими структурными параметрами
        fp->ptr += offset;
        if (fp->ptr==NULL)
            return NULL;
    }
    else if (origin==SEEK_CUR)
    {
        fp->ptr += offset;
        if (fp->ptr==NULL)
            return NULL;
    }
    else
    {
        fp->ptr += fp->cnt;
        fp->ptr += offset;
        if (fp->ptr==NULL)
            return NULL;
    }
    return fp->ptr;
}