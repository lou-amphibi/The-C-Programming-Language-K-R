#include <stdio.h>
#include <stdlib.h> /* для atof() */

#define MAXOP 100  /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */

int getop (char []);
void push (double);
double pop (void);

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop (s)) != EOF) {
        switch (type) {
        case NUMBER:
            push (atof(s));
            break;
        case '+':
            push (pop() + pop());
            break;
        case '*':
            push (pop() * pop());
            break;
        case '-':
            op2 = pop();
            push (pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push (pop() / op2);
            else
                printf("ошибка: деление на нуль\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* максимальная глубина стека */

int sp = 0;         /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек */

/* push: положить значение f в стек */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

/* pop: взять с вершины стека и выдать в качестве результата */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf ("ошибка: стек пуст\n");
    return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: получает следующий оператор или операнд */
int getop(char s[])
{
    char c;
    static char prevc='\0';
    int i=0;
    if (prevc!='\0')
    {
        c=prevc;
        prevc='\0';
    }
    else
        scanf("%c", &c);
    while(c==' ')
        scanf("%c", &c);
    if (isdigit(c))
    {
        s[i++]=c;
        while(isdigit(c))
        {
            scanf("%c", &c);
            if(isdigit(c))
                s[i++]=c;
        }
        if (c=='.')
        {
            s[i++]=c;
            scanf("%c", &c);
            s[i++]=c;
            while(isdigit(c))
            {
            scanf("%c", &c);
            if(isdigit(c))
                s[i++]=c;
            }
        }
        if (c!=' ')
            prevc=c;
        s[i]='\0';
        return NUMBER;
    }
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */

int getch(void)       /* взять (возможно возвращенный) символ */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* вернуть символ на ввод */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}


