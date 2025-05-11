#include <stdio.h>
int main()
{
    float side_1, side_2, side_3;
    printf("enter sides of triangle: ");
    scanf("%f %f %f", &side_1, &side_2, &side_3);
    if ((side_1 + side_2) > side_3 && (side_2 + side_3) > side_1 && (side_3 + side_1) > side_2)
        printf("Valid triangle");
    else
        printf("Invalid triangle");

    return 0;
}