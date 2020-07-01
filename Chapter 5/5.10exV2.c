#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int full[MAXLINE];
void push(int c);
int pop(void);
int atof2(char s[]);
int operand(char s[]);

int main(int argc, char *argv[])
{
    int y=0, c;
    int op2;
    for (int i=1; i<argc; i++)
    {
        if( (c=atof2(*(argv+i)))!=0 ) {
            push(c);
          if ( (c=operand(*(argv+i)))!=0)
            goto here;
        }
        else
        {
            c=*(argv+i)[0];
            here:
            switch (c) {
        case '+':
            push (pop() + pop());
            break;
        case '^':
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
            if (op2 != 0)
                push (pop() / op2);
            else
                printf("ошибка: деление на нуль\n");
                break;
        case '\0':
            continue;
            break;
        default:
            printf("ошибка: неизвестная операция %c\n", c);
            break;
            }
        }
    }
    printf("%d\n", pop());
}




int sp=0;

void push(int c)
{
    if (sp<MAXLINE)
        full[sp++]=c;
    else
        puts("Память заполнена");
}

int pop(void)
{
    if (sp>0)
        return full[--sp];
    else
        puts("Значения не заданы");
        return 0;
}

int atof2(char s[])
{
    int n=0;
    for (int i=0; isdigit(s[i]); i++)
    {
        n=n*10+(s[i]-'0');
    }
    return n;
}

int operand(char s[])
{
    int flag=0;
    int i;
    for (i=0; isdigit(s[i]); i++)
    {
        flag=1;
    }
    if ((s[i]=='+' || s[i]=='-' || s[i]=='^' || s[i]=='/' || s[i]=='%') && flag==1)
    {
        return s[i];
    }
    else
        return 0;
}