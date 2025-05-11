#include <iostream>
#include "DLL.h"

using namespace std;

DLL::DLL()
{
    this->start = nullptr;
    this->count = 0;
}

DLL::DLL(const DLL &obj)
{
    this->start = nullptr;
    Node *current = obj.start;
    while (current != nullptr)
    {
        this->insert_at_end(current->data);
        current = current->next;
    }
}

DLL &DLL::operator=(const DLL &obj)
{
    // Self-assignment check (list1 = list1)
    if (this == &obj)
        return *this;

    this->clear();
    Node *current = obj.start;
    while (current != nullptr)
    {
        this->insert_at_end(current->data);
        current = current->next;
    }

    return *this;
}

DLL::~DLL()
{
    while (this->start)
        this->delete_at_start();
}

bool DLL::isEmpty() const
{
    return this->start == nullptr;
}

int DLL::length() const
{
    return this->count;
}

Node *DLL::search(int data) const
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

void DLL::insert_at_start(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = this->start;

    if (!this->isEmpty())
        this->start->prev = new_node;

    this->start = new_node;
    this->count++;
}

void DLL::insert_at_end(int data)
{
    Node *new_node = new Node;
    new_node->data = data;

    if (this->isEmpty())
        this->start = new_node;
    else
    {
        Node *temp = this->start;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
    this->count++;
}

void DLL::insert_after(int source, int data)
{
    Node *source_ptr = this->search(source);
    if (!source_ptr)
    {
        cout << "insert_after() failed! " << source << " not found in list" << endl;
        return;
    }

    Node *new_node = new Node;
    new_node->prev = source_ptr;
    new_node->data = data;
    if (source_ptr->next)
    {
        new_node->next = source_ptr->next;
        source_ptr->next->prev = new_node;
    }
    source_ptr->next = new_node;
    this->count++;
}

void DLL::delete_at_start()
{
    if (this->isEmpty())
    {
        cout << "delete_at_start() failed! List is empty" << endl;
        return;
    }
    Node *temp = this->start;

    // if only one node was present
    if (this->start->next == nullptr)
        this->start = nullptr;
    else
    {
        this->start->next->prev = nullptr;
        this->start = temp->next;
    }
    delete temp;
    this->count--;
}

void DLL::delete_at_end()
{
    if (this->isEmpty())
    {
        cout << "delete_at_end() failed! List is empty" << endl;
        return;
    }
    Node *temp = this->start;

    // if only one node was present
    if (this->start->next == nullptr)
        this->start = nullptr;
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->prev->next = nullptr;
    }
    delete temp;
    this->count--;
}

void DLL::delete_node(int data)
{
    Node *data_ptr = this->search(data);
    if (!data_ptr)
    {
        cout << "delete_node() failed! " << data << " not found in list" << endl;
        return;
    }

    Node *temp = data_ptr;
    // if the deleted node was first node
    if (temp->prev == nullptr)
    {
        this->start = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = nullptr;
    }
    else
    {
        temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
    }
    delete temp;
    this->count--;
}

void DLL::clear()
{
    while (this->start != nullptr)
    {
        Node *temp = this->start;
        this->start = temp->next;
        delete temp;
    }
    this->start = nullptr;
}

void DLL::display()
{
    if (this->isEmpty())
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }

    Node *temp = this->start;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
