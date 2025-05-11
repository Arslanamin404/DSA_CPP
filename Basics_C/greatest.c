#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter a number: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a > b)
    {
        if (a > c)
            printf("%d is greates", a);
        else
            printf("%d is greates", c);
    }
    else
    {
        if (b > c)
            printf("%d is greates", b);
        else
            printf("%d is greates", c);
    }

    return 0;
}