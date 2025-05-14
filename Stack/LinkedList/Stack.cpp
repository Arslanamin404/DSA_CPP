#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    this->top = nullptr;
}

bool Stack::isEmpty()
{
    return this->top == nullptr;
}

void Stack::push(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = this->top;
    this->top = newNode;
}

void Stack::reverse()
{
    Node *prev = nullptr;
    Node *current = top;
    Node *next = nullptr;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top = prev;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "STACK UNDERFLOW" << endl;
        exit(-1);
    }
    return this->top->data;
}

int Stack::pop()
{

    if (isEmpty())
    {
        cout << "pop() failed. STACK UNDERFLOW!" << endl;
        exit(-1);
    }
    int poped_value = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;

    return poped_value;
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "STACK UNDERFLOW" << endl;
        return;
    }

    Node *current = top;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

Stack::Stack(const Stack &obj)
{
    this->top = nullptr;
    Node *current = obj.top;
    while (current)
    {
        push(current->data);
        current = current->next;
    }
    reverse();
}

Stack &Stack::operator=(const Stack &obj)
{

    if (this == &obj)
        return *this;

    if (top)
    {
        while (top)
            pop();
    }
    this->top = nullptr;
    Node *current = obj.top;
    while (current)
    {
        push(current->data);
        current = current->next;
    }
    reverse();

    return *this;
}

Stack::~Stack()
{
    while (top)
        pop();
}
