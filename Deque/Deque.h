#include <iostream>

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class Deque
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    Deque();
    Deque(const Deque &obj);
    Deque &operator=(const Deque &obj);

    bool isEmpty() const;

    void insert_at_front(int data);
    void insert_at_rear(int data);

    int get_length() const;
    int get_rear() const;
    int get_front() const;

    int delete_at_front();
    int delete_at_rear();

    void display();

    ~Deque();
};