#include <stdio.h>
void radixsort(int a[], int n, int d)
{
    int c[10] = {0}, b[10], i, j;
    for ( i = 1; i <= d; i++)
    {
        a[i]=a[i]%10;
        a[i]=a[i]/10;
        for (i = 0; i < n; i++)
        {
            c[a[i]]++;
        }
        for (i = 1; i <= 9; i++)
        {
            c[i] = c[i] + c[i - 1];
        }
        for (j = n - 1; j >= 0; j--)
        {
            b[c[a[j]] - 1] = a[j];
            c[a[j]]--;
        }
        for (j = 0; j < n; j++)
        {
            a[i] = b[i];
        }
    }
    printf("sorted array is :-\n");
    for (j = 0; j < n; j++)
    {
        printf("%d\t", b[i]);
    }
}

int main()
{
    int a[10], n, d, i;
    printf("enter the number of digits\n");
    scanf("%d", &d);
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    radixsort(a, n, d);
    return 0;
}
