#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int s[9]={11, 12, 13, 14, 15, 16, 17, 18};
    int i=0;
    for (i=0; s[i]!='\0'; i++)
    {
    ;
    }
    printf("%d\n", binsearch(18, s, i));
}



int binsearch(int x, int v[], int n)
{
    int low, high, mid, el;
    low = 0;
    high = n-1;
    mid=low+high;
    el=-1;
    if (!(x>=v[0] && x<=v[high] ))
    {
        return el;
    }
    while (x!=v[mid])
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low=mid+1;
        }
    }
        return mid;
}