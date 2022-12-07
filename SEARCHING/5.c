#include <stdio.h>
int interpolationsearch(int a[], int n, int x)
{
    int l, h, pos;
    l = 0;
    h = n - 1;
    while (l <= h && x >= a[l] && x <= a[h])
    {
        if (l == h)
        {
            if (a[l] == x)
            {
                return l+1;
            }
            else
                return -1;
        }
        pos = l + ((h - l) / (a[h] - a[l])) * (x - a[l]);
        if (a[pos] == x)
        {
            return pos+1;
        }
        else if (a[pos] < x)
        {
            l = pos + 1;
        }
        else
            h = pos - 1;
    }
    return -1;
}
int main()
{
    int a[10], i, x, n, f;
    int l, h;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the number you want to search\n");
    scanf("%d", &x);
    f = interpolationsearch(a, n, x);
    if (f==-1)
    {
        printf("number doesnt exist in the array\n");
    }
    else
    {
        printf("number is at position %d",f);
    }
    
    return 0;
}
