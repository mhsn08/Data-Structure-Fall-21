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
	T pop();
	bool push(T);
	bool isfull();
	bool isempty();
	T top();
};

int main()
{
	stack<int> res(10), A(10) , B(10), C(10) , dest(10);
    res.push(5);
    res.push(7);
    res.push(1);
    res.push(2);
    res.push(4);
    res.push(9);
    res.push(10);
    res.push(3);
    res.push(6);
    res.push(8);
    int spop , apop , bpop , cpop , dpop;
    bool suc;
    while(!(res.isempty() && A.isempty() && B.isempty() && C.isempty()))
    {
        if(!res.isempty()){
                spop = res.pop();
            suc = dest.push(spop);
            dpop = dest.pop();
            if(!suc)
            {
                suc = A.push(dpop);
                if(!suc)
                {
                    suc = B.push(dpop);
                    if(!suc)
                    {
                        C.push(dpop);
                    }
                }
            }
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
T stack<T>::pop()
{
	if(isempty())
        return 0;
    T ret;
	temp = head;
	head = head->next;
    ret = temp->info;
	cout << temp->info << " Popped!" << endl;
	delete temp;
	temp = NULL;
	length--;
    return ret;
}

template < class T >
bool stack<T>::push(T data)
{
	if(isfull())
	{
		cout << "Stack Overflow!" << endl;
		return;
	}
    if(head->info > data)
        return false;
	temp = new node<T>;
	temp->info = data;
	temp->next = head;
	head = temp;
	length++;
    return true;
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
