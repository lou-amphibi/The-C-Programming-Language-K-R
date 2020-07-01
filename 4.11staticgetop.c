


// getop без необходимости в ungetch
int getop(char s[])
{
    int i, c, y;
    int b;
    static int a='0';
    if (isdigit(a) || a==' ' || a=='\t') {
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c!='-')
        return c;    /* не число или его часть */
    i=0;
    if (c=='-')
    {
        y=c;
        while (isdigit(s[++i] = c = getch()) || c=='.')
            ;
        if (i==1)
        {
            a=c;
            return y;
        }
    }
    if (isdigit(c)) { /* накапливаем целую часть */
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c =='.') /* накапливаем дробную часть */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c==EOF)
    {
        return EOF;
    }
    a=c;
    return NUMBER;
    }
    else
    {
        b=a;
        a='0';
        return b;
    }
}

