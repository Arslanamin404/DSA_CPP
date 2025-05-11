#include <iostream>
#include "CLL.h"

using namespace std;

int main()
{
    CLL mycll;
    mycll.insert_at_start(900);
    mycll.insert_at_end(10);
    mycll.insert_at_end(20);
    mycll.insert_at_start(50);
    mycll.insert_at_end(90);
    mycll.insert_after(90, 100);
    mycll.insert_at_start(5);
    mycll.insert_at_end(150);
    mycll.display();
    cout << "\n=======================================" << endl;
    mycll.delete_at_start();
    mycll.delete_at_start();
    mycll.delete_node(20);
    mycll.delete_node(900);
    mycll.delete_node(10);
    mycll.delete_at_start();

    mycll.display();
    cout << "\n=======================================" << endl;
    cout << "COPY LIST" << endl;
    CLL newList;
    newList.insert_at_start(10);
    newList.insert_at_start(10);
    newList.insert_at_start(10);
    newList.insert_at_start(10);
    newList.insert_at_start(10);
    newList.display();
    cout << "\n=======================================" << endl;
    newList = mycll;
    newList.display();
    return 0;
}