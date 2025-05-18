#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

Queue::Queue(const Queue &obj)
{
    this->front = this->rear = nullptr;
    this->count = 0;
    Node *current = obj.front;
    while (current)
    {
        push(current->data);
        current = current->next;
    }
}

Queue &Queue::operator=(const Queue &obj)
{
    if (this == &obj)
        return *this;

    // delete the nodes if already present in queue
    while (!is_empty())
        pop();

    count = 0;
    Node *current = obj.front;
    while (current)
    {
        push(current->data);
        current = current->next;
    }
    return *this;
}

bool Queue::is_empty() const
{
    return (front == nullptr && rear == nullptr);
}

void Queue::push(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if (is_empty())
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
    count++;
}
int Queue::pop()
{
    if (is_empty())
    {
        cout << "QUEUE UNDERFLOW! Queue is empty." << endl;
        return -1;
    }
    Node *temp = front;
    int poped_data = temp->data;
    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
    count--;
    return poped_data;
}

void Queue::display()
{
    Node *current = front;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
int Queue::get_length() { return count; }
int Queue::get_rear()
{
    if (is_empty())
    {
        cout << "QUEUE UNDERFLOW! Queue is empty." << endl;
        return -1;
    }
    return rear->data;
}
int Queue::get_front()
{
    if (is_empty())
    {
        cout << "QUEUE UNDERFLOW! Queue is empty." << endl;
        return -1;
    }
    return front->data;
}

Queue::~Queue()
{
    while (front)
        pop();
}