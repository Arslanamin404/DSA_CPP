// wap to calc avg of 3 nums. take input from user
#include <stdio.h>
int main()
{
    int a, b, c;
    float avg;
    printf("Enter 3 numbers: ");
    scanf("%d%d%d", &a, &b, &c);
    avg = (a + b + c) / 3.0;
    printf("Avegrage of %d,%d,%d = %.2f", a, b, c, avg);
    return 0;
} 