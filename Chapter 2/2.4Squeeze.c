#include <stdio.h>

void squezee(char s1[], char s2[]);

int main()
{
    char s1[50]="Homo Erectus will be promise";
    char s2[50]="jony can be Homo, but can be gomo too";;
    squezee(s1, s2);
    printf("%s\n", s1);
}

void squezee(char s1[], char s2[])
{
    int i, k, j;
    for (i=0; s2[i]!='\0'; i++)
    {
        for (k=j=0; s1[j]!='\0'; j++)
        {
            if(s1[j]!=s2[i] || (s1[j]==' ' || s1[j]=='\t'))
            {
                s1[k++]=s1[j];
            }
        }
         s1[k]='\0';
    }
}

