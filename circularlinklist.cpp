#include<iostream>

using namespace std;

struct node
{
    int info;
    node * next;
};

class list
{
    node * head;
    node * temp;
    node * temp1;
public:
    list();
    ~list();
    void insert1();
    void insertall();
    void deleteall();
    void deleteone();
    void reverse();
    void search();
    void print();
    bool isempty();
};

int main()
{
    list l1;
    int ch;
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
        cout << "8. To reverse the list" << endl << endl;
        cout << "Press : ";
        cin >> ch;
        if(ch == 0)
            return 0;
        if(ch>0 && ch<9){
            switch (ch)
            {
            case 1:
                l1.insert1();
                break;
            case 2:
                l1.insertall();
                break;
            case 3:
                l1.deleteone();
                break;
            case 4:
                l1.deleteall();
                break;
            case 5:
                l1.search();
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
                break;
            }
        }
        else{
            cout << "Invalid number" << endl << endl;
        }
    }
    return 0;
}

list::list()
{
    head = temp1 = temp = NULL;
}

list::~list()
{
    if(head == NULL)
        return;
    temp = temp1 = head->next;
    while (temp != head)
    {
        temp = temp->next;
        delete temp1;
        temp1 = temp;
    }
    delete head;
    head = temp = temp1 = NULL;
}

void list::insert1()
{
    int key, data;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the Data: ";
    cin >> data;
    if(head == NULL){
        head = new node;
        head->info = data;
        head->next = head;
        return;
    }
    temp = head;
    do
    {
        if(temp->info == key){
            temp1 = new node;
            temp1->info = data;
            temp1->next = temp->next;
            temp->next = temp1;
            return;
        }
        temp = temp->next;
    } while (temp->next != head);
}

void list::insertall()
{
    int key, data;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the Data: ";
    cin >> data;
    if(head == NULL){
        head = new node;
        head->info = data;
        head->next = head;
        return;
    }
    temp = head;
    do
    {
        if(temp->info == key){
            temp1 = new node;
            temp1->info = data;
            temp1->next = temp->next;
            temp->next = temp1;
            temp = temp1->next;
            continue;
        }
        temp = temp->next;
    } while (temp != head);
}

void list::deleteone()
{
    int data;
    cout << "Enter the Data: ";
    cin >> data;
    if(head == NULL)
        return;
    if(head->info == data){
        if(head->next == head){
            delete head;
            temp = head = temp1 = NULL;
            return;
        }
        temp1 = head;
        temp = head->next;
        while(temp->next != temp1)
            temp = temp->next;
        head = head->next;
        temp->next = head;
        delete temp1;
        temp1 = NULL;
        return;
    }
    temp = head;
    do
    {
        if(temp->next->info == data){
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            temp1 = NULL;
            return;
        }
        temp = temp->next;
    }while (temp != head);   
}

void list::deleteall()
{
    int data;
    cout << "Enter the Data: ";
    cin >> data;
    if(head == NULL)
        return;
    temp1 = temp = head;
    while(head->info == data){
        if(head->next == head){
            delete head;
            temp = head = temp1 = NULL;
            return;
        }
        while(temp->next != head)
            temp = temp->next;
        head = head->next;
        temp->next = head;
        delete temp1;
        temp1 = head;
    }
    temp1 = temp = head;
    do
    {
        if(temp->next->info == data){
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            temp1 = NULL;
            continue;
        }
        temp = temp->next;
        temp1 = temp;
    }while (temp != head || temp1 == NULL);
}

void list::search()
{
    int data;
    cout << "Enter the Data: ";
    cin >> data;
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    temp = head;
    do
    {
        if(temp->info == data){
            cout << "Found the item." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);   
}

void list::print()
{
    if(head == NULL){
        cout << "[ ]" << endl;
        return;
    }
    temp = head;
    cout << "[ ";
    do
    {
        cout << temp->info;
        temp = temp->next;
        if(temp != head)
            cout << " , ";
    } while (temp != head);
    cout << " ]" << endl;
}

bool list::isempty()
{
    if(head == NULL)
        return true;
    return false;
}

void list::reverse()
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
    temp->next = head;
}