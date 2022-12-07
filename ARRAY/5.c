#include<stdio.h>
int main()
{
    int a[10], b[10], i, x, j, k, n, c[10];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    k = 0;
    for (i = 0; i < n; i++)
    {
        x = 1;
        j = (i + 1);
        if (j == n)
        {
            break;
        }
        while (a[i] != (a[j] - x))
        {
            c[k] = (a[i] + x);
            x++;
            k++;
        }
    }
    printf("the missing numbers are\n");
    for (i = 0; i < k; i++)
    {
        printf("%d\t", c[i]);
    }

    return 0;
}