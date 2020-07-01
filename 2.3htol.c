#include <stdio.h>
#include <math.h>
#include <ctype.h>

int htol(int s[]);
int htol2(char s[]);

int main()
{
    int n=0x0;
    int s[8]={0x1, 0x2, 0x3, 55};
    char s1[10]={'K', '0', 'x', '3', 'A', '5', '\0'};
    char s2[18]="Jal0Xffla0x3A5";
   printf("%x и в десятичной - %d\n", htol(s), htol(s));
   int k=htol2(s2);
   printf("%d в десятичном и в %x шестн.\n", k, k);

}


int htol(int s[])
{
    int i, n;
    n = 0x0;
    for (i = 0; s[i] >= 0x0 && s[i] <= 0xf; ++i)
        n = 0xa * n + s[i];
    return n;
}


int htol2(char s[])
{
    int i, n=0, j=-1;
    for (i=0; s[i]!='\0'; i++)
    {
        if (s[i]=='0' && (s[i+1]=='x' || s[i+1]=='X'))
        {
            int a=i+2;
            while((s[a]>='0' && s[a]<='9') || (s[a]>='a' && s[a]<='f') || (s[a]>='A' && s[a]<='F'))
            {
                if (s[a]>='A' && s[a]<='F')
                {
                    s[a]=tolower(s[a]);
                }
                if (s[a]>='a' && s[a]<='f')
                {
                    s[a]-='W';
                }
                else if(s[a]>='0' && s[a]<='9')
                {
                    s[a]-='0';
                }
                a++;
                j++;
            }
            i+=2;
            for(int y=j; y>=0; y--, i++)
            {
            n+=s[i]*pow(16, y);
            }
            j=-1;
            i--;
        }
    }
    return n;
}
