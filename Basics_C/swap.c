#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Value of a=%d and b=%d\n", a, b);
    // a=10,b=5
    // a= a+b;//15
    // b= a-b//10
    // a = a-b//5
    // a=5, b=10

    a = a + b;
    b = a - b;
    a = a - b;
    printf("Value of a=%d and b=%d\n", a, b);
    return 0;
}