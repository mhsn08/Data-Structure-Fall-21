#include<iostream>

using namespace std;

template < class T >
struct node
{
	T info;
	node<T> * next;
};

template < class T >
class list
{
	node<T> * head;
	node<T> * temp , * temp1;
public:
	list();
	~list();
	void insert(T,T);
	void insertall(T,T);
	void remove(T);
	void removeall(T);
	bool search(T);
	void print();
	bool isempty();
	void reverse();
};

int main()
{
	list<string> l1;
	string data,key;
    int des;
	bool search;
    bool isempty;
    while(1){
        cout << "Enter your desired operation:" << endl;
        cout << "0. To Exit" << endl;
        cout << "1. To insert something 1 time:" << endl;
        cout << "2. To insert something evertime:" << endl;
        cout << "3. To delete something 1 time:" << endl;
        cout << "4. To delete something everytime:" << endl;
        cout << "5. To search something:" << endl;
        cout << "6. To Print the whole List:" << endl;
        cout << "7. To check if list is empty:" << endl;
        cout << "8. To reverse list:" << endl << endl;
        cout << "Press : ";
        cin >> des;
        if(des == 0)
            return 0;
        
        if(des>0 && des<9){
            switch (des)
            {
            case 1:
				cout << "Enter Key : ";
				cin >> key;
				cout << "Enter Data: ";
				cin >> data;
                l1.insert(key,data);
                break;
            case 2:
				cout << "Enter Key : ";
				cin >> key;
				cout << "Enter Data: ";
				cin >> data;
                l1.insertall(key,data);
                break;
            case 3:
				cout << "Enter Val: ";
				cin >> key;
                l1.remove(key);
                break;
            case 4:
                cout << "Enter Val: ";
				cin >> key;
				l1.removeall(key);
                break;
            case 5:
				cout << "Enter Val: ";
				cin >> key;
                search = l1.search(key);
				if(search)
					cout << "Item found" << endl;
				else
					cout << "Item not Found" << endl;
                break;
            case 6:
                l1.print();
                break;
            case 7:
                isempty = l1.isempty();
                if(isempty){
                    cout << "List is empty" << endl;
                }
                else{
                    cout<<"List is not empty" << endl;
                }
                break;
            case 8:
                l1.reverse();
            }
        }
        else{
            cout << "Invalid number" << endl << endl;
        }
    }
	return 0;
}

template < class T>
list<T>::list()
{
	head = temp = temp1 = NULL;
}

template < class T >
list<T>::~list()
{
	if(head == NULL)
		return;
	temp = head->next;
	while(temp!= head)
	{
		temp1 = temp;
		temp = temp->next;
		delete temp1;
	}
	delete head;
	head = temp = temp1 = NULL;
}

template < class T >
void list<T>::insert(T key, T data)
{
	if(head == NULL)
	{
		head = new node<T>;
		head->info = data;
		head->next = head;
		return;
	}
	for(temp = head;;)
	{
		if(temp->info == key)
		{
			temp1 = new node<T>;
			temp1->info = data;
			temp1->next = temp->next;
			temp->next = temp1;
			temp = temp1->next;
			return;
		}
		temp = temp->next;
		if(temp == head)
			return;
	}
}

template < class T >
void list<T>::insertall(T key, T data)
{
	if(head == NULL)
	{
		head = new node<T>;
		head->info = data;
		head->next = head;
		return;
	}
	for(temp = head;;)
	{
		if(temp->info == key)
		{
			temp1 = new node<T>;
			temp1->info = data;
			temp1->next = temp->next;
			temp->next = temp1;
			temp = temp->next;
		}
		temp = temp->next;
		if(temp == head)
			return;
	}
}

template < class T >
void list<T>::remove(T val)
{
	if(head == NULL)
		return;
	if(head->info == val)
	{
		if(head->next == head)
		{
			delete head;
			head = temp = temp1 = NULL;
			return;
		}
		temp = head->next;
		while(temp->next != head)
			temp = temp->next;
		temp1 = head;
		head = head->next;
		temp->next = head;
		delete temp1;
		return;
	}
	temp = head;
	do
	{
		if(temp->next->info == val)
		{
			temp1 = temp->next;
			temp->next = temp->next->next;
			delete temp1;
			temp1 = NULL;
			return;
		}
		temp = temp->next;
	}while(temp->next != head);
}

template < class T >
void list<T>::removeall(T val)
{
	if(head == NULL)
		return;
	temp = head->next;
	while(temp->next != head)
		temp = temp->next;
	while(head->info == val)
	{
		if(head->next == head)
		{
			delete head;
			head = temp = temp1 = NULL;
			return;
		}
		temp1 = head;
		head = head->next;
		temp->next = head;
		delete temp1;
	}
	temp = head;
	do
	{
		if(temp->next->info == val)
		{
			temp1 = temp->next;
			temp->next = temp->next->next;
			delete temp1;
			temp1 = NULL;
			continue;
		}
		temp = temp->next;
	}while(temp->next != head);
}

template < class T >
bool list<T>::search(T val)
{
	if(head == NULL)
		return false;
	temp = head;
	do
	{
		if(temp->info == val)
			return true;
		temp = temp->next;
	}while(temp != head);
	return false;
}

template < class T >
void list<T>::print()
{
	if(head == NULL)
	{
		cout << "[ ]" << endl;
		return;
	}
	temp = head;
	cout << "[ ";
	do
	{
		cout << temp->info;
		if(temp->next != head)
			cout << " , ";
		temp = temp->next;
	}while(temp != head);
	cout << " ]" << endl;
}

template < class T >
bool list<T>::isempty()
{
	if(head == NULL)
		return true;
	return false;
}

template < class T >
void list<T>::reverse()
{
	temp1 = NULL;
	temp = head->next;
	while(temp->next != NULL)
	{
		head->next = temp1;
		temp1 = head;
		head = temp;
		temp = temp->next;
	}
	head->next = temp1;
	temp->next = head;
}

