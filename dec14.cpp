#include<iostream>

using namespace std;

struct node
{
    int info;
    node * next;
    node * prev;
};

class list
{
private:
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
    void reversing(node *);
    void search(int);
    int searching(int , node * , bool , int);
    void print();
    bool isempty();
};

int main()
{
    list l1;
    int ch;
    int ser;
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
                cout << "Enter key";
                cin >> ser;
                l1.search(ser);
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

list::list()
{
    head = temp = temp1 = NULL;
}

list::~list()
{
    if(head == NULL)
        return;
    temp = head->next;
    while(temp != head)
    {
        temp1 = temp;
        temp = temp->next;
        delete temp1;
    }
    delete head;
    head = temp1 = temp = NULL;
}

void list::insert1()
{
    int data,key;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the Data: ";
    cin >> data;
    if(head == NULL){
        head = new node;
        head->info = data;
        head->next = head->prev = head;
        return;
    }
    temp = head;
    do
    {
        if(temp->info == key){
            temp1 = new node;
            temp1->info = data;
            temp1->prev = temp;
            temp1->next = temp->next;
            temp->next = temp1;
            temp1->next->prev = temp1;
            if(temp1->next == head)
                head->prev = temp1;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void list::insertall()
{
    int data,key;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the Data: ";
    cin >> data;
    if(head == NULL){
        head = new node;
        head->info = data;
        head->next = head->prev = head;
        return;
    }
    temp = head;
    do
    {
        if(temp->info == key){
            temp1 = new node;
            temp1->info = data;
            temp1->next = temp->next;
            temp1->prev = temp;
            temp->next = temp1;
            temp = temp1->next;
            temp->prev = temp1;
            if(temp1->next == head){
                head->prev = temp1;
                return;
            }
            continue;
        }
        temp = temp->next;
    } while (temp != head);
}

void list::deleteone()
{
    int data;
    cout << "Enter what you want to delete: ";
    cin >> data;
    if(head == NULL)
        return;
    if(head->info == data){
        if(head->next == head){
            delete head;
            head = temp = temp1 = NULL;
            return;
        }
        temp = temp1 = head;
        while(temp->next != head)
            temp = temp->next;
        head = head->next;
        temp->next = head;
        head->prev = temp;
        delete temp1;
        temp1 = NULL;
        return;
    }
    temp = head->next;
    do
    {
        if(temp->info == data){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            temp = NULL;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void list::deleteall()
{
    int data;
    cout << "Enter what you want to delete: ";
    cin >> data;
    if(head == NULL)
        return;
    temp = head->next;
    while(temp->next != head)
        temp = temp->next;
    while(head->info == data){
        if(head->next == head){
            delete head;
            head = temp = temp1 = NULL;
            return;
        }
        temp1 = head;
        head = head->next;
        head->prev = temp;
        temp->next = head;
        delete temp1;
        temp1 = NULL;
    }
    temp = head->next;
    do
    {
        if(temp->info == data){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            temp1 = temp;
            temp = temp1->next;
            delete temp1;
            temp1 = NULL;
            continue;
        }
        temp = temp->next;
    } while (temp != head);   
}

bool list::isempty()
{
    if(head == NULL)
        return true;
    return false;
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
        if(temp->next != head)
            cout << " , ";
        temp = temp->next;
    } while (temp != head);
    cout << " ]" << endl;    
}

// void list::search()
// {
//     int key;
//     cout << "Enter key: ";
//     cin >> key;
//     if(head == NULL){
//         cout << "Empty list" << endl;
//         return;
//     }
//     temp = head;
//     do
//     {
//         if(temp->info == key){
//             cout << "Item found" << endl;
//             return;
//         }
//     } while (temp != head);
//     cout << "Item not found" << endl;
// }

// void list::reverse()
// {
//     temp1 = NULL;
//     temp = head->next;
//     while(temp->next != NULL)
//     {
//         head->next = temp1;
//         head->prev = temp;
//         temp1 = head;
//         head = temp;
//         temp = temp->next;
//     }
//     head->next = temp1;
//     head->prev = temp;
//     temp->next = head;
// }

void list::search(int key)
{
    int count = searching(key , head , true , 0);
    if(count == 0)
        cout << "Same!" << endl;
    else if (count < 0)
        cout << "Forward faster" << endl;
    else
        cout << "Backward faster" << endl;
}

int list::searching(int key , node * temp, bool forward_counting , int count)
{
    if(head->info == key)
        return 0;
    if(key == temp->info)
        forward_counting = false;
    if(forward_counting)
        count++;
    else
        count--;
    temp = temp->next;
    if(temp != head)
        return searching(key , temp , forward_counting , count);
    else
        return count;
}

void list::reverse()
{
    if(head == NULL)
        return;
    temp1 = head->prev;
    temp = head->next;
    node * temp2 = head;
    reversing(temp2);
}

void list::reversing(node * temp2)
{
    if(temp == temp2)
    {
        head->prev = temp;
        head->next = temp1;
        return;
    }
    head->prev = temp;
    head->next = temp1;
    temp1 = head;
    head = temp;
    temp = temp->next;
    reversing(temp2);
}

