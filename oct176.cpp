#include<iostream>

using namespace std;

template < class T >
struct node
{
	T info;
	node<T> * next;
};

template < class T >
class queue
{
	node<T> * head;
	node<T> * rear;
	node<T> * temp;
	int size;
	int length;
public:
	queue(int);
	~queue();
	void enqueue(T);
	void dequeue();
	bool isfull();
	bool isempty();
	T peek();
};

int main()
{
	return 0;
}

template < class T >
queue<T>::queue(int size)
{
	head = rear = NULL;
	this->size = size;
	length = 0;
}

template < class T >
queue<T>::~queue()
{
	while(head != NULL)
		dequeue();
}

template < class T >
void queue<T>::enqueue(T data)
{
	if(isfull())
	{
		cout << "Queue Overflow!" << endl;
		return;
	}
	if(rear == NULL)
	{
		rear = new node<T>;
		head = rear;
	}
	else
	{
		rear->next = new node<T>;
		rear = rear->next;
	}
	rear->info = data;
	rear->next = NULL;
	length++;
}

template < class T >
void queue<T>::dequeue()
{
	if(isempty())
	{
		cout << "Queue Underflow!" << endl;
		return;
	}
	cout << head->info << " Dequeued!" << endl;
	temp = head;
	head = head->next;
	delete temp;
	temp = NULL;
	if(head == NULL)
		rear = NULL;
	length--;
}

template < class T >
bool queue<T>::isfull()
{
	if(length == size)
		return true;
	return false;
}

template < class T >
bool queue<T>::isempty()
{
	if(length == 0)
		return true;
	return false;
}

template < class T >
T queue<T>::peek()
{
	if(isempty())
	{
		cout << "Nothing in Queue" << endl;
		return 0;
	}
	T ret = head->info;
	return ret;
}