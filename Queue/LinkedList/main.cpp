#include <iostream>
#include "Queue.h"

using namespace std;
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout << "POPPED DATA: " << q.pop() << endl;
    cout << "FRONT: " << q.get_front() << endl;
    cout << "REAR: " << q.get_rear() << endl;
    cout << "=========================" << endl;
    q.display();
    cout << "\n=========================" << endl;
    return 0;
}