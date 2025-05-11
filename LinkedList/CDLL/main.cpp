#include <iostream>
#include "CDLL.h"

using namespace std;

int main()
{
    CDLL list;
    list.insert_at_start(10);
    list.insert_at_start(20);
    list.insert_at_last(30);
    list.insert_at_last(40);
    list.insert_after(40, 120);
    list.insert_at_last(100);

    cout << "BEFORE DELETION: " << endl;
    list.display();
    cout << "\nCOUNT: " << list.length() << endl;
    cout << "============================================" << endl;

    list.delete_at_start();
    // list.delete_at_start();
    list.delete_at_last();
    // list.delete_at_last();
    // list.delete_at_last();
    // list.delete_at_last();
    // list.delete_node(20);
    // list.delete_node(100);
    list.delete_node(40);
    cout << "AFTER DELETION: " << endl;
    list.display();
    cout << "\nCOUNT: " << list.length() << endl;
    cout << "============================================" << endl;

    // copy constructor
    CDLL new_list = list;
    new_list.insert_at_start(69);
    new_list.insert_at_last(169);
    new_list.display();
    cout << "\nCOUNT: " << list.length() << endl;
    cout << "============================================" << endl;
    return 0;
}