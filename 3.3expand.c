#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s[], char s1[]);

int main()
{
    char s1[40]="b-v a-j0-7 a-b-c -a-d";
    char s3[30]="a-g a-b-c -a-e";
    char s2[600]=" ";
    expand(s1, s2);
    printf("%s\n", s2);
}

void expand(char s[], char s1[])
{
    int n, j=0;
    n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(isalpha(s[i])!=0 && s[i+1]=='-' && isalpha(s[i+2])!=0 && s[i]<s[i+2])
        {
            int tab=s[i+2]-s[i];
            for (int y=0; tab>0; tab--, y++)
            {
                s1[j++]=s[i]+y;
            }
            i++;
        }
        else if(isdigit(s[i])!=0 && s[i+1]=='-' && isdigit(s[i+2])!=0 && s[i]<s[i+2])
        {
            int tab=s[i+2]-s[i];
            for (int y=0; tab>0; tab--, y++)
            {
                s1[j++]=s[i]+y;
            }
            i++;
        }
        else
        {
        s1[j++]=s[i];
        }
    }
    s1[j]='\0';
}