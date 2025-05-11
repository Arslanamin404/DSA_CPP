// wap to calc square of a num. take input from user
#include <stdio.h>
int main()
{
    int num, square;
    printf("Enter any integer value: ");
    scanf("%d", &num);
    square = num * num;
    printf("Square of %d is %d.\n", num, square);
    return 0;
}