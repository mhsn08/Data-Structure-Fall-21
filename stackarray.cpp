#include<iostream>

using namespace std;

template < class T >
class stack
{
	T * rear;
	T * head;
	int size;
	int length;
public:
	stack(int);
	~stack();
	stack<T>(stack<T> &l);
	void pop();
	void push(T);
	bool isfull();
	bool isempty();
	T top();
};

int main()
{
	stack<int> s(10);
	int des , data , ret;
	bool isempty , isfull;
	while (1)
	{
		cout << "Enter your desired operation:" << endl;
        cout << "0. To Exit" << endl;
        cout << "1. To Push" << endl;
        cout << "2. To Pop" << endl;
        cout << "3. To Check if Stack is full" << endl;
        cout << "4. To Check if Stack is empty" << endl;
        cout << "5. To get top value of Stack" << endl << endl;
		cout << "Press : ";
        cin >> des;
        if(des == 0)
            return 0;
		if(des>0 && des<6){
            switch (des)
            {
            case 1:
				cout << "Enter Data: ";
				cin >> data;
                s.push(data);
                break;
            case 2:
				s.pop();
                break;
            case 3:
				if(s.isfull())
					cout << "Stack if Full" << endl;
				else
					cout << "Stack is not Full" << endl;
                break;
            case 4:
                if(s.isempty())
					cout << "Stack if Empty" << endl;
				else
					cout << "Stack is not Empty" << endl;
                break;
            case 5:
				if(!s.isempty()){
					ret = s.top();
					cout << "Top of the Stack is : " << ret << endl;
				}
				s.top();
				break;
            }
        }
        else{
            cout << "Invalid number" << endl << endl;
        }
	}
	return 0;
}

template < class T >
stack<T>::stack(int size)
{
	this->size = size;
	length = 0;
	rear = new T[size];
	head = NULL;
}

template < class T >
stack<T>::~stack()
{
	delete [] rear;
}

template < class T >
void stack<T>::pop()
{
	if(isempty())
	{
		cout << "Stack Underflow" << endl;
		return;
	}
	cout << *head << " Popped!" << endl;
	head--;
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
	rear[length] = data;
	head = &rear[length];
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
		cout << "Empty Stack!" << endl;
		return 0;
	}
	T ret;
	ret = *head;
	return ret;
}

template < class T >
stack<T>::stack(stack<T> &l)
{
	
}


