#include <iostream>
#include "DynamicArray.h"

using namespace std;

void DynamicArray::double_array()
{

    int *temp = new int[size * 2];

    // Copy existing elements to the new array
    for (int i = 0; i <= last_index; i++)
        temp[i] = ptr[i];

    // Free the old memory and point it to new memory
    delete[] ptr;

    ptr = temp;

    // Update size to reflect the new size
    size *= 2;
}

void DynamicArray::half_array()
{

    int *temp = new int[size / 2];
    for (int i = 0; i <= last_index; i++)
        temp[i] = ptr[i];

    delete[] ptr;
    ptr = temp;
    size /= 2;
}

DynamicArray::DynamicArray()
{
    ptr = NULL;
    size = 0;
    last_index = -1;
}

void DynamicArray::create_array(int size)
{
    this->size = size;
    last_index = -1;

    if (ptr != NULL)
        delete[] ptr;
    ptr = new int[size];
}

void DynamicArray::insert(int index, int value)
{
    if (index < 0 || index > size - 1 || index > last_index + 1)
    {
        // index > last_index + 1, inorder to maintain continuity
        cout << "INVALID INDEX! Index out of bounds" << endl;
        return;
    }

    if (isFull())
        double_array();

    for (int i = last_index + 1; i > index; i--)
        ptr[i] = ptr[i - 1];

    ptr[index] = value;
    last_index++;
}

void DynamicArray::append(int value)
{
    if (isFull())
        double_array();

    last_index++;
    ptr[last_index] = value;
}

int DynamicArray::get_value(int index)
{
    if (this->isEmpty())
    {
        cout << "ARRAY IS Empty" << endl;
        return -1;
    }

    if (index < 0 || index > last_index)
    {
        cout << "INVALID INDEX! Index out of bounds" << endl;
        return -1;
    }

    return ptr[index];
}

bool DynamicArray::isEmpty()
{
    return last_index == -1;
}

bool DynamicArray::isFull()
{
    return last_index == size - 1;
}

void DynamicArray::del(int index)
{
    if (index < 0 || index > last_index)
    {
        cout << "INVALID INDEX! Index out of bounds" << endl;
        return;
    }

    for (int i = index; i < last_index; i++)
        ptr[i] = ptr[i + 1];
    last_index--;

    // compare number of elements with the half size
    if (size > 1 && (get_count() < size / 2))
        half_array();
}

void DynamicArray::edit(int index, int value)
{
    if (index < 0 || index > last_index)
    {
        cout << "INVALID INDEX! Index out of bounds" << endl;
        return;
    }

    ptr[index] = value;
}

int DynamicArray::get_count()
{
    return last_index + 1;
}

int DynamicArray::get_size()
{
    return size;
}

DynamicArray::~DynamicArray()
{
    delete[] ptr;
}

// Deep copy
DynamicArray::DynamicArray(const DynamicArray &arr)
{
    size = arr.size;
    last_index = arr.last_index;
    ptr = new int[size];
    for (int i = 0; i <= last_index; i++)
        ptr[i] = arr.ptr[i];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &arr)
{
    size = arr.size;
    last_index = arr.last_index;

    if (ptr != NULL)
        delete[] ptr;

    ptr = new int[size];

    for (int i = 0; i <= last_index; i++)
        ptr[i] = arr.ptr[i];

    return *(this);
}
