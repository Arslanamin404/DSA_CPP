#include <iostream>
#include "Array.h"

using namespace std;

Array::Array()
{
    ptr = NULL;
    size = 0;
    last_index = -1;
}

void Array::create_array(int size)
{
    this->size = size;
    last_index = -1;

    if (ptr != NULL)
        delete[] ptr;
    ptr = new int[size];
}

void Array::insert(int index, int value)
{
    if (index < 0 || index > size - 1 || index > last_index + 1)
    {
        // index > last_index + 1, inorder to maintain continuity
        cout << "INVALID INDEX! Index out of bounds" << endl;
        return;
    }

    if (isFull())
    {
        cout << "ARRAY OVERFLOW! Insert not performed" << endl;
        return;
    }

    for (int i = last_index + 1; i >= index; i--)
        ptr[i] = ptr[i - 1];

    ptr[index] = value;
    last_index++;
}

void Array::append(int value)
{
    if (isFull())
    {
        cout << "ARRAY OVERFLOW! Append not performed" << endl;
        return;
    }
    last_index++;
    ptr[last_index] = value;
}

int Array::get_value(int index)
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

bool Array::isEmpty()
{
    return last_index == -1;
}

bool Array::isFull()
{
    return last_index == size - 1;
}

void Array::del(int index)
{
    if (index < 0 || index > last_index)
    {
        cout << "INVALID INDEX! Index out of bounds" << endl;
        return;
    }

    for (int i = index; i < last_index; i++)
        ptr[i] = ptr[i + 1];
    last_index--;
}

void Array::edit(int index, int value)
{
    if (index < 0 || index > last_index)
    {
        cout << "INVALID INDEX! Index out of bounds" << endl;
        return;
    }

    ptr[index] = value;
}

int Array::get_count()
{
    return last_index + 1;
}

int Array::get_size()
{
    return size;
}

Array::~Array()
{
    delete[] ptr;
}

// Deep copy
Array::Array(const Array &arr)
{
    size = arr.size;
    last_index = arr.last_index;
    ptr = new int[size];
    for (int i = 0; i <= last_index; i++)
        ptr[i] = arr.ptr[i];
}

Array &Array::operator=(const Array &arr)
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
