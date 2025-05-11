// wap to calc sum of 2 nums. take input from user
#include <stdio.h>
int main()
{
    int a, b, sum;
    printf("Enter num1: ");
    scanf("%d", &a);
    printf("Enter num2: ");
    scanf("%d", &b);
    sum = a + b;
    printf("Sum of %d and %d = %d", a, b, sum);
    return 0;
}