#include <stdio.h>
#include <time.h>
#define isupeer2(c) (c>='A' && c<='Z')
int isupeer(char c);


int main()
{
    char c='B';
    char a='b';
    clock_t start, stop, start1, stop1;
    start=clock();
    int i=isupeer(c);
    stop=clock();
    int j=isupeer(a);
    printf("%d %d\n", i , j);
    start1=clock();
    int f=isupeer2(c);
    stop1=clock();
    printf("Функция - %ld\n", stop-start);
    printf("Макрос - %ld\n", stop1-start1);
}


int isupeer(char c)
{
    return (c>='A' && c<='Z') ? c : 0;
}

