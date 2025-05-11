#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int);
int heighestValueDigit(int);
double power(double, double);
int add(int, int, int = 0);
float add(float, float, float = 0);
float area(float);
float area(float, float);
int max(int, int);
double max(double, double);

int main()
{
    // isPrime(2) ? cout << "Prime " : cout << "Not prime ";
    // isPrime(5) ? cout << "Prime " : cout << "Not prime ";
    // isPrime(10) ? cout << "Prime " : cout << "Not prime ";

    // cout << heighestValueDigit(12812) << endl;
    // cout << heighestValueDigit(92812) << endl;
    // cout << heighestValueDigit(217) << endl;

    // cout << power(2, 2) << endl;
    // cout << power(2, 3) << endl;
    // cout << power(5, 3) << endl;
    // cout << power(5, 2) << endl;

    cout << add(10, 20) << endl;
    cout << add(10, 20, 30) << endl;
    return 0;
}

bool isPrime(int num)
{
    for (int i = 2; i <= (int)sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int heighestValueDigit(int num)
{
    int max = 0;
    while (num > 0)
    {
        int last_digit = num % 10;
        max = (last_digit > max) ? last_digit : max;
        num /= 10;
    }

    return max;
}

double power(double x, double y)
{
    if (x == 0)
        return 1;

    if (y > 0)
        return x * power(x, y - 1);
    else
        return x * power(x, y + 1);
}

int add(int x, int y, int z)
{
    return x + y + z;
}

float add(float x, float y, float z)
{
    return x + y + z;
}

float area(float r)
{
    return 3.14 * (r * r);
}

float area(float length, float breadth)
{
    return length * breadth;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

double max(double x, double y)
{
    return (x > y) ? x : y;
}
