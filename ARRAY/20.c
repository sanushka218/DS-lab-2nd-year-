#include <stdio.h>
int main()
{
    int a[10][10],i,j, r, c, d;
    printf("enter the number of rows of matrix\n");
    scanf("%d", &r);
    printf("enter the number of rows of matrix\n");
    scanf("%d", &c);
    if (r != c)
    {
        printf("As matrix isnt a square matrix, hence determiant cant be calculated\n");
    }
    else
    {
        printf("enter the elements of matrix") ;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        
    }

    return 0;
}
