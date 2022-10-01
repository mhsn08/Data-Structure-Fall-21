#include<iostream>

using namespace std;

struct node
{
    int info;
    node * next;
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
    void search();
    void print();
    bool isempty();
};

int main()
{
    list l1;
    int des;
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
    temp = head;
    while(temp != NULL){
        temp1 = temp;
        temp = temp->next;
        delete temp1;
    }
    head = temp1 = temp = NULL;
}

void list::insert1()
{
    int key,data;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the Data: ";
    cin >> data;
    temp = head;
    if(head == NULL){
        head = new node;
        head->info = data;
        head->next = NULL;
        return;
    }
    while(temp->next != NULL){
        if(temp->info == key){
            temp1 = new node;
            temp1->info = data;
            temp1->next = temp->next;
            temp->next = temp1;
            return;
        }
        temp = temp->next;
    }
    temp1 = new node;
    temp1->info = data;
    temp1->next = temp->next;
    temp->next = temp1;
}

void list::insertall()
{
    int key,data;
    cout << "Enter the key: ";
    cin >> key;
    cout << "Enter the Data: ";
    cin >> data;
    bool ifinserted = false;
    temp = head;
    if(head == NULL){
        head = new node;
        head->info = data;
        head->next = NULL;
        return;
    }
    while(temp->next != NULL){
        if(temp->info == key){
            ifinserted = true;
            temp1 = new node;
            temp1->info = data;
            temp1->next = temp->next;
            temp->next = temp1;
            temp = temp1->next;
            if(temp1->next == NULL){
                return;
            }
            continue;
        }
        temp = temp->next;
    }
    if(temp->info == key){
        temp1 = new node;
        temp1->info = data;
        temp1->next = NULL;
        temp->next = temp1;
        return;
    }
    if(!ifinserted){
        temp1 = new node;
        temp1->info = data;
        temp1->next = NULL;
        temp->next = temp1;
    }
}

void list::deleteall()
{
    int data;
    cout << "Enter what you want to delete: ";
    cin >> data;
    if(head == NULL){
        return;
    }
    while(head->info == data){
        temp = head;
        head = head->next;
        delete temp;
        temp = head;
        if(head == NULL)
            return;
    }
    temp = head;
    while(temp->next != NULL){
        if(temp->next->info == data){
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            temp1 = NULL;
            if(temp == NULL)
                return;
            continue;
        }
        temp = temp->next;
    }
    if(temp->info == data){
        delete temp;
        temp = NULL;
    }
}

void list::deleteone()
{
    int data;
    cout << "Enter what you want to delete: ";
    cin >> data;
    if(head == NULL)
        return;
    if(head->info == data){
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL){
        if(temp->next->info == data){
            temp1 = temp->next;
            temp->next = temp1 ->next;
            delete temp1;
            temp1 = NULL;
            return;
        }
        temp = temp->next;
    }
}

void list::search()
{
    int data;
    cout << "Enter what you want to Search: ";
    cin >> data;
    bool iffound = false;
    if(head == NULL)
        return;
    temp = head;
    while(temp != NULL){
        if(temp->info == data){
            iffound = true;
            cout << "Found " << temp->info << " in the list." << endl;
        }
        temp = temp->next;
    }
    if(!iffound)
        cout << "Sorry, couldn't find anything" << endl;
}

void list::print()
{
    if(head == NULL)
        return;
    temp = head;
    cout << "[ ";
    while(temp != NULL){
        cout << temp->info;
        if(temp->next != NULL){
            cout << " , ";
        }
        temp = temp->next;
    }
    cout << " ]" << endl;
}

bool list::isempty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

void list::reverse()
{
    temp1 = NULL;
    temp = head->next;
    while (temp != NULL)
    {
        head->next = temp1;
        temp1 = head;
        head = temp;
        temp = temp->next;
    }
    head->next = temp1;
}