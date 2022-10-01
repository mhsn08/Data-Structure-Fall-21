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
    void insert1(int,int);
    void insertall(int,int);
    void deleteall(int);
    void deleteone(int);
    void search();
    void print();
    bool isempty();
};

int main()
{
    list l1;
    for(int i = 0; i < 6; i++)
        l1.insert1(1,1);
    l1.insertall(1,2);
    l1.insertall(2,3);
    l1.insertall(3,4);
    l1.insert1(4,4);
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

void list::insert1(int key, int data)
{
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

void list::insertall(int key, int data)
{
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
    if(temp->info == data){
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

void list::deleteall(int data)
{
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
        }
        temp = temp->next;
    }
    if(temp->info == data){
        delete temp;
        temp = NULL;
    }
}

void list::deleteone(int data)
{
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
    }
}

// void list::search()
// {
//     int data;
//     cout << "Enter what you want to Search: ";
//     cin >> data;
//     bool iffound = false;
//     if(head == NULL)
//         return;
//     temp = head;
//     while(temp != NULL){
//         if(temp->info == data){
//             iffound = true;
//             cout << "Found " << temp->info << " in the list." << endl;
//         }
//         temp = temp->next;
//     }
//     if(!iffound)
//         cout << "Sorry, couldn't find anything" << endl;
// }

// void list::print()
// {
//     if(head == NULL)
//         return;
//     temp = head;
//     cout << "[ ";
//     while(temp != NULL){
//         cout << temp->info;
//         if(temp->next != NULL){
//             cout << " , ";
//         }
//         temp = temp->next;
//     }
//     cout << " ]" << endl;
// }

// bool list::isempty()
// {
//     if(head == NULL)
//         return true;
//     else
//         return false;
// }