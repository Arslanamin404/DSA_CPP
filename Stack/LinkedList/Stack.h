#ifndef STACK_H
#define STACK_H

struct Node
{
    int data;
    Node *next = nullptr;
};

class Stack
{
private:
    Node *top;

public:
    Stack();
    bool isEmpty();
    void push(int value);
    void reverse();
    int peek();
    int pop();
    void display();

    Stack(const Stack &obj);
    Stack &operator=(const Stack &obj);
    ~Stack();
};

#endif