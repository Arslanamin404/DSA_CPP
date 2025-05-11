#include <iostream>
#include "SLL.h"

using namespace std;

int main()
{
    SLL mySll = SLL();
    mySll.insert_at_start(10);
    mySll.insert_at_start(20);
    mySll.insert_at_start(30);
    mySll.insert_at_end(40);
    mySll.insert_at_end(50);
    mySll.insert_at_end(60);
    mySll.insert_after(10, 15);
    // mySll.insert_after(2, 12);

    mySll.display();
    cout << "\n===========================" << endl;
    mySll.delete_at_start();
    mySll.delete_at_end();
    mySll.delete_node(40);
    // mySll.delete_node(100);
    mySll.display();
    return 0;
}