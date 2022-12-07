#include <stdio.h>
#include <stdlib.h>
void input(int *arr, int n)
{
    int i;
    printf("enter the elements\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", (arr+i));
    }
}
void output(int *arr, int n)
{
    int i;
    printf("the elements are\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d", *(arr+i));
    }
}
int main()
{
    int n,*arr;
    arr = (int *)malloc(n * sizeof(int));
    printf("enter the number of elements\n");
    scanf("%d", &n);
    input(arr, n);
    output(arr, n);
    return 0;
}
