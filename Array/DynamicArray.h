#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{
private:
    int size;
    int last_index;
    int *ptr;

protected:
    void double_array();
    void half_array();

public:
    DynamicArray();
    DynamicArray(const DynamicArray &arr);
    DynamicArray &operator=(const DynamicArray &arr);
    void create_array(int size);
    void insert(int index, int value);
    void append(int value);
    int get_value(int index);
    bool isEmpty();
    bool isFull();
    void del(int index);
    void edit(int index, int value);
    int get_count();
    int get_size();
    ~DynamicArray();
};

#endif