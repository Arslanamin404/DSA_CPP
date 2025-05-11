#include <iostream>
#include "Array.h"
#include "DynamicArray.h"

using namespace std;

void get_array(Array &arr);
void get_dynamic_array(DynamicArray &arr);

int main()
{
    // Array myArray;
    // myArray.create_array(5);
    // myArray.append(10);
    // myArray.append(20);
    // myArray.insert(1, 15);
    // myArray.edit(0, 100);

    // get_array(myArray);

    // myArray.del(1);

    // cout << "\n===========================" << endl;

    // get_array(myArray);

    // cout << "Count: " << myArray.get_count() << endl;

    // cout << "\n===========================" << endl;

    // // deep copy
    // Array arr2;
    // arr2 = myArray;

    // get_array(arr2);

    cout << "\n===========================" << endl;

    DynamicArray darr1;
    darr1.create_array(5);
    darr1.append(1);
    darr1.append(4);
    darr1.insert(1, 12);
    darr1.edit(0, 89);

    get_dynamic_array(darr1);
    cout << "SIZE: " << darr1.get_size() << endl;
    cout << "COUNT: " << darr1.get_count() << endl;

    darr1.del(1);

    cout << "\n===========================" << endl;

    get_dynamic_array(darr1);
    cout << "\nSIZE: " << darr1.get_size() << endl;
    cout << "COUNT: " << darr1.get_count() << endl;

    return 0;
}

void get_array(Array &arr)
{
    for (int i = 0; i < arr.get_count(); i++)
        cout << "Value at index " << i << ": " << arr.get_value(i) << endl;
}

void get_dynamic_array(DynamicArray &arr)
{
    for (int i = 0; i < arr.get_count(); i++)
        cout << "Value at index " << i << ": " << arr.get_value(i) << endl;
}
