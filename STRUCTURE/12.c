#include <stdio.h>
#include <string.h>
struct em
{
    char name[10];
    int s;
    int hr;
} e[5];
int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("enter the name\n");
        fflush(stdin);
        gets(e[i].name);
        printf("enter the salary\n");
        scanf("%d", &e[i].s);
        printf("enter the hours of work per day\n");
        scanf("%d", &e[i].hr);
    }
    for ( i = 0; i < 5; i++)
    {
        if (e[i].hr>8)
        {
            e[i].s=e[i].s+50;
        }
    }
    printf("final salaries of employes\n");
    for ( i = 0; i < 5; i++)
    {
        puts(e[i].name);printf(": %d\n", e[i].s);
    }
    
    

    return 0;
}

