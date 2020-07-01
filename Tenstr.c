#include <stdio.h>

int main ()
{
int c, i=0, len=0, lim=0;
char one[120]="g", two[120]="t";
while((c=getchar())!=EOF)
{
    one[len]=c;
    len++;
    if(len>10 && c=='\n')
    {
          while(one[lim]!='\n')
        {
            two[i]=one[lim];
            i++;
            lim++;
        }
        if (one[lim]=='\n')
        {
            two[i]='\n';
            i++;
            lim=0;
            len=0;
        }
    }
    else if (len<=9 && c=='\n')
    {
         len=0;
    }
}
//На случай EOF без нажатия \n, забота о пользователе//
if (len>10)
{
    for (int g=0; g<len; g++)
    {
        two[i]=one[g];
        i++;
    }
two[i]='\n';
}
printf("\n%s", two);
}

