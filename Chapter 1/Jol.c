#include <stdio.h>

int main()
{
int c, simbols[4]={0}, i=0, n=0;
while((c=getchar())!=EOF)
{
    if (c==' ' || c=='\n' || c=='\t')
    {
        ++simbols[0];
    }
    else if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
    {

        ++simbols[1];
    }
    else if(c>='0' && c<='9')
    {
        ++simbols[2];
    }
    else
    {
        ++simbols[3];
    }
}
for (i=0; i<4; i++)
{
    for (n=0; n<simbols[i]; n++)
    {
    putchar('_');
    }
if (i==0)
{
    printf(" Пробелов и эскейпов %d\n", simbols[i]);
}
else if (i==1)
{
    printf(" Букв %d\n", simbols[i]);
}
else if (i==2)
{
    printf(" Цифр %d\n", simbols[i]);
}
else
{
    printf(" Остальных %d\n", simbols[i]);
}
}
}