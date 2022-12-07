#include<stdio.h>
void input(int *a, int n)
{
    int i;
    printf("enter the elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }
}
void output(int *a, int n)
{
    int i;
    printf("the array is\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d", *(a+i));
    }  
}
int main()
{
    int n, a[10];
    printf("enter the number of elements\n");
    scanf("%d", &n);
    input(a,n);
    output(a,n);
    return 0;
}
