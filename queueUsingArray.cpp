#include<iostream>

using namespace std;

class queue
{
    int * data , * front , * rear;
    int size;
public:
    queue(int);
    ~queue();
    void enqueue(int);
    void dequeue();
    bool isFull();
    bool isEmpty();
    int peek();
};

int main()
{
    int op;
    int data;
    queue q(5);
    while (1)
    {
        cout << "Choose:" << endl << endl;
        cout << "0. To Exit" << endl;
        cout << "1. Enqueue Data" << endl;
        cout << "2. Dequeue Data" << endl;
        cout << "3. Peek" << endl;
        cout << "Choose: ";
        cin >> op;
        if(op == 0)
            break;
        if(op > 2 && op < 1)
        {
            cout << "Invalid Input!" << endl;
            continue;
        }
        if(op == 1)
        {
            cout << "Data: ";
            cin >> data;
            q.enqueue(data);
        }
        if(op == 2)
            q.dequeue();
        else
            cout << q.peek() << " is in Front" << endl;
    }
    return 0;
}

queue::queue(int size)
{
    data = new int[size];
    this->size = size;
    front = rear = NULL;
}

queue::~queue()
{
    delete [] data;
}

void queue::enqueue(int info)
{
    if(isFull())
    {
        cout << "Queue OverFlow!" << endl;
        return;
    }
    if(rear == NULL)
        rear = front = data;
    else if(rear == data + size - 1)
        rear = data;
    else
        rear++;
    *rear = info;
}

void queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue Underflow!" << endl;
        return;
    }
    cout << *front << " Dequeued!" << endl;
    if(front == rear)
        front = rear = NULL;
    else if(front == data + size - 1)
        front = data;
    else
        front++;
}

bool queue::isEmpty()
{
    if(front == NULL)
        return true;
    else
        return false;
}

bool queue::isFull()
{
    if((rear == data + size - 1 && front == data) || rear == front - 1)
        return true;
    else
        return false;
}

int queue::peek()
{
    if(front == NULL)
        return 0;
    else
        return *front;
}