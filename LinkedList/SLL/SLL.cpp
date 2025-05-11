#include <iostream>
#include "SLL.h"

using namespace std;

SLL::SLL()
{
    this->start = nullptr;
}

// copy constructor
SLL::SLL(const SLL &obj)
{
    Node *temp = obj.start;
    this->start = nullptr; // to avoid garbage values

    while (temp)
    {
        this->insert_at_end(temp->data);
        temp = temp->next;
    }
}

SLL &SLL::operator=(const SLL &obj)
{
    Node *temp = obj.start;
    while (this->start)
        this->delete_at_start();

    while (temp)
    {
        this->insert_at_end(temp->data);
        temp = temp->next;
    }
    return *this;
}

SLL::~SLL()
{
    while (this->start)
        this->delete_at_start();
}

bool SLL::isEmpty() const
{
    return this->start == nullptr;
}

int SLL::length() const
{
    return this->count;
}

Node *SLL::search(int data) const
{
    Node *temp = this->start;
    while (temp)
    {
        if (temp->data == data)
            return temp;

        temp = temp->next;
    }
    return nullptr;
}

void SLL::insert_at_start(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    // if list is empty, new_node->next will point to nullptr
    new_node->next = this->start;
    this->start = new_node;
    this->count++;
}

void SLL::insert_at_end(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if (isEmpty())
        this->start = new_node;
    else
    {
        Node *temp = this->start;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new_node;
    }
    this->count++;
}

void SLL::insert_after(int source_data, int data)
{
    Node *source_ptr = this->search(source_data);
    if (!source_ptr)
    {
        cout << "insert_after() Failed! " << source_data << " not found in list" << endl;
        return;
    }
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = source_ptr->next;
    source_ptr->next = new_node;

    this->count++;
}

void SLL::delete_at_start()
{
    if (this->isEmpty())
    {
        cout << "delete_at_start() Failed! List is already empty." << endl;
        return;
    }
    // to prevent memory leak
    Node *temp = this->start;
    this->start = temp->next;
    delete temp;
    this->count--;
}

void SLL::delete_at_end()
{
    if (this->isEmpty())
    {
        cout << "delete_at_start() Failed! List is already empty." << endl;
        return;
    }

    // only 1 node is present
    if (this->start->next == nullptr)
    {
        delete this->start;
        this->start = nullptr;
    }
    else
    {
        Node *temp = this->start;

        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }
    this->count--;
}

void SLL::delete_node(int data)
{
    Node *data_ptr = this->search(data);

    if (isEmpty())
    {
        cout << "Delete_node() Failed!  List is empty" << endl;
        return;
    }

    if (!data_ptr)
    {
        cout << "Delete_node() Failed! " << data << " not found in list" << endl;
        return;
    }

    // if only one node is present
    if (this->start == data_ptr)
    {
        this->delete_at_start();
    }
    else
    {
        Node *temp = this->start;
        while (temp->next != data_ptr)
            temp = temp->next;
        temp->next = data_ptr->next;
        delete data_ptr;
    }

    this->count--;
}

void SLL::display()
{
    Node *temp = this->start;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
