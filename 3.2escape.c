#include <stdio.h>

void escape(char s[], char t[]);
void reverceescape (char s[]);

int main()
{
    char t[35]=" ";
    char s[45]="Sona!";
    int c, i=0;
    while((c=getchar())!=EOF)
    {
        t[i]=c;
        i++;
    }
    escape(s, t);
    printf("\n%s\n", s);
    reverceescape(s);
    printf("\n%s\n", s);
}


void escape(char s[], char t[])
{
    int j, i;
    for(j=0; s[j]!='\0'; j++)
    {
    ;
    }
    for(i=0; t[i]!='\0'; i++, j++)
    {
        switch (t[i]) {
            case '\t': s[j]='\\'; ;s[j+1]='t'; j++;  break;
            case '\n': s[j]='\\'; s[j+1]='n'; j++; break;
            default: s[j]=t[i]; break;
        }
    }
    s[j]='\0';
}

void reverceescape (char s[])
{
    int i, j;
    for (i=j=0; s[j]!='\0'; i++, j++)
    {
        switch (s[i]) {
            case '\\' : (s[i+1]=='t') ? s[j]='\t', i++: (s[i+1]=='n') ? s[j]='\n', i++: s[i]; break;
            default: s[j]=s[i]; break;
        }
    }
    s[j]='\0';
}


