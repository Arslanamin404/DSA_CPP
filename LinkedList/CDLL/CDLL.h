#ifndef CDLL_H
#define CDLL_H

#include <iostream>

struct Node
{
    Node *prev = nullptr;
    int data;
    Node *next = nullptr;
};

class CDLL
{
private:
    Node *last;
    int count;

public:
    CDLL();
    CDLL(const CDLL &obj);            // copy constructor
    CDLL &operator=(const CDLL &obj); // copy assignment operator overloading
    ~CDLL();

    int length() const;
    bool isEmpty() const;
    Node *search(int data) const;

    void insert_at_start(int data);
    void insert_at_last(int data);
    void insert_after(int source_data, int data);

    void delete_at_start();
    void delete_at_last();
    void delete_node(int data);

    void clear();
    void display();
};
#endif