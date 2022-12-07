#include <stdio.h>
void swap(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void quicksort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partiition(a, l, h);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, h);
    }
}
int partiition(int a[], int l, int h)
{
    int i, j, pivot;
    i = l;
    j = h + 1;
    pivot = a[l];
    do
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);

    if (i > j)
    {
        swap(a[j], a[l]);
    }
    return j;
}
int main()
{
    int a[15], i, n;
    printf("no of elements\n");
    scanf("%d", &n);
    printf("elements\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 1, n);
    printf("sorted array\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }

    return 0;
}
