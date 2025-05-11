// swap 2 numbs without using 3rd variable, or + and minus operators
#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("a=%d, b=%d\n", a, b);
    // XOR operator
    // If c = a ^ b, then c ^ b = a and c ^ a = b.
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a=%d, b=%d\n", a, b);
    return 0;
}