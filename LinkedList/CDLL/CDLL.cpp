#include <iostream>
#include "CDLL.h"

using namespace std;

CDLL::CDLL()
{
    this->last = nullptr;
    this->count = 0;
}

CDLL::CDLL(const CDLL &obj)
{
    this->last = nullptr;
    if (obj.last == nullptr)
        return;

    Node *current = obj.last->next;
    do
    {
        this->insert_at_last(current->data);
        current = current->next;
    } while (current != obj.last->next);
}

CDLL &CDLL::operator=(const CDLL &obj)
{
    if (this == &obj)
        return *this;

    this->clear();
    Node *current = obj.last->next;
    do
    {
        this->insert_at_last(current->data);
        current = current->next;
    } while (current != obj.last->next);
    return *this;
}

CDLL::~CDLL()
{
    while (last)
        delete_at_start();
}

int CDLL::length() const
{
    return this->count;
}
bool CDLL::isEmpty() const
{
    return this->last == nullptr;
}

Node *CDLL::search(int data) const
{
    if (isEmpty())
        return nullptr;

    Node *current = last->next;
    while (current != last)
    {
        if (current->data == data)
            return current;
        current = current->next;
    }
    if (current->data == data)
        return current;

    return nullptr;
}

void CDLL::insert_at_start(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if (isEmpty())
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        this->last = new_node;
    }
    else
    {
        new_node->next = last->next;
        new_node->prev = last;
        last->next->prev = new_node;
        last->next = new_node;
    }
    count++;
}
void CDLL::insert_at_last(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    if (isEmpty())
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        this->last = new_node;
    }
    else
    {
        new_node->prev = last;
        new_node->next = last->next;
        last->next->prev = new_node;
        last->next = new_node;
        last = new_node;
    }
    count++;
}
void CDLL::insert_after(int source_data, int data)
{
    Node *source_data_ptr = search(source_data);
    if (!source_data_ptr)
    {
        cout << "insert_after() failed! " << source_data << " not found in list!" << endl;
        return;
    }

    if (source_data_ptr == last)
    {
        insert_at_last(data);
        return;
    }
    else
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->prev = source_data_ptr;
        new_node->next = source_data_ptr->next;
        source_data_ptr->next->prev = new_node;
        source_data_ptr->next = new_node;
    }
    count++;
}

void CDLL::delete_at_start()
{
    if (isEmpty())
    {
        cout << "delete_at_start() failed. List is EMPTY!" << endl;
        return;
    }

    if (last->next == last)
    {
        delete last;
        last = nullptr;
    }
    else
    {
        Node *temp = last->next;
        last->next = temp->next;
        temp->next->prev = last;
        delete temp;
    }
    count--;
}
void CDLL::delete_at_last()
{
    if (isEmpty())
    {
        cout << "delete_at_last() failed. List is EMPTY!" << endl;
        return;
    }

    if (last->next == last)
    {
        delete last;
        last = nullptr;
    }
    else
    {
        Node *temp = last;
        last->next->prev = temp->prev;
        last->prev->next = temp->next;
        last = temp->prev;
        delete temp;
    }
    count--;
}
void CDLL::delete_node(int data)
{
    if (isEmpty())
    {
        cout << "delete_node() failed. List is EMPTY!" << endl;
        return;
    }

    Node *data_ptr = search(data);
    if (!data_ptr)
    {
        cout << "delete_node() failed! " << data << " not found in list!" << endl;
        return;
    }

    // if node to delete is first node
    if (data_ptr == last->next)
    {
        delete_at_start();
        return;
    }
    // if node to delete is last node
    else if (data_ptr == last)
    {
        delete_at_last();
        return;
    }
    else
    {
        data_ptr->prev->next = data_ptr->next;
        data_ptr->next->prev = data_ptr->prev;
        delete data_ptr;
    }
    count--;
}

void CDLL::clear()
{
    while (!isEmpty())
        delete_at_start();
}
void CDLL::display()
{
    if (isEmpty())
    {
        cout << "LIST IS EMPTY!" << endl;
        return;
    }
    Node *current = last->next;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != last->next);
}