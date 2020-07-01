#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

int main()
{
    double atof (char[]);
    char line[MAXLINE];
    int getline (char line[], int max);
    while (getline(line, MAXLINE) > 0)
        printf ("\t%g\n", atof(line));
    return 0;
}


double atof (char s[])
{
    double val, power, expo;
    int i, sign, sign1=0, flag=0;
    int sten=-1;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? sten : 1;
    if (s[i] =='+' || s[i] =='-')
        i++;
    for (val = 0.0; isdigit (s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i]=='e' || s[i]=='E')
    {
        flag=1;
        sign1= (s[i+1] == '-') ? i+=2, sten : (s[i+1]== '+') ? i+=2, 0 : (isdigit(s[i+1])) ? i+=1, 0 : 2;
        for (expo = 0.0; isdigit (s[i]); i++)
            expo = 10.0 * expo + (s[i] - '0');
        expo = pow(10, expo);
    }
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i]=='e' || s[i]=='E')
    {
        flag=1;
        sign1= (s[i+1] == '-') ? i+=2, sten : (s[i+1]== '+') ? i+=2, 0 : (isdigit(s[i+1])) ? i+=1, 0 : 2;
        for (expo = 0.0; isdigit (s[i]); i++)
            expo = 10.0 * expo + (s[i] - '0');
        expo = pow(10, expo);
    }
    if (flag==1 && sign1==sten)
    {
        return (sign * val / power) / expo;
    }
    else if (flag==1 && sign1==0)
    {
        return (sign * val / power)*expo;
    }
    else
    {
    return sign * val / power;
    }
}


int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


