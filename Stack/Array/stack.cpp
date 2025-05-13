#include <iostream>

using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *stack_arr_ptr;

public:
    Stack(int size);
    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    int peek();
    void display();
    Stack(Stack &obj);
    Stack &operator=(Stack &obj);
    ~Stack();
};

int main()
{
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << "POPED ELEMENT: " << s.pop() << endl;
    cout << "TOP ELEMENT: " << s.peek() << endl;
    s.display();

    return 0;
}

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    stack_arr_ptr = new int[size];
}

bool Stack::isEmpty()
{
    return this->top == -1;
}
bool Stack::isFull()
{
    return this->top == size - 1;
}

void Stack::push(int value)
{
    if (isFull())
    {
        cout << "push() operation failed! STACK OVERFLOW" << endl;
        return;
    }
    stack_arr_ptr[++top] = value;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "pop() operation failed! STACK UNDERFLOW" << endl;
        return -1;
    }
    int popped_value = stack_arr_ptr[top];
    top--;
    return popped_value;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "peek() operation failed! STACK UNDERFLOW" << endl;
        return -1;
    }
    return stack_arr_ptr[this->top];
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "STACK UNDERFLOW" << endl;
        return;
    }
    for (int i = top; i >= 0; i--)
        cout << stack_arr_ptr[i] << endl;
}

Stack::Stack(Stack &obj)
{
    this->size = obj.size;
    this->top = obj.top;
    this->stack_arr_ptr = new int[size];

    for (int i = 0; i <= obj.top; i++)
        this->stack_arr_ptr[i] = obj.stack_arr_ptr[i];
}

Stack &Stack::operator=(Stack &obj)
{
    if (this == &obj)
        return *this;

    if (this->stack_arr_ptr != nullptr)
        delete[] this->stack_arr_ptr;

    this->size = obj.size;
    this->top = obj.top;
    this->stack_arr_ptr = new int[size];

    for (int i = 0; i <= obj.top; i++)
        this->stack_arr_ptr[i] = obj.stack_arr_ptr[i];

    return *this;
}

Stack::~Stack()
{
    if (stack_arr_ptr)
        delete[] stack_arr_ptr;
}
