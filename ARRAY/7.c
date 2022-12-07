#include <stdio.h>
int main()
{
    int a[10], i, j, n, t;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    /*revreal of array*/
    i = 0;
    j = n - 1;
    while (i < j)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
    printf("the reversed array is given as\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
        return 0;
}
