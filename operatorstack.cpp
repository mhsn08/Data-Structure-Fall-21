#include<iostream>

using namespace std;

template < class T >
struct node
{
	T info;
	node<T> * next;
};

template < class T >
class stack
{
	node<T> * head;
	node<T> * temp;
	int size;
	int length;
public:
	stack(int);
	~stack();
	void pop();
	void push(T);
	bool isfull();
	bool isempty();
	T top();
};

int main()
{
	
	return 0;
}

template < class T >
stack<T>::stack(int size)
{
	head = temp = NULL;
	this->size = size;
	length = 0;
}

template < class T >
stack<T>::~stack()
{
	while(head != NULL)
		pop();
}

template < class T >
void stack<T>::pop()
{
	if(isempty())
	{
		cout << "Stack Underflow!" << endl;
		return;
	}
	temp = head;
	head = head->next;
	cout << temp->info << " Popped!" << endl;
	delete temp;
	temp = NULL;
	length--;
}

template < class T >
void stack<T>::push(T data)
{
	if(isfull())
	{
		cout << "Stack Overflow!" << endl;
		return;
	}
	temp = new node<T>;
	temp->info = data;
	temp->next = head;
	head = temp;
	length++;
}

template < class T >
bool stack<T>::isfull()
{
	if(length == size)
		return true;
	return false;
}

template < class T >
bool stack<T>::isempty()
{
	if(length == 0)
		return true;
	return false;
}

template < class T >
T stack<T>::top()
{
	if(isempty())
	{
		cout << "Stack is empty" << endl;
		return 0;
	}
	T ret;
	ret = head->info;
	return ret;	
}
