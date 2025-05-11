#include <iostream>
#include "DLL.h"

using namespace std;
int main()
{
    DLL myDLL = DLL();
    myDLL.insert_at_start(10);
    myDLL.insert_at_start(20);
    myDLL.insert_at_start(30);
    myDLL.insert_at_start(40);
    myDLL.insert_at_start(50);
    myDLL.insert_at_end(60);
    myDLL.insert_at_end(70);
    myDLL.insert_at_end(80);
    myDLL.insert_after(80, 888);
    cout << "LENGTH: " << myDLL.length() << endl;
    myDLL.display();

    cout << "\n========================" << endl;

    myDLL.delete_at_start();
    myDLL.delete_at_start();
    myDLL.delete_at_end();
    myDLL.delete_node(10);
    myDLL.delete_node(80);

    cout << "LENGTH: " << myDLL.length() << endl;
    myDLL.display();

    cout << "\n========================" << endl;
    cout << "COPY LIST" << endl;
    DLL dll2;
    dll2.insert_at_start(9);
    dll2.insert_at_start(9);
    dll2.insert_at_start(9);
    dll2.insert_at_start(9);
    dll2.insert_at_start(9);
    dll2.insert_at_start(9);
    dll2.display();
    cout << "\n========================" << endl;
    dll2 = myDLL;
    dll2.display();

    return 0;
}