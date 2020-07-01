#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *calloc2(unsigned n, unsigned size);



typedef long Align;        /* для выравнивания по границе long */

union header {             /* заголовок блока: */
    struct {
        union header *ptr; /* след. блок в списке свободных */
        unsigned size;     /* размер этого блока */
    } s;
    Align x; /* принудительное выравнивание блока */
};

typedef union header Header;

int main()
{
    char *p;
    p=calloc2(3, 4);
    Header base;
    Header base2;
    Header *fn=malloc(sizeof (Header));
    int j=sizeof (Header);
    unsigned nunits;
    nunits = (12 + sizeof(Header) - 1 ) / sizeof (Header) + 1;
    printf("%d j - %d\n", nunits, j);
    int *k=malloc(sizeof (int));
    *k=3;
    //sleep(2);
    printf("k-%d\n", *k);
    printf("%d size and %d\n", base.s.size, base2.s.size);
    Header arm;
    fn=&base;
    //fn->s.size=123;
    printf("%d size and %d\n", fn->s.size, fn->s.ptr->s.size);

}

void *calloc2(unsigned n, unsigned size)
{
    char *p, *q;
    unsigned size2=n*size;
    if ((p=q=malloc(size2))!=NULL)
    for (unsigned i=0; i<size2; i++)
        *q++=0;
    return p;
}

