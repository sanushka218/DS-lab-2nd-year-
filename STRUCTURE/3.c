#include <stdio.h>
#include <string.h>
struct data
{
    int r;
    char name[20];
    int age;
    char address[30];
    int marks;
} s[15];
int main()
{
    int i;
    for (i = 0; i < 15; i++)
    {
        printf("enter the roll no\n");
        scanf("%d", &s[i].r);
        printf("enter the name\n");
        fflush(stdin);
        gets(s[i].name);
        printf("enter the age\n");
        scanf("%d", &s[i].age);
        printf("enter the address\n");
        fflush(stdin);
        gets(s[i].address);
        printf("enter the marks\n");
        scanf("%d", &s[i].marks);
    }
    printf("the details are\n");
    for (i = 0; i < 15; i++)
    {
        printf("the roll no is %d\n", s[i].r);
        printf("the name : ");
        puts(s[i].name);
        printf("the age: %d\n", s[i].age);
        printf("the address: ");
        puts(s[i].address);
        printf("the marks: %d\n", s[i].marks);
    }
    return 0;
}