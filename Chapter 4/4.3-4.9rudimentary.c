#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100  /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */


int getop (char []);
void push (double);
double pop (void);
void denay(void);
double vari(char i);

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    // команды интерфейса
    double up, dbl, swt, swt2;
    // переменные
    double last, result=0;

    char s[MAXOP];
    while ((type = getop (s)) != EOF) {
        switch (type) {
        // операнды
        case NUMBER:
            push (atof(s));
            last=(atof(s));
            break;
        // операторы
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
        case '%':
            op2 = pop();
            push (((int)pop()) % ((int)op2));
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push (pop() / op2);
            else
                printf("ошибка: деление на нуль\n");
                break;
        // переменные
        case ']':
            push(last);
            break;
        case '_':
            push(result);
            break;
        case 'a':
            push(vari('a'));
            break;
        case 'l':
            push(result-vari('a'));
            break;
        case 'x':
            push(vari('x'));
            break;
        case 'y':
            push(vari('x')-last);
            break;
        case 'q':
            push(result-last);
            break;
        case 'o':
            push(result-vari('x'));
            break;
        // комплексные и унарные операторы
        case 'P':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 'S':
            push(sin(pop()));
            break;
        case 'E':
            push(exp(pop()));
            break;
        // интерфейс
        case '^':
            printf("Верхний элемент = %g\n", up=pop() );
            push(up);
            break;
        case '&':
            dbl=pop();
            push(dbl);
            push(dbl);
            break;
        case '$':
            swt=pop();
            swt2=pop();
            push(swt);
            push(swt2);
            break;
        case '#':
            denay();
            push(0);
            break;
        case '\n':
            printf("\t%.8g\n", result=pop());
            break;
        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
        }
    }
    if (type==EOF)
    {
        printf("EOF\nРассчеты окончены.\n");
    }
    return 0;
}

#define MAXVAL 100  /* максимальная глубина стека */

int sp = 0;         /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек */
/* push: положить значение f в стек */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

/* pop: взять с вершины стека и выдать в качестве результата */
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else {
        printf ("ошибка: стек пуст\n");
        return 0.0;
    }
}
// Функции для стека
void denay(void)
{
    int i=0;
    while(i<MAXVAL)
    {
        val[i++]=0;
    }
    sp=0;
}

double vari(char i)
{
    if (i=='a')
    {
        return val[0];
    }
    else if (i=='x')
    {
        return val[1];
    }
    else if (i=='y')
    {
        return val[2];
    }
    return 0;
}


// Ввод
int getch(void);
void ungetch(int);
void ungets(char s[]);

/* getop: получает следующий оператор или операнд */
int getop(char s[])
{
    int i, c, y;
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
            ungetch(c);
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
    ungetch(c);
    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */


int getch(void)       /* взять (возможно возвращенный) символ */
{
    int c;
    if (bufp>0)
    {
        return buf[--bufp];  //return (bufp > 0) ? buf[--bufp] : (c!=EOF) ? c=getchar() : EOF;
    }
    else {
    if((c=getchar())!=EOF)
        return c;
    else
        return EOF; }
}

void ungetch(int c)   /* вернуть символ на ввод */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        if (c!=EOF)
        buf[bufp++] = c;
}
// ungets
void ungets(char s[])
{
    int i=0;
    for(; s[i]!='\0'; i++)
        ;

    if (bufp >= BUFSIZE)
        printf("ungets: слишком много символов\n");
    else
        for (int j=0; j<i;)
            buf[bufp++]=s[j++];
}


// 4.8

int prev;
int gflag;

int getchMOD(void)       /* взять (возможно возвращенный) символ */
{
    return (gflag>0) ? gflag=0, prev : getchar();
}

void ungetchMOD(int c)   /* вернуть символ на ввод */
{
    prev=c;
    gflag=1;
}