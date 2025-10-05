#ifndef SLL_H
#define SLL_H

struct Node
{
    int data;
    Node *next = nullptr;
};

class SLL
{
private:
    Node *start;
    Node *last;
    int count = 0;

public:
    SLL();
    SLL(const SLL &obj);
    SLL &operator=(const SLL &obj);
    ~SLL();

    bool isEmpty() const;
    int length() const;
    Node *search(int) const;

    void insert_at_start(int data);
    void insert_at_end(int data);
    void insert_after(int source, int data);

    void array_to_list(int *arr, int size);

    void delete_at_start();
    void delete_at_end();
    void delete_node(int data);

    void display();
};

#endif
