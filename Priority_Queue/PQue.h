#include <iostream>

struct Node
{
    int data;
    int priority;
    Node *next;
    Node(int data, int priority) : data(data), priority(priority), next(nullptr) {}
};

class PQue
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    PQue();
    PQue(const PQue &obj);
    PQue &operator=(const PQue &obj);

    bool isEmpty() const;

    void enqueue(int data, int priority);
    int dequeue();

    int get_length() const;
    int peek() const;

    void display() const;

    ~PQue();
};
