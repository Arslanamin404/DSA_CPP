#ifndef DLL_H
#define DLL_H
struct Node
{
    Node *prev = nullptr;
    int data;
    Node *next = nullptr;
};

class DLL
{
private:
    Node *start;
    int count;

public:
    DLL();
    DLL(const DLL &obj);
    DLL &operator=(const DLL &obj);
    ~DLL();

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