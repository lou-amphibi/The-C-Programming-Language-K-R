#include <fcntl.h>
#include "syscalls.h"
#define PERMS 0666 /* RW для собственника, группы и проч. */


struct _{
    _READ  : 1;  /* файл открыт на чтение */
    _WRITE : 1;  /* файл открыт на запись */
    _UNBUF : 1;  /* файл не буферизируется */
    _EOF   : 1; /* в данном файле встретился EOF */
    _ERR   : 1;  /* в данном файле встретилась ошибка */
}flags;

/* fopen: открывает файл, возвращает файловый указатель */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a'
        return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (fp->flags._READ==0 && fp->flags._WRITE==0)
            break;              /* найдена свободная позиция */
    if (fp >= _iob + OPEN_MAX)  /* нет свободной позиция */
        return NULL;

    if (*mode == 'w')
        fd = creat(name, PERMS);
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    } else
        fd = open(name, O_RDONLY, 0);
    if (fd ==-1) /* невозможен доступ по имени name */
        return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    if (fp->flag = (*mode == 'r'))
    {
        fp->flag._READ=1;
        fp->flag._WRITE=0;
    }
    else
    {
        fp->flag._READ=0;
        fp->flag._WRITE=1;
    }
    return fp;
}




/* _fillbuf: запрос памяти и заполнение буфера */
int _fillbuf(FILE *fp)
{
    int bufsize;

    if ((fp->flag._READ==0 || fp->flag._EOF==1 || fp->flag._ERR)==1)
        return EOF;
    bufsize = (fp->flag._UNBUF==1) ? 1 : BUFSIZ;
    if (fp->base == NULL) /* буфера еще нет */
       if ((fp->base = (char *) malloc(bufsize)) == NULL)
           return EOF; /* нельзя получить буфер */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1)
            fp->flags._EOF = 1;
        else
            fp->flags._ERR = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}