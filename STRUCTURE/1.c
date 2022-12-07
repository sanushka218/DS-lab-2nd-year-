#include <stdio.h>
#include <string.h>
struct student
{
    int rn;
    char name[20];
    int marks[6];
} s[5];
int main()
{
    int sum , total, min, i,j;
    float per;
    for (j = 0; j< 6; j++)
    {
        printf("enter the roll number of student\n");
        scanf("%d", &s[j].rn);
        printf("enter the name of the student\n");
        fflush(stdin);
        gets(s[j].name);
        printf("enter the marks in following subjects\n");
        printf("maths: physics: chem: english: IT: PE:");
        for (i = 0; i < 6; i++)
        {
            scanf("%d", &s[j].marks[i]);
        }
    }
    printf("the entered data of student is\n");
    for (j = 0; j < 6; j++)
    {
        sum=0;
        printf("Roll No- %d\n", s[j].rn);
        printf("Name - ");
        puts(s[j].name);
        printf("marks are\n");
        for (i = 0; i < 6; i++)
        {
            printf("%d\t", s[j].marks[i]);
        }
        printf("\n");
        for (i = 0; i < 6; i++)
        {
            sum = sum + s[j].marks[i];
        }
        min = s[j].marks[0];
        for (i = 0; i < 6; i++)
        {
            if (min > s[j].marks[i])
            {
                min = s[j].marks[i];
                s[j].marks[i] = __INT_MAX__;
            }
        }
        sum = sum - min;
        min = s[j].marks[0];
        for (i = 0; i < 6; i++)
        {
            if (min > s[j].marks[i])
            {
                min = s[j].marks[i];
            }
        }
        total = sum - min;
        per = total / 4;
        if (per >= 95.0)
        {
            printf("Student is elegible for DU\n");
        }
        else
        {
            printf("Student NOT elegible for DU\n");
        }
    }
    return 0;
}
