#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data
{
    char name[10];
    int rn;
}*s;
void input(struct data *s)
{
    printf("enter the name\n");
    scanf("%s", (s->name));
    printf("enter the roll number\n");
    scanf("%d", &(s->rn));
}
void output(struct data *s)
{
    printf("the name is ");
   printf("%s", s->name);
    printf("the roll number ");
    printf("%d", (s->rn));
}
int main()
{
    s= (struct data*)malloc(sizeof(struct data));
    printf("enter the data for the student\n");
    input(s);
    output(s);
    return 0;
}
