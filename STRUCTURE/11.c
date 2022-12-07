#include <stdio.h>
#include <string.h>
struct date
{
    int date, month, year;
} d[5];
int main()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        printf("enter the date\n");
        scanf("%d", &d[i].date);
        printf("enter the month\n");
        scanf("%d", &d[i].month);
        printf("enter the year\n");
        scanf("%d", &d[i].year);
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            if (d[i].date == d[j].date && d[i].month == d[j].month && d[i].year == d[j].year)
            {
                printf("dates: %d/%d/%d & %d/%d/%d are equal\n", d[i].date, d[i].month, d[i].year, d[j].date, d[j].month, d[j].year);
            }
            else
            {
                printf("dates: %d/%d/%d & %d/%d/%d are NOT equal\n", d[i].date, d[i].month, d[i].year, d[j].date, d[j].month, d[j].year);
            }
        }
    }

    return 0;
}
