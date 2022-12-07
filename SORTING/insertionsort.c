#include<stdio.h>
void insertionsort(int a[], int n)
{
    int i,j,k;
    for ( i = 2; i <= n; i++)
    {
        k= a[i], j=i-1;
        while (a[j]>k && j>0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k; 
    }
    
}
int main()
{
    int a[15],i,n;
    printf("no of elements\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for ( i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    insertionsort(a,n);
    printf("sorted array is\n");
     for ( i = 1; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
