#include <stdio.h>
void counting_sort(int a[], int n, int l)
{
    int c[10] = {0}, i, b[10], j;
    j = n - 1;
    for (i = 0; i < n;)
    {
        if (a[i] < a[j])
        {
            l = a[j];
            i++;
        }
        else
        {
            l = a[i];
            j--;
        }
        if (i == j || i > j)
        {
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    for (i = 1; i <=l; i++)
    {
        c[i] = c[i] + c[i - 1];
    }
    for (j = n-1; j >=0; j--)
    {
        b[c[a[j]]-1] = a[j];
        c[a[j]]--;
    }
    printf("the sorted array is :-\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", b[i]);
    }
}
int main()
{
    int a[10], n, l, i, j, b[10];
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    counting_sort(a, n, l);
    return 0;
}
