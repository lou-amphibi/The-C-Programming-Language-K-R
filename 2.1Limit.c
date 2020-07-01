#include <stdio.h>
#include <limits.h>
#include <float.h>

long int howsym(int a);
long int signo(long a);
long int signp(long a);
// Для типа long
long int lsigno(unsigned long int a);
long int lsignp(unsigned long int a);
// Для плавающей точки
float floar();
double dfloar();
long double lfloar();

int main()
{
    char un[3];
    // Размеры в байтах
    puts("Размеры в байтах для различных значений через sizeof():");
    printf("int %lu\n", sizeof(int));
    printf("long %lu\n", sizeof(long));
    printf("short %lu\n", sizeof(short));
    printf("char %lu\n", sizeof(char));
    puts("Для плавающей точки");
    printf("float %lu\n", sizeof(float));
    printf("double %lu\n", sizeof(double));
    printf("long double %lu\n", sizeof(long double));
    // Через limits.h
    puts("Диапазон значений из limits.h:");
    puts("Signed:");
    printf("Signed char минимальное %d и максимальное %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Signed short минимальное %d и максимальное %d\n", SHRT_MIN, SHRT_MAX);
    printf("Signed int минимальное %d и максимальное %d\n", INT_MIN, INT_MAX);
    printf("Signed long минимальное %ld и максимальное %ld\n", LONG_MIN, LONG_MAX);
    puts("Unigned:");
    printf("Unsigned char минимальное 0 и максимальное %u\n", UCHAR_MAX);
    printf("Unsigned short минимальное 0 и максимальное %u\n", USHRT_MAX);
    printf("Unsigned int минимальное 0 и максимальное %u\n", UINT_MAX);
    printf("Unsigned long минимальное 0 и максимальное %lu\n", ULONG_MAX);
    // Прямое вычисление
    int a, b, c, d;
    a=((int)sizeof(char))*8;
    b=((int)sizeof(short))*8;
    c=((int)sizeof(int))*8;
    d=((int)sizeof(long))*8;
    puts("Прямое вычисление диапазона:");
    printf("Unsigned char минимальное 0 и максимальное %ld, Signed char - минимальное %ld и максимальное %ld\n", howsym(a), signo(howsym(a)), signp(howsym(a)));
    printf("Unsigned short минимальное 0 и максимальное %ld, Signed short - минимальное %ld и максимальное %ld\n", howsym(b), signo(howsym(b)), signp(howsym(b)));
    printf("Unsigned int минимальное 0 и максимальное %ld, Signed int - минимальное %ld и максимальное %ld\n", howsym(c), signo(howsym(c)), signp(howsym(c)));
    printf("Unsigned long минимальное 0 и максимальное %lu, Signed long - минимальное %ld и максимальное %ld\n", howsym(d), lsigno(howsym(d)), lsignp(howsym(d)));
    // Плавающая точка
    printf("Максимальное число с плавающей точкой %f\n", FLT_MAX);
    printf("Максимальное число с плавающей точкой double %lf\n", DBL_MAX);
    printf("Максимальное число с плавающей точкой long double %LF\n", LDBL_MAX);
    printf("Минимальное число с плавающей точкой %f\n", FLT_MIN);
    printf("Миниимальное число с плавающей точкой double %lf\n", DBL_MIN);
    printf("Минимальное число с плавающей точкой long double %LF\n", LDBL_MIN);
    // Прямое вычисление плавающей точки
    printf("Максимальное отрицательное число с плавающей точкой %f\n", floar());
    printf("Максимальное отрицательное число с плавающей точкой double %lf\n", dfloar());
    printf("Максимальное отрицательное число с плавающей точкой long double %Lf\n", lfloar());

}

long int howsym(int a)
{
    if (a==64)
    {
    unsigned long int c=1;
    for (int i=a; i>0; i--)
    {
        c*=2;
    }
    c-=1;
    return c;
    }
    else
    {
    long int c=1;
    for (int i=a; i>0; i--)
    {
        c*=2;
    }
    c-=1;
    return c;
    }
}


long int signo(long a)
{
    long int b=a/2;
    long int c=b-a;
    return c;
}

long int signp(long a)
{
    long int c=a/2;
    return c;
}

/**************************************/
long int lsigno(unsigned long int a)
{
    unsigned long int b=a/2;
    long int c=b-a;
    return c;
}

long int lsignp(unsigned long int a)
{
    unsigned long int c=a/2;
    return c;
}
/*****************************************/

float floar()
{
    float a=FLT_MAX;
    float b=FLT_EPSILON;
    float d=a-a;
    float c=d-a-FLT_EPSILON;
    return c;
}

double dfloar()
{
    double a=DBL_MAX;
    double b=DBL_EPSILON;
    double d=a-a;
    double c=d-a-DBL_EPSILON;
    return c;
}

long double lfloar()
{
    long double a=LDBL_MAX;
    long double b=LDBL_EPSILON;
    long double d=a-a;
    long double c=d-a-LDBL_EPSILON;
    return c;
}