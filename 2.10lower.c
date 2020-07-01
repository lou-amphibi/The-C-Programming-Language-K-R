#include <stdio.h>

void lower(char s[]);
int lower1(int x);

int main()
{
    int c, i=0;
    char y='H';
    char s[35]=" ";
    while((c=getchar())!=EOF)
    {
        s[i++]=c;
    }
    lower(s);
    printf("\n%s\n", s);
    printf("%c -> %c\n", y, lower1(y));
}


void lower(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        s[i]=(s[i]>='A' && s[i]<='Z') ? s[i]+=32 :s[i];
        i++;
    }
}

int lower1(int x)
{
     x=(x>='A' && x<='Z') ? x+=32 : x;
     return x;
}