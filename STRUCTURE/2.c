#include <stdio.h>
#include <string.h>
struct student
{
    int rn;
    char name[20];
    int age;
    int marks;
} s[5];
int main()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("enter the roll no\n");
        scanf("%d", &s[i].rn);
        printf("enter the name\n");
        fflush(stdin);
        gets(s[i].name);
        printf("enter the age\n");
        scanf("%d", &s[i].age);
        printf("enter marks\n");
        scanf("%d", &s[i].marks);
    }
    printf("the details of student with Roll NO=1\n");
    printf("Name=");
    puts(s[0].name);
    printf("Age= %d\n", s[0].age);
    printf("the marks are %d", s[0].marks);
}