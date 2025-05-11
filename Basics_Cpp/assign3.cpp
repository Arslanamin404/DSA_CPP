#include <iostream>
using namespace std;

void set_array(int *, int);
void get_array(int *, int);
void sort_array(int *, int, bool = true);
int max(int, int, int);
int min(int, int);
int lcm(int, int, int);
bool isPrime(int);
int nextPrime(int);
void primeFacots(int);
int hcf(int, int);
string subString(string, int, int);
void swap_array(int *, int *, int);
void merge_array(int *, int *, int);

int main()
{
    // int size = 5;

    // int arr1[size];
    // int arr2[size];

    // set_array(arr1, size);
    // set_array(arr2, size);
    // cout << "\n===============================" << endl;
    // get_array(arr1, size);
    // cout << "\n===============================" << endl;
    // get_array(arr2, size);
    // cout << "\n===============================" << endl;

    // merge_array(arr1, arr2, size);

    // cout << "\n===============================" << endl;

    // get_array(arr1, size);
    // cout << "\n===============================" << endl;
    // get_array(arr2, size);

    // cout << "\n===============================" << endl;

    // swap_array(arr1, arr2, size);
    // cout << "\n===============================" << endl;

    // get_array(arr1, size);
    // cout << "\n===============================" << endl;
    // get_array(arr2, size);

    // sort_array(arr, size);
    // // sort_array(arr, size, false);
    // cout << "\n===============================" << endl;
    // get_array(arr, size);

    // cout << lcm(10, 20, 22) << endl;
    // cout << lcm(2, 3, 4) << endl;
    // cout << lcm(5, 7, 11) << endl;
    // cout << lcm(3, 6, 12) << endl;

    // cout << nextPrime(38120)<<endl;

    // primeFacots(36);
    // primeFacots(60);

    // cout << hcf(12, 18) << endl;
    // cout << hcf(20, 30) << endl;
    // cout << hcf(2, 3) << endl;

    // cout << subString("Hello, World. I am ADMIN.", 13, 20) << endl;

    return 0;
}

void set_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cin >> *(arr + i);
}

void get_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
}

void sort_array(int *arr, int size, bool asc)
{
    if (asc)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (*(arr + i) > *(arr + j))
                {
                    int temp = *(arr + i);
                    *(arr + i) = *(arr + j);
                    *(arr + j) = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (*(arr + i) < *(arr + j))
                {
                    int temp = *(arr + i);
                    *(arr + i) = *(arr + j);
                    *(arr + j) = temp;
                }
            }
        }
    }
}

int max(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int lcm(int a, int b, int c)
{
    for (int i = max(a, b, c); i <= (a * b * c); i++)
    {
        if (i % a == 0 && i % b == 0 && i % c == 0)
            return i;
    }
    return 1;
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

int nextPrime(int num)
{
    while (true)
    {
        num++;
        if (isPrime(num))
            return num;
    }
}

void primeFacots(int num)
{
    for (int i = 2; i <= num; i = nextPrime(i))
    {
        while (num % i == 0)
        {
            cout << i << " ";
            num /= i;
        }
    }
}

int hcf(int a, int b)
{
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

string subString(string str, int start_idx, int end_idx = -1)
{
    if (end_idx == -1 || end_idx > str.length())
        end_idx = str.length();

    string subStr;
    for (int i = start_idx; i < end_idx; i++)
        subStr += str[i];

    return subStr;
}

void swap_array(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

void merge_array(int *arr1, int *arr2, int size)
{
    sort_array(arr1, size);
    sort_array(arr2, size);

    int arr3[2 * size];
    int i, j, k;

    for (i = 0, j = 0, k = 0; j < size && k < size; i++)
    {
        if (arr1[j] > arr2[k])
        {
            arr3[i] = arr2[k];
            k++;
        }
        else
        {
            arr3[i] = arr1[j];
            j++;
        }
    }

    // Copy remaining elements of arr1 (if any)
    while (j < size)
    {
        arr3[i++] = arr1[j++];
    }

    // Copy remaining elements of arr2 (if any)
    while (k < size)
    {
        arr3[i++] = arr2[k++];
    }

    cout << "\n====================================" << endl;
    get_array(arr3, 2 * size);
}
