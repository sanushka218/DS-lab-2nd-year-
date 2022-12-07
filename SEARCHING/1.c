/*linear search*/
#include <stdio.h>
int linearsearch(int a[], int key, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int a[10], i, n,key,f;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the element to be found\n");
    scanf("%d", &key);
    f=linearsearch(a,key,n);
    if (f==-1)
    {
        printf("element not found\n");
    }
    else{
        printf("element found at index %d\n", f);
    }
    
}
