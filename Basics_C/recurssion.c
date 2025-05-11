#include <stdio.h>
int sum(int n);
int factorial(int n);
void getNaturalNums(int n);
void getReverseNaturalNums(int n);
void oddNums(int n);
void reverseOddNums(int n);
void evenNums(int n);
void reverseEvenNums(int n);
void squareNums(int n);
void DTB(int n);
void DTO(int n);
void reverse(int n);
int sumOddNums(int n);
int sumEvenNums(int n);
int sumSquares(int n);
int sumDigits(int n);
int hcf(int a, int b);
int countDigits(int n);
float powerOf(float base, float power);

int main()
{
    // printf("Sum of first 5 numbers is %d", sum(5));
    // printf("%d", factorial(3));
    // getNaturalNums(10);
    // getReverseNaturalNums(10);
    // oddNums(5);
    // reverseOddNums(5);
    // evenNums(5);
    // reverseEvenNums(5);
    // squareNums(5);
    // DTB(25);
    // DTO(25);
    // reverse(12345);
    // printf("%d ", sumOddNums(2));
    // printf("%d ", sumEvenNums(2));
    // printf("%d ", sumSquares(2));
    // printf("%d ", sumDigits(123));
    // printf("%d ", hcf(35, 49));
    // printf("%d ", countDigits(1251));
    printf("%.2f ", powerOf(2, -1));
    return 0;
}

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return (n * factorial(n - 1));
}

void getNaturalNums(int n)
{
    if (n > 0)
    {
        getNaturalNums(n - 1);
        printf("%d ", n);
    }
}

void getReverseNaturalNums(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        getReverseNaturalNums(n - 1);
    }
}

void oddNums(int n)
{
    if (n > 0)
    {
        oddNums(n - 1);
        printf("%d ", (2 * n) - 1);
    }
}

void reverseOddNums(int n)
{
    if (n > 0)
    {
        printf("%d ", (2 * n) - 1);
        reverseOddNums(n - 1);
    }
}

void evenNums(int n)
{
    if (n > 0)
    {
        evenNums(n - 1);
        printf("%d ", 2 * n);
    }
}

void reverseEvenNums(int n)
{
    if (n > 0)
    {
        printf("%d ", 2 * n);
        reverseEvenNums(n - 1);
    }
}

void squareNums(int n)
{
    if (n > 0)
    {
        squareNums(n - 1);
        printf("%d ", n * n);
    }
}

void DTB(int n)
{
    // Decimal to binary
    if (n > 0)
    {
        DTB(n / 2);
        printf("%d", n % 2);
    }
}

void DTO(int n)
{
    // Decimal to octal
    if (n > 0)
    {
        DTO(n / 8);
        printf("%d", n % 8);
    }
}

void reverse(int n)
{
    if (n > 0)
    {
        printf("%d", n % 10);
        reverse(n / 10);
    }
}

int sumOddNums(int n)
{
    if (n == 1)
        return 1;
    return (2 * n) - 1 + sumOddNums(n - 1);
}

int sumEvenNums(int n)
{
    if (n == 1)
        return 2;
    return (2 * n) + sumEvenNums(n - 1);
}

int sumSquares(int n)
{
    if (n == 1)
        return 1;
    return (n * n) + sumSquares(n - 1);
}

int sumDigits(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int hcf(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a > b)
        return hcf(a % b, b);
    else
        return hcf(a, b % a);
}

int countDigits(int n)
{
    if (n == 0)
        return 0;
    return countDigits(n / 10) + 1;
}

float powerOf(float base, float power)
{
    if (power == 0)
        return 1;
    if (power > 0)
    {
        return base * powerOf(base, power - 1);
    }
    else
    {
        return (powerOf(base, power + 1) / base);
    }
}
