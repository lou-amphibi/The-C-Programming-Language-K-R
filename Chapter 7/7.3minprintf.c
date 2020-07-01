#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void minprintf(char *fmt, ...);

int main()
{
    char s[]="January";
    minprintf("%.5s %.3f %x\n", s, 3.4, 124);
}

/* minprintf: минимальный printf с переменным числом аргументов */
void minprintf(char *fmt, ...)
{
    va_list ap;        /* указывает на очередной безымянный аргумент */
    char *p, *sval;
    int ival;
    double dval;
    unsigned int xval;
    char point[10];
    char *o=point;
    int opoint, jpoint;

    va_start(ap, fmt); /* устанавливает ap на 1-й безымянный аргумент */
    for (p=fmt; *p; p++) {
        if (*p !='%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf ("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        case 'x':
            xval= va_arg(ap, int);
            printf ("%x", xval);
            break;
        case '.':
            p+=1;
            if (isdigit(*p))
            {
            for(; isdigit(*p); p++)
                *o++=*p;
            *o++='\0';
            opoint=atof(point);
            }
            switch (*p) {
                case 'f':
                    dval = va_arg(ap, double);
                    printf("%.*f", opoint, dval);
                    break;
                case 's':
                    jpoint=0;
                    for (sval = va_arg(ap, char *); *sval; sval++, jpoint++)
                    {
                        if (opoint>jpoint)
                            putchar(*sval);
                    }
                    break;
                default:
                    putchar(*p);
                    break;
            }
        break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap); /* очистка, когда все сделано */
}