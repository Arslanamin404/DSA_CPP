#include <stdio.h>
#include <math.h>

void get_oddNums(int size);
void get_evenNums(int size);
void sum_first_evenNums(int size);
void count_digits(int num);
int isPrime(int num);
int max(int a, int b);
int min(int a, int b);
int lcm(int a, int b);
int reverse_number(int num);
int fibonacci(int term);
void first_n_fibonacci(int n);
int hcf(int a, int b);
int isCoprime(int a, int b);
void get_n_prime_numbers(int n);
void range_prime_numbers(int a, int b);
long long next_prime(long long num);
int isArmstrong(int num);
void first_n_armstrong(int n);

int main()
{
    // get_oddNums(10);
    // get_evenNums(10);
    // sum_first_evenNums(5);
    // count_digits(2323);
    // isPrime(10) ? printf("\nPRIME\n") : printf("NOT PRIME\n");
    // isPrime(2) ? printf("PRIME\n") : printf("NOT PRIME\n");
    // isPrime(23) ? printf("PRIME\n") : printf("NOT PRIME\n");
    // isPrime(7) ? printf("PRIME\n") : printf("NOT PRIME\n");
    // isPrime(3) ? printf("PRIME\n") : printf("NOT PRIME\n");
    // isPrime(8) ? printf("PRIME\n") : printf("NOT PRIME\n");
    // printf("%d\n", lcm(2, 6));
    // printf("%d\n", lcm(12, 18));
    // printf("%d\n", lcm(1, 12));
    // printf("%d\n", reverse_number(11342));
    // printf("%d\n", fibonacci(6));
    // first_n_fibonacci(6);
    // isCoprime(14, 21) ? printf("CoPrime\n") : printf("Not CoPrime\n");
    // get_n_prime_numbers(100);
    // range_prime_numbers(1, 10);
    // printf("%lld ", next_prime(9999999));
    // isArmstrong(5) ? printf("Armstrong\n") : printf("Not Armstrong\n");
    first_n_armstrong(1000);

    return 0;
}

void get_oddNums(int size)
{
    int n = 0;
    printf("First %d odd numbers are: \n", size);
    while (n != size)
    {
        printf("%d ", (2 * n) + 1);
        n++;
    }
}

void get_evenNums(int size)
{
    int n = 1;
    printf("\nFirst %d even numbers are: \n", size);
    while (n != size)
    {
        printf("%d ", (2 * n));
        n++;
    }
}

void sum_first_evenNums(int size)
{
    int count = 0, i = 2, sum = 0;
    while (count != size)
    {
        if (i % 2 == 0)
        {
            sum += i;
            count++;
        }
        i++;
    }
    printf("\nSum of first %d even numbers is: %d\n", size, sum);
}

void count_digits(int num)
{
    int temp = num;
    int count = 0;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    printf("%d has %d digits", num, count);
}

int isPrime(int num)
{
    if (num < 2)
        return 0;
    for (int i = 2; i <= (int)sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int lcm(int a, int b)
{
    for (int i = max(a, b); i <= a * b; i++)
    {
        if (i % a == 0 && i % b == 0)
            return i;
    }
    return 0;
}

int reverse_number(int num)
{
    int reverse_numberd_num = 0, last_digit;
    while (num != 0)
    {
        last_digit = num % 10;
        reverse_numberd_num = (reverse_numberd_num * 10) + last_digit;
        num /= 10;
    }

    return reverse_numberd_num;
}

int fibonacci(int term)
{
    int zeroth_term = 0, first_term = 1, fib = 0;
    if (term == 0 || term == 1)
        return term;

    for (int i = 2; i <= term; i++)
    {
        fib = zeroth_term + first_term;
        zeroth_term = first_term;
        first_term = fib;
    }

    return fib;
}

void first_n_fibonacci(int n)
{
    for (int i = 0; i <= n; i++)
        printf("%d ", fibonacci(i));
}

int hcf(int a, int b)
{
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            printf("%d\n", i);
            return i;
        }
    }
    return 1;
}

int isCoprime(int a, int b)
{
    if (hcf(a, b) == 1)
        return 1;
    return 0;
}

void get_n_prime_numbers(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }
}

void range_prime_numbers(int a, int b)
{
    for (int i = min(a, b); i <= max(a, b); i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }
}

long long next_prime(long long num)
{
    int temp = num;
    while (1)
    {
        temp++;
        if (isPrime(temp))
            return temp;
    }
}

int isArmstrong(int num)
{
    int temp = num;
    int digit_count = 0;
    int armstrong = 0;
    int last_digit = 0;
    while (temp)
    {
        temp /= 10;
        digit_count++;
    }
    temp = num;
    while (temp)
    {
        last_digit = temp % 10;
        armstrong += pow(last_digit, digit_count);
        temp /= 10;
    }
    if (armstrong == num)
    {
        return num;
    }
    return 0;
}

void first_n_armstrong(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isArmstrong(i))
            printf("%d ", i);
    }
}
