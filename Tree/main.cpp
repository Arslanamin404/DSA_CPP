#include <iostream>
#include "BST.h" // Make sure you have your class definition here

using namespace std;

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorder(); // Expected: 20 30 40 50 60 70 80
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(); // Expected: 50 30 20 40 70 60 80
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(); // Expected: 20 40 30 60 80 70 50
    cout << endl;

    // Search
    int key = 60;
    tree.search(key) ? cout << key << " found in BST." << endl : cout << key << " not found in BST." << endl;

    // Delete
    tree.del(70); // Node with two children
    cout << "Inorder after deleting 70: ";
    tree.inorder(); // Should show updated tree
    cout << endl;

    tree.del(30); // Node with one child
    cout << "Inorder after deleting 30: ";
    tree.inorder();
    cout << endl;

    tree.del(20); // Leaf node
    cout << "Inorder after deleting 20: ";
    tree.inorder();
    cout << endl;

    return 0;
}
