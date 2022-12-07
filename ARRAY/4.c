#include<stdio.h>
int main()
{
    int n,i,j,x,a[10];
    printf("enter the number of elemnts\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the position of element to be deleted\n");
    scanf("%d", &i);
    x=a[i];
    for(j=i;j<n;j++)
    {
        a[j]= a[j+1];
        n=n-1;
    }
    printf("new array\n");
    for(i=0;i<n;i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}
