#include <iostream>
#include "PQue.h"

using namespace std;
int main()
{
    PQue q;
    q.enqueue(10, 1);
    q.enqueue(20, 2);
    q.enqueue(30, 0);
    q.display();
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    return 0;
}