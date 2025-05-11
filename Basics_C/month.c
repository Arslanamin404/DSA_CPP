#include <stdio.h>
int main()
{
    int month_number;
    printf("enter the month number: ");
    scanf("%d", &month_number);
    if (month_number > 12)
        printf("Invalid Month number");
    else
    {
        if ((month_number % 2 != 0 && month_number != 2) || month_number == 8)
            printf("31 days");
        else if (month_number % 2 == 0 && month_number != 2)
            printf("30 days");
        else
            printf("28 or 29 days");
    }

    return 0;
}