#include <iostream>
#include "PQue.h"

using namespace std;

PQue::PQue()
{
    front = nullptr;
    count = 0;
}

PQue::PQue(const PQue &obj)
{
    front = nullptr;
    count = 0;
    Node *temp = obj.front;
    while (temp)
    {
        enqueue(temp->data, temp->priority);
        temp = temp->next;
    }
}

PQue &PQue::operator=(const PQue &obj)
{
    if (this == &obj)
        return *this;
    while (!isEmpty())
        dequeue();

    front = nullptr;
    count = 0;
    Node *temp = obj.front;
    while (temp)
    {
        enqueue(temp->data, temp->priority);
        temp = temp->next;
    }
    return *this;
}

bool PQue::isEmpty() const { return front == nullptr; }
int PQue::get_length() const { return count; }
int PQue::peek() const
{
    if (isEmpty())
    {
        cout << "QUEUE UNDERFLOW" << endl;
        return -1;
    }
    return front->data;
}

void PQue::display() const
{
    if (isEmpty())
    {
        cout << "QUEUE UNDERFLOW" << endl;
        return;
    }
    Node *temp = front;
    while (temp)
    {
        cout << "PRIORITY: " << temp->priority << " - DATA: " << temp->data << endl;
        temp = temp->next;
    }
    cout << "\n=========================================" << endl;
}

void PQue::enqueue(int data, int priority)
{
    Node *new_node = new Node(data, priority);
    if (isEmpty())
        front = new_node;
    // New node has higher priority than current front
    else if (front->priority < new_node->priority)
    {
        new_node->next = front;
        front = new_node;
    }
    // more than one nodes were present
    else
    {
        Node *temp = front;
        while (temp->next != nullptr && temp->next->priority >= priority)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
    }
    count++;
}
int PQue::dequeue()
{
    if (isEmpty())
    {
        cout << "QUEUE UNDERFLOW" << endl;
        return -1;
    }
    int data = front->data;
    Node *temp = front;
    front = temp->next;
    delete temp;
    count--;
    return data;
}

PQue::~PQue()
{
    while (front)
        dequeue();
}
