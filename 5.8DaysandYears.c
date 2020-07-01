#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int year=1993;
    int month=8;
    int day=14;
    int yearday=124;
    int x, y;
    int *pmoth=&x;
    int *pday=&y;
    month_day(year, yearday, pmoth, pday);
    printf("День года %d и %d месяц - %d день\n", day_of_year(year, month, day), *pmoth, *pday);

}


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: определяет день года по месяцу и дню */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    if ((year>0 && month>0 && day>0) && (month>=1 && month<=12)) {
        leap = (year % 4 == 0 && year % 100 !=0) || year % 400 == 0;
        //Проверяем день
        if (leap==0 && day>365)
            return 0;
        else if (leap==1 && day>366)
            return 0;
        for (i = 1; i < month; i++)
            day += daytab[leap][i];
        return day;
        }
    else
    {
        return 0;
    }
}

/* month_day: определяет месяц и день по дню года */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if (year>0 && yearday>0)
    {
        leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        if ((leap==0 && (yearday>=1 && yearday<=365)) || (leap==1 && (yearday>=1 && yearday<=366)))
        {
            for (i = 1; yearday > daytab[leap][i]; i++)
                yearday -= daytab[leap][i];
            *pmonth = i;
            *pday = yearday;
        }
        else
        {
            *pmonth = 0;
            *pday = 0;
        }
    }
    else
    {
        *pmonth = 0;
        *pday = 0;
    }
}