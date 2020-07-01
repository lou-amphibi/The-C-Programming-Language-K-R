#include <stdio.h>

int main()
{
int i, c, n[5];
for(i=0; i<5; i++)
{
c=getchar();
if(c=='\n')
{
    i--;
}
else if (c>='0' && c<='9')
{
   n[i]=c-'0';
}
else
{
    printf("No\n");
    i--;
}
}

for(i=0; i<5; i++)
{
printf("%d", n[i]);
}
printf("\n");
}