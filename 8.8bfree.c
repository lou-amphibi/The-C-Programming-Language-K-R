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

int bfree(void *p, int n)
{
    Header *hp;

    if(n < sizeof(Header))
        return 0;
    hp = (Header *) p;
    hp->s.size = n / sizeof(Header);
    free((void *) (hp + 1));
    return hp->s.size;
}

int _bfree(void *p, int n)
{
    Header *h=(Header *) p;
    for(int i=n; i>0; i--)
        free(*h++);
    return p->s.size;
}