#include<iostream>
#include<string>
using namespace std;

struct node
{
    char info;
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
    void insert_at_end(char);
    string getdata();
    void print();
};

list * concatenate(list * l1, list * l2)
{
    string data;
    data = l1->getdata();
    data += l2->getdata();
    list * l3;
    l3 = new list;
    for(int i = 0; i < data.length(); i++){
        l3->insert_at_end(data[i]);
    }
    return l3;
}

list::list()
{
    head = temp1 = temp = NULL;
}
list::~list()
{
    if(head == NULL){
        return;
    }
    temp = head;
    while(temp != NULL){
        temp1 = temp;
        temp = temp->next;
        delete temp1;
    }
    head = temp1 = temp = NULL;
}
void list::insert_at_end(char data)
{
    if(head == NULL){
        head = new node;
        head->info = data;
        head->next = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp1 = new node;
    temp1->info = data;
    temp1->next = NULL;
    temp->next = temp1;
}

string list::getdata()
{
    if(head == NULL)
        return "";
    temp = head;
    string ret = "";
    while(temp != NULL){
        ret += temp->info;
        temp = temp->next;
    }
    return ret;
}

void list::print()
{
    cout << endl;
    if(head == NULL){
        return;
    }
    temp = head;
    while(temp != NULL){
        cout << temp->info;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    list * l1 = new list;
    list * l2 = new list;
    string data1 = "Ahmed";
    string data2 = " Someone";
    for(int i = 0; i < data1.length(); i++){
        l1->insert_at_end(data1[i]);
    }
    for(int i = 0; i < data2.length(); i++){
        l2->insert_at_end(data2[i]);
    }
    list * l3;
    l3 = concatenate(l1,l2);
    l3->print();
    return 0;
}