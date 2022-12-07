#include <stdio.h>
#include <string.h>
struct students
{
    int r;
    int age;
    char name[10];
    char address[20];
} s[5];

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("enter the roll no\n");
        scanf("%d", &s[i].r);
        printf("enter the name\n");
        fflush(stdin);
        gets(s[i].name);
        printf("enter the age: the age should be between 11 to 14\n");
        scanf("%d", &s[i].age);
        printf("enter the address\n");
        fflush(stdin);
        gets(s[i].address);
    }
    printf("students name with age 14\n");
    for (i = 0; i < 15; i++)
    {
        if (s[i].age == 14)
        {
            puts(s[i].name);
            printf("\n");
        }
    }

    return 0;
}
