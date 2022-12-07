#include <stdio.h>
struct height
{
    int inch;
    int feet;
} d[5];
int main()
{
    int sumi=0,sumf=0, i;
    for (i = 0; i < 3; i++)
    {
        printf("enter the distance in inch\n");
        scanf("%d", &d[i].inch);
        printf("enter the distnace in feet\n");
        scanf("%d", &d[i].feet);
        sumi= sumi+ d[i].inch; 
        sumf= sumf+d[i].feet;
    }
     printf("the sum of distances is %d feet %d inch\n",(sumf+sumi/12), (sumi%12) );
    return 0;
}