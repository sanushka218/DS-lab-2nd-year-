#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    char name[10];
    int rn;
} * s[5];
void input(struct data *s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("enter the name\n");
        scanf("%s", (s[i]->name));
        printf("enter the roll number\n");
        scanf("%d", &(s[i]->rn));
    }
}
void output(struct data *s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("the name is ");
        printf("%s", s[i]->name);
        printf("the roll number ");
        printf("%d", (s[i]->rn));
    }
}
int main()
{
    int n;
    s = (struct data *)malloc(sizeof(struct data));
    putc("enter the number of students\n");
    scanf("%d", &n);
    printf("enter the data for the student\n");
    input(s, n);
    output(s, n);
    return 0;
}
