#include <iostream>
struct Node
{
    Node *left;
    int data;
    Node *right;
    Node(int data) : left(nullptr), data(data), right(nullptr) {}
};

class BST
{
private:
    Node *root;
    Node *recursive_insert(Node *root, int data);
    void recursive_preorder(Node *root);
    void recursive_postorder(Node *root);
    void recursive_inorder(Node *root);
    Node *recursive_search(Node *root, int data);

public:
    BST();
    bool is_empty();
    Node *search(int data);
    void preorder();
    void postorder();
    void inorder();

    void insert(int data);
    Node *inorder_successor(Node *node);
    void del(int data);

    ~BST();
};