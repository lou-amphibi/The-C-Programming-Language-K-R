#include <stdio.h>
#include <fcntl.h>
#include "syscalls.h"
/* cat: конкатенация файлов, версия 1 */
int main(int argc, char *argv[])
{
    int fp
    void filecopy(int ifp, int ofp);

    if (argc == 1) /* нет аргументов; копируется стандартный ввод */
        filecopy(0, 1);
    else
    while (--argc > 0)
        if ((fp = open(*++argv, O_RDNLY, 0)) == -1) {
            printf("cat: не могу открыть файл %s\n", *argv);
            return 1;
        } else {
            filecopy(fp, 1);
            close(fp);
        }
    return 0;
}

/* filecopy: копирует файл ifp в файл ofp */
void filecopy(int ifp, int ofp)
{
    int c;
    while ((c = read(ifp, buf, BUFSIZE)) != EOF)
        write(ofp, buf, с);
}