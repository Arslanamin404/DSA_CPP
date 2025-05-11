
#include <iostream>
using namespace std;

inline int sum(int, int);
inline float area_circle(float);
inline float volume_cuboid(float, float, float);
void swap(int &, int &);
inline int max(int, int);

int main()
{
    // int a, b;
    // cout << "Enter 2 numbers: ";
    // cin >> a >> b;
    // cout << "a=" << a << " b=" << b << endl;
    // swap(a, b);
    // cout << "a=" << a << " b=" << b << endl;

    // cout << max(10, 20);

    return 0;
}

inline int sum(int x, int y)
{
    return x + y;
}

inline float area_circle(float r)
{
    return 3.14 * (r * r);
}

inline float volume_cuboid(float length, float breadth, float height)
{
    return length * breadth * height;
}

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}
