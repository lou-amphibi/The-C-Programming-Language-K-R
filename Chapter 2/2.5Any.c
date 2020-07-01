#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[25]=" Synapsiide man";
    char s2[25]=" Jorfar me!";
    int a=any(s1, s2);
    printf("%d\n", a);
}

int any(char s1[], char s2[])
{
    int i, j, n=-1;
    for (i=0; s1[i]!='\0' && n==-1; i++)
    {
        for (j=0; s2[j]!='\0' && n==-1; j++)
        {
            if(s2[j]==s1[i] && (s1[i]!=' ' && s1[i]!='\t'))
            {
                n=i;
            }
        }
    }
    return n;
}