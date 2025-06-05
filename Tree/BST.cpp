#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = nullptr;
}

bool BST::is_empty() { return root == nullptr; }

Node *BST::recursive_search(Node *root, int data)
{
    if (root == nullptr || root->data == data)
        return root;
    if (root->data > data)
        return recursive_search(root->left, data);
    else
        return recursive_search(root->right, data);
}
void BST::recursive_preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        recursive_preorder(root->left);
        recursive_preorder(root->right);
    }
}
void BST::recursive_postorder(Node *root)
{
    if (root)
    {
        recursive_postorder(root->left);
        recursive_postorder(root->right);
        cout << root->data << " ";
    }
}
void BST::recursive_inorder(Node *root)
{
    if (root)
    {
        recursive_inorder(root->left);
        cout << root->data << " ";
        recursive_inorder(root->right);
    }
}

void BST::preorder() { recursive_preorder(root); }
void BST::postorder() { recursive_postorder(root); }
void BST::inorder() { recursive_inorder(root); }
Node *BST::search(int data) { return recursive_search(root, data); }

Node *BST::recursive_insert(Node *root, int data)
{
    if (root == nullptr)
        root = new Node(data);
    else
    {
        if (root->data > data)
            root->left = recursive_insert(root->left, data);
        else
            root->right = recursive_insert(root->right, data);
    }
    return root;
}

void BST::insert(int data) { root = recursive_insert(root, data); }

Node *BST::inorder_successor(Node *node)
{
    Node *current = node->right;
    while (current && current->left)
        current = current->left;
    return current;
}

void BST::del(int data)
{
    if (is_empty())
    {
        cout << "DELETION FAILED: TREE IS EMPTY" << endl;
        return;
    }

    Node *parent_current = nullptr;
    Node *current = root;
    while (current)
    {
        if (current->data == data)
            break;
        if (current->data > data)
        {
            parent_current = current;
            current = current->left;
        }
        else
        {
            parent_current = current;
            current = current->right;
        }
    }
    // if node is found current will hold address else it will contain nullptr
    if (current == nullptr)
    {
        cout << "DELETION FAILED: NODE NOT FOUND" << endl;
        return;
    }

    //  if the node to delete is root node
    if (current == root)
    {
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            root = nullptr;
        }
        else if (current->left && current->right)
        {
            Node *successor_node = inorder_successor(current);
            int successor_data = successor_node->data;
            del(successor_data);
            current->data = successor_data;
        }
        else
        {
            if (current->right)
                root = current->right;
            else
                root = current->left;
            delete current;
        }
    }
    else
    {
        // node to delete has no child (leaf node)
        if (current->left == nullptr && current->right == nullptr)
        {
            if (parent_current->left == current)
                parent_current->left = nullptr;
            else
                parent_current->right = nullptr;
            delete current;
        }
        // node to delete has 2 children
        else if (current->left && current->right)
        {
            Node *successor_node = inorder_successor(current);
            int successor_data = successor_node->data;
            del(successor_data);
            current->data = successor_data;
        }
        // Node to delete has 1 child
        else
        {
            if (parent_current->left == current)
            {
                if (current->right)
                    parent_current->left = current->right;
                else
                    parent_current->left = current->left;
            }
            else
            {
                if (current->right)
                    parent_current->right = current->right;
                else
                    parent_current->right = current->left;
            }
            delete current;
        }
    }
}

BST::~BST()
{
    while (root)
        del(root->data);
}
