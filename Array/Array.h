#ifndef ARRAY_H
#define ARRAY_H

class Array
{
private:
    int size;
    int last_index;
    int *ptr;

public:
    Array();
    Array(const Array &arr);
    Array &operator=(const Array &arr);
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
    ~Array();
};

#endif