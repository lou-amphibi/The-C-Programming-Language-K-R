#define MAXBUT 1024; // допустимая память системы
static Header base;          /* пустой список для нач. запуска */
static Header *freep = NULL; /* начало в списке своб. блоков */

void *malloc(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    if (nbytes>MAXBUT)
    {
        puts("Запрос превышает объем оперативной памяти системы");
        return NULL;
    }

    if ((prevp = freep) == NULL) { /* списка своб. памяти еще нет */
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {      /* достаточно большой */
            if (p->s.size == nunits)    /* точно нужного размера */
                prevp->s.ptr = p->s.ptr;
            else {                      /* отрезаем хвостовую часть */
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p+1);
        }
        if (p == freep)                 /* прошли полный цикл по списку */
            if ((p = morecore(nunits)) == NULL)
                return NULL; /* больше памяти нет */
    }
}


void free(void *ар)
{
    Header *bp, *p;

    bp = (Header *)ap -1; /* указатель на заголовок блока */
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >- p->s.ptr && (bp > p || bp < p->s.ptr))
            break; /* освобождаем блок в начале или в конце */

    if (bp + bp->s.size == p->s.ptr) {  /* слить с верхним */
        bp->s.size += p->s.ptr->s.size; /* соседом */
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) { /* слить с нижним соседом */
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;
    freep = p;
}