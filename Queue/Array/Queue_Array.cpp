#include <iostream>
using namespace std;

class Queue_Array
{
private:
    int size;
    int front;
    int rear;
    int *queue_arr_ptr;
    int count;

public:
    Queue_Array(int size);
    bool isEmpty() const;
    bool isFull();
    void enqueue(int value);
    int dequeue();
    int get_front();
    int get_rear();
    int get_length();
    void display();
    Queue_Array(const Queue_Array &obj);
    Queue_Array &operator=(const Queue_Array &obj);
    ~Queue_Array();
};

int main()
{
    Queue_Array queue(5);
    queue.enqueue(10);
    queue.enqueue(2);
    queue.enqueue(30);
    queue.enqueue(60);
    queue.enqueue(90);
    cout << "FRONT: " << queue.get_front() << endl;
    cout << "REAR: " << queue.get_rear() << endl;
    cout << "Length: " << queue.get_length() << endl;
    cout << "========================================" << endl;
    queue.display();
    cout << "\n========================================" << endl;
    queue.dequeue();
    queue.enqueue(200);
    queue.dequeue();
    queue.dequeue();
    cout << "FRONT: " << queue.get_front() << endl;
    cout << "REAR: " << queue.get_rear() << endl;
    cout << "Length: " << queue.get_length() << endl;
    cout << "========================================" << endl;
    queue.display();
    cout << "\n========================================" << endl;

    return 0;
}

Queue_Array::Queue_Array(int size)
{
    this->size = size;
    this->count = 0;
    this->front = -1;
    this->rear = -1;
    this->queue_arr_ptr = new int[size];
}

bool Queue_Array::isEmpty() const
{
    return (front == -1 && rear == -1);
}
bool Queue_Array::isFull()
{
    return ((rear + 1) % size == front);
}

void Queue_Array::enqueue(int value)
{
    if (isFull())
    {
        cout << "QUEUE OVERFLOW!" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % size;

    queue_arr_ptr[rear] = value;
    count++;
}
int Queue_Array::dequeue()
{
    if (isEmpty())
    {
        cout << "QUEUE UNDERFLOW!" << endl;
        return -1;
    }

    int poped_data = queue_arr_ptr[front];

    // if the item to delete was the only item present in queue
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;

    count--;
    return poped_data;
}

int Queue_Array::get_front()
{
    if (isEmpty())
    {
        cout << "QUEUE is empty" << endl;
        return -1;
    }

    return queue_arr_ptr[front];
}
int Queue_Array::get_rear()
{
    if (isEmpty())
    {
        cout << "QUEUE is empty" << endl;
        return -1;
    }
    return queue_arr_ptr[rear];
}

int Queue_Array::get_length() { return count; }

void Queue_Array::display()
{
    if (isEmpty())
    {
        cout << "QUEUE UNDERFLOW" << endl;
        return;
    }

    int i = front;
    while (true)
    {
        cout << queue_arr_ptr[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
}

Queue_Array::Queue_Array(const Queue_Array &obj)
{
    size = obj.size;
    rear = obj.rear;
    count = obj.count;
    front = obj.front;
    queue_arr_ptr = new int[size];

    if (!obj.isEmpty())
    {
        int i = front;
        while (true)
        {
            queue_arr_ptr[i] = obj.queue_arr_ptr[i];
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
    }
}
Queue_Array &Queue_Array::operator=(const Queue_Array &obj)
{
    if (this == &obj)
        return *this;

    delete[] queue_arr_ptr;

    size = obj.size;
    rear = obj.rear;
    count = obj.count;
    front = obj.front;
    queue_arr_ptr = new int[size];

    if (!obj.isEmpty())
    {
        int i = front;
        while (true)
        {
            queue_arr_ptr[i] = obj.queue_arr_ptr[i];
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
    }
    return *(this);
}
Queue_Array::~Queue_Array()
{
    delete[] queue_arr_ptr;
}
