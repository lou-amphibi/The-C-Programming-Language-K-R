#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void miscan(char *fmt, ...);

int main()
{
    int b=0;
    char s[10];
    float f=0;
     miscan("%d", &b);
    //miscan("%f %d %s", &f, &b, s);
    //printf("%.1f %d %s\n", f, b, s);
    printf("%d\n", b);
}

void miscan(char *fmt, ...)
{
    va_list ap;
    char point[100];
    int c;
    char *pp=point;
    char *p;
    int *ival=NULL;
    float *dval=NULL;
    char *sval;
    unsigned int *xval=NULL;
    va_start(ap, fmt); /* устанавливает ap на 1-й безымянный аргумент */
    for (p=fmt; *p; p++)
    {
        if (*p !='%')
        {
            continue;
        }
        switch (*++p) {
        case 'd':     // Вариант через гетчар
            ival=va_arg(ap, int *);
            while ( isdigit(c=getchar()))
                *pp++=c;
            *ival=atof(point);
            break;
    /*    case 'd':
            ival = va_arg(ap, int *);
            scanf("%f", ival);
            break;
        case 'f':
            dval = va_arg(ap, float *);
            scanf("%f", dval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            scanf("%s", sval);
            break;
        case 'x':
            xval= va_arg(ap, unsigned int *);
            scanf ("%x", xval);
            break; */
        default:
            break;
        }
    }
    va_end(ap); /* очистка, когда все сделано */
}