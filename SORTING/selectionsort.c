#include <stdio.h>
void selectionsort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i <= (n - 2); i++)
    {
        min = i;
        for (j = (i + 1); j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    int a[15], i, n;
    printf("no of elements\n");
    scanf("%d", &n);
    printf("elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionsort(a, n);
    printf("sorted array\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}
