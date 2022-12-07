#include <stdio.h>
struct complex
{
    int real, imag;
} c[3];
int main()
{
    int i, sumr=0, sumi=0, mulr=1, muli=1, mi=0,subr=0,subi=0;
    for (i = 0; i < 2; i++)
    {
        printf("enter the real part\n");
        scanf("%d", &c[i].real);
        printf("enter the imaginary part\n");
        scanf("%d", &c[i].imag);
        sumr = sumr + c[i].real;
        sumi = sumi + c[i].imag;
        subr=c[0].real-c[1].real;
        subi=c[0].imag-c[1].imag;
        mulr = mulr * c[i].real;
        muli = muli *c[i].imag;
        mi = mi + (c[0].real * c[1].imag) + (c[1].real * c[0].imag);
    }
    printf("sum is %d+%di\n", sumr, sumi);
    printf("subtarction is %d+%di\n", subr, subi);
    printf("multiplication is %d+%di\n", mulr - muli, mi);
     return 0;
}
