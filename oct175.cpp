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
