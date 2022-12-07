#include<stdio.h>
struct time{
    int hour, min, sec;
}t[3];
int main()
{
    int i,sums=0,summ=0,sumh=0;
    for ( i = 0; i < 2; i++)
    {
        printf("enter time in second\n");scanf("%d", &t[i].sec);
        printf("enter time in min\n");scanf("%d", &t[i].min);
        printf("enter time in hour\n");scanf("%d", &t[i].hour);
        sums=sums+t[i].sec;
        summ= summ+t[i].min;
        sumh=sumh+t[i].hour;
    }
    printf("the time is %d hr %d min %d sec\n",(sumh+summ/60),((summ+sums/60)%60),(sums%60)); 
    
    
    return 0;
}
