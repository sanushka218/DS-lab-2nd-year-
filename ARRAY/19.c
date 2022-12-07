#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],i,j,r,c;
    printf("enter the number of rows\n");
    scanf("%d", &r);
    printf("enter the number of columns\n");
    scanf("%d", &c);
    printf("enter the elements of the matrix\n");
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            b[i][j]= a[j][i];
        }
    }
    printf("the transpose of the matrix is \n");
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
