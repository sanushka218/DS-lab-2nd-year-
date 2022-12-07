#include <stdio.h>
#include <string.h>
struct customer
{
    char name[10];
    int an, b;
} c[5];
int more()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (c[i].b > 1000)
        {
            c[i].b = c[i].b + 100;
            puts(c[i].name);
            printf("final balance: %d\n", c[i].b);
        }
    }
    return 0;
}
int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("enter the name\n");
        fflush(stdin);
        gets(c[i].name);
        printf("enter the account number\n");
        scanf("%d", &c[i].an);
        printf("enter the balance\n");
        scanf("%d", &c[i].b);
    }
    printf("names with balance less than 200\n");
    for (i = 0; i < 5; i++)
    {
        if (c[i].b < 200)
        {
            puts(c[i].name);
        }
    }printf("\n");
    more();
    

    return 0;
}
