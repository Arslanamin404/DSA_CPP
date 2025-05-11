#ifndef CLL_H
#define CLL_H

struct Node
{
    int data;
    Node *next = nullptr;
};

class CLL
{
private:
    Node *last;
    int count;

public:
    CLL();
    CLL(const CLL &obj);
    CLL &operator=(const CLL &obj);
    ~CLL();

    bool isEmpty() const;
    int length() const;
    Node *search(int data) const;

    void insert_at_start(int data);
    void insert_at_end(int data);
    void insert_after(int source, int data);

    void delete_at_start();
    void delete_at_end();
    void delete_node(int data);
    void clear();

    void display();
};

#endif