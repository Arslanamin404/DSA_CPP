#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << "PEEK: " << s1.peek() << endl;
    cout << "===========================" << endl;
    s1.display();
    cout << "\n===========================" << endl;
    s1.pop();
    s1.display();
    cout << "\n===========================" << endl;
    Stack s2 = s1;
    s2.display();
    return 0;
}