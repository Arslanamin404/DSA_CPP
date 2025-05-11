// wap to calc simple interest. take input from user
#include <stdio.h>
int main()
{
    int principal_ammount, rate, time;
    float simple_interest;
    printf("Enter principal ammount: ");
    scanf("%d", &principal_ammount);

    printf("Enter rate: ");
    scanf("%d", &rate);

    printf("Enter time period(years): ");
    scanf("%d", &time);

    simple_interest = (principal_ammount * rate * time) / 100.0;

    printf("principal_ammount = %d\nrate = %d\ntime_period = %dyear\nsimple_interest = %.2f", principal_ammount, rate, time, simple_interest);
    return 0;
}