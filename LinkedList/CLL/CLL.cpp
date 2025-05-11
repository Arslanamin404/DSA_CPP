#include <iostream>
#include "CLL.h"

using namespace std;

CLL::CLL()
{
    this->last = nullptr;
    this->count = 0;
}

CLL::CLL(const CLL &obj)
{
    this->last = nullptr;
    if (obj.last == nullptr)
        return;

    Node *current = obj.last->next;
    while (current != obj.last)
    {
        this->insert_at_end(current->data);
        current = current->next;
    }
    this->insert_at_end(current->data);
}

CLL &CLL::operator=(const CLL &obj)
{
    if (this == &obj)
        return *this;

    this->clear();

    Node *current = obj.last->next;
    while (current != obj.last)
    {
        this->insert_at_end(current->data);
        current = current->next;
    }
    this->insert_at_end(current->data);

    return *this;
}

CLL::~CLL()
{
    while (this->last)
    {
        this->delete_at_start();
    }
}

bool CLL::isEmpty() const
{
    return this->last == nullptr;
}

int CLL::length() const
{
    return this->count;
}

Node *CLL::search(int data) const
{
    Node *temp = this->last->next;
    while (temp != this->last)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }

    if (temp->data == data)
        return temp;

    return nullptr;
}

void CLL::insert_at_start(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if (this->isEmpty())
    {
        new_node->next = new_node;
        this->last = new_node;
    }
    else
    {
        new_node->next = this->last->next;
        this->last->next = new_node;
    }
    this->count++;
}

void CLL::insert_at_end(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if (this->isEmpty())
    {
        new_node->next = new_node;
    }
    else
    {
        new_node->next = this->last->next;
        this->last->next = new_node;
    }
    this->last = new_node;
    this->count++;
}

void CLL::insert_after(int source, int data)
{
    Node *source_ptr = this->search(source);
    Node *temp = this->last->next;
    if (!source_ptr)
    {
        cout << source << " not found in CLL" << endl;
        return;
    }

    // only one node is present
    if (source_ptr->next == source_ptr)
        this->insert_at_end(data);
    // if the source_node is last node
    else if (source_ptr->next == temp)
        this->insert_at_end(data);
    // if the source_node is in the middle of list
    else
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = source_ptr->next;
        source_ptr->next = new_node;
    }

    this->count++;
}

void CLL::delete_at_start()
{
    if (this->isEmpty())
    {
        cout << "delete_at_start() failed. Circular Linked List is EMPTY!" << endl;
        return;
    }
    if (this->last->next == this->last)
    {
        delete this->last;
        this->last = nullptr;
    }
    else
    {
        Node *temp = this->last->next;
        this->last->next = temp->next;
        delete temp;
    }
    this->count--;
}

void CLL::delete_at_end()
{
    if (this->isEmpty())
    {
        cout << "delete_at_end() failed. Circular Linked List is EMPTY!" << endl;
        return;
    }
    if (this->last->next == this->last)
    {
        delete this->last;
        this->last = nullptr;
    }
    else
    {
        Node *temp = this->last->next;
        while (temp->next != this->last)
            temp = temp->next;

        Node *node_to_delete = this->last;
        temp->next = temp->next->next;
        this->last = temp;
        delete node_to_delete;
    }

    this->count--;
}

void CLL::delete_node(int data)
{
    Node *delete_data_ptr = this->search(data);
    if (!delete_data_ptr)
    {
        cout << "delete_node() failed." << data << " not found in LIST!" << endl;
        return;
    }
    if (delete_data_ptr == this->last)
    {
        this->delete_at_end();
        return;
    }
    Node *temp = this->last->next;
    while (temp->next != delete_data_ptr)
        temp = temp->next;

    temp->next = delete_data_ptr->next;
    delete delete_data_ptr;

    this->count--;
}

void CLL::clear()
{
    if (this->isEmpty())
        return;

    Node *current = this->last->next;
    while (current != this->last)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete this->last;
    this->last = nullptr;
}

void CLL::display()
{
    if (isEmpty())
    {
        cout << "Circular Linked List is EMPTY!" << endl;
        return;
    }

    Node *temp = this->last->next;

    while (temp != this->last)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}