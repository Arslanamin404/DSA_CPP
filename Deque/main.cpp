#include <iostream>
#include "Deque.h"

using namespace std;

int main()
{
    Deque dq;
    dq.insert_at_front(10);
    dq.insert_at_front(20);
    dq.insert_at_front(30);
    dq.insert_at_rear(40);
    dq.insert_at_rear(50);
    dq.insert_at_rear(60);

    dq.delete_at_rear();
    dq.display();

    return 0;
}