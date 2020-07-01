#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100  /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */

int getline(char s[], int lim);
int getop (char s[], char p[]);
void push (double);
double pop (void);

/* калькулятор с обратной польской записью */
int main()
{
    int type, tab;
    double op2;
    // команды интерфейса
    double up, dbl, swt, swt2;
    // переменные
    double last, result=0;

    char s[MAXOP];
    char p[MAXOP];
    while ((tab=getline(s, MAXOP))>0) {
    while ((type = getop (s, p)) != '\0') {
        switch (type) {
        // операнды
        case NUMBER:
            push (atof(p));
            last=(atof(p));
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
       /* // переменные в этой версии отключены
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
            break; */
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
      /*  case '#': denay отключен
            denay();
            push(0);
            break; */
        case '\n':
            printf("\t%.8g\n", result=pop());
            break;
        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
        }
    }
    }
    if (tab==0)
    {
        printf(" EOF\n Конец рассчетов\n");
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



/* getop: получает следующий оператор или операнд */
int getop(char s[], char p[])
{
    static int i;
    int c;
    int y=0;
    while(s[i]!='\0')
    {
    while (s[i] == ' ' || s[i] == '\t')
        i++;
    if (!isdigit(s[i]) && s[i]!= '.' && s[i]!='-') {
        c=s[i++];
        return c;    /* не число или его часть */
    }
    if (s[i]=='-')
    {
        if (isdigit(s[i+1]) || s[i+1]=='.')
        {
            p[y++]=s[i++];
            while (isdigit(s[i]) || s[i]=='.')
                p[y++]=s[i++];
            p[y]='\0';
        }
        else if (!isdigit(s[i+1]))
        {
            c=s[i++];
            return c;
        }
    }
    if (isdigit(s[i])) { /* накапливаем целую часть */
        while (isdigit(s[i]))
            p[y++]=s[i++];
        p[y]='\0';
    }
    if (s[i] =='.') { /* накапливаем дробную часть */
        if (isdigit(s[i+1]))
        {
            p[y++]=s[i++];
            while (isdigit(s[i]))
                p[y++]=s[i++];
            p[y]='\0';
        }
    }
    return NUMBER;
    }
    i=0;
    return '\0';
}



int getline(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}