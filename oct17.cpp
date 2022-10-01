#include<iostream>

using namespace std;

template < class T >
class list
{
	T * data;
	int length;
	int size;
	T * current , * temp;
public:
	list(int);
	~list();
	T get(int);
	void update(int,T);
	int getlength();
	void back();
	void next();
	void start();
	void end();
	void remove(int);
	void add(int,T);
	void print();
};

int main()
{
	list<int> l1(10);
	int data,ind,len;
    int des;
    while(1){
        cout << "Enter your desired operation:" << endl;
        cout << "0. To Exit" << endl;
        cout << "1. To update list:" << endl;
        cout << "2. To get the length of list:" << endl;
        cout << "3. Push Back:" << endl;
        cout << "4. Push forward:" << endl;
        cout << "5. Go to start:" << endl;
        cout << "6. Go to end:" << endl;
        cout << "7. Remove something:" << endl;
		cout << "8. Add something:" << endl;
        cout << "9. Reverse List" << endl;
		cout << "10. Print List" << endl << endl;
        cout << "Press : ";
        cin >> des;
        if(des == 0)
            return 0;
        if(des>0 && des<11){
            switch (des)
            {
            case 1:
				cout << "Enter index: ";
				cin >> ind;
				cout << "Enter Data: ";
				cin >> data;
                l1.update(ind,data);
                break;
            case 2:
                cout << "Length of list is " << l1.getlength();
                break;
            case 3:
                l1.back();
                break;
            case 4:
                l1.next();
                break;
            case 5:
                l1.start();
                break;
            case 6:
                l1.end();
                break;
            case 7:
				cout << "Enter index: ";
				cin >> ind;
                l1.remove(ind);
                break;
            case 8:
				cout << "Enter index: ";
				cin >> ind;
				cout << "Enter Data: ";
				cin >> data;
                l1.add(ind,data);
                break;
			case 10:
				l1.print();
            }
        }
        else{
            cout << "Invalid number" << endl << endl;
        }
    }
	return 0;
}

template < class T >
list<T>::list(int size)
{
	this->size = size;
	data = new T [size];
	length = 0;
	current = temp = data;
}


template < class T >
list<T>::~list()
{
	delete [] data;
}

template < class T >
T list<T>::get(int ind)
{
	current = data;
	for(int i = 0 ; i < ind - 1 ; i++)
		current++;
	return *(current);
}

template < class T >
void list<T>::update(int ind , T val)
{
	if(ind > length)
	{
		cout << "Index out of range" << endl;
		return;
	}
	for(int i = 0 ; i < ind - 1 ; i++)
		current++;
	*(current) = val;
}

template < class T >
int list<T>::getlength()
{
	return length;
}

template < class T >
void list<T>::back()
{
	if(current == data)
	{
		cout << "Can't push further back" << endl;
		return;
	}
	current--;
}

template < class T >
void list<T>::next()
{
	if(current == &data[length - 1])
	{
		cout << "Can't move further" << endl;
		return;
	}
	current++;
}

template < class T >
void list<T>::start()
{
	current = data;
}

template < class T >
void list<T>::end()
{
	current = &data[length - 1];
}

template < class T >
void list<T>::remove(int ind)
{
	if(ind > length)
	{
		cout << "Index out of range" << endl;
		return;
	}
	current = &data[ind - 1];
	temp = &data[ind];
	while(current != &data[length - 1])
	{
		*(current) = *(temp);
		current++;
		temp++;
	}
	*(current) = *(temp);
	length--;
}

template < class T >
void list<T>::add(int ind, T val)
{
	if(length == size)
	{
		cout << "No more spaces to insert data" << endl;
		return;
	}
	if(ind > size)
	{
		cout << "Index out of range" << endl;
		return;
	}
	if(ind > length)
	{
		current = &data[length];
		*(current) = val;
		length++;
		return;
	}
	temp = &data[length];
	current = &data[length - 1];
	while(current != &data[ind - 1])
	{
		*(temp) = *(current);
		temp--;
		current--;
	}
	*(temp) = *(current);
	*(current) = val;
	length++;
}

template < class T >
void list<T>::print()
{
	cout << "[ ";
	current = data;
	for(int i = 0; i < length ; i++)
	{
		cout << *(current + i);
		if(length > i + 1)
			cout << " , ";
	}
	cout << " ]" << endl;
}