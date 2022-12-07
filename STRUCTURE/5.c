#include<stdio.h>
struct complex {
    int real; int imag;
}c[2];
int main()
{
    int i,sumr=0,sumi=0;
    for ( i = 0; i < 2; i++)
    {
        printf("enter the real part\n");scanf("%d", &c[i].real);
        printf("enter the imag part\n");scanf("%d", &c[i].imag);
        printf("the entered the complex number is %d+%di\n", c[i].real, c[i].imag);
        sumr=sumr+c[i].real;
        sumi=sumi+c[i].imag;
    }
    printf("the sum of the complex number is %d + %di", sumr, sumi);
    return 0;
}
