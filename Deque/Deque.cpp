#include <iostream>
#include "Deque.h"

using namespace std;

Deque::Deque()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

Deque::Deque(const Deque &obj)
{
    this->front = nullptr;
    this->rear = nullptr;
    this->count = 0;

    Node *current = obj.front;

    while (current)
    {
        insert_at_rear(current->data);
        current = current->next;
    }
}

Deque &Deque::operator=(const Deque &obj)
{
    if (this == &obj)
        return *this;

    while (!isEmpty())
        this->delete_at_front();

    this->front = nullptr;
    this->rear = nullptr;
    this->count = 0;

    Node *current = obj.front;

    while (current)
    {
        insert_at_rear(current->data);
        current = current->next;
    }
    return *this;
}

bool Deque::isEmpty() const
{
    return (front == nullptr && rear == nullptr);
}

void Deque::insert_at_front(int data)
{
    Node *newNode = new Node(data);
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    count++;
}
void Deque::insert_at_rear(int data)
{
    Node *new_node = new Node(data);
    if (isEmpty())
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        new_node->prev = rear;
        rear = new_node;
    }
    count++;
}

int Deque::get_length() const
{
    return count;
}

int Deque::get_rear() const
{
    if (isEmpty())
    {
        cout << "QUEUE IS EMPTY" << endl;
        return -1;
    }
    return rear->data;
}
int Deque::get_front() const
{
    if (isEmpty())
    {
        cout << "QUEUE IS EMPTY" << endl;
        return -1;
    }
    return front->data;
}

int Deque::delete_at_front()
{
    if (isEmpty())
    {
        cout << "QUEUE IS EMPTY" << endl;
        return -1;
    }
    int popped_data = front->data;

    Node *temp = front;
    // only 1 node present in list
    if (front == rear)
    {
        delete front;
        front = rear = nullptr;
    }
    // more than 1 nodes in list
    else
    {
        front = temp->next;
        front->prev = nullptr;
        delete temp;
    }
    count--;
    return popped_data;
}
int Deque::delete_at_rear()
{
    if (isEmpty())
    {
        cout << "QUEUE IS EMPTY" << endl;
        return -1;
    }
    int popped_data = rear->data;

    // only 1 node present in list
    if (front == rear)
    {
        delete front;
        rear = front = nullptr;
    }
    else
    {
        Node *temp = rear;
        rear = temp->prev;
        rear->next = nullptr;

        delete temp;
    }
    count--;
    return popped_data;
}

void Deque::display()
{
    if (isEmpty())
    {
        cout << "QUEUE IS EMPTY" << endl;
        return;
    }
    Node *current = front;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Deque::~Deque()
{
    while (!isEmpty())
        delete_at_front();
}