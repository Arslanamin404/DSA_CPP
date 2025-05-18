#include <iostream>
struct Node
{
    int data;
    Node *next = nullptr;
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    Queue();
    Queue(const Queue &obj);
    Queue &operator=(const Queue &obj);
    bool is_empty() const;

    void push(int data);
    int pop();

    void display();
    int get_length();
    int get_front();
    int get_rear();
    ~Queue();
};
