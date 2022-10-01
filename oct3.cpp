#include<iostream>

using namespace std;

// void concatenate(list * l1, list * l2);

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
    list operator + (list l2){
        this->temp = this->head;
        while(this->temp->next != NULL){
            this->temp = this->temp->next;
        }
        this->temp1 = new node;
        this->temp1->info = l2.head->info;
        this->temp1->next = NULL;
        this->temp->next = this->temp1;
        this->temp = this->temp->next;
        l2.temp = l2.head->next;
        while(l2.temp != NULL){
            this->temp1 = new node;
            this->temp1->info = l2.temp->info;
            this->temp1->next = NULL;
            this->temp->next = this->temp1;
            this->temp = this->temp->next;
        }
    }
};

list::list(/* args */)
{
    head = temp1 = temp = NULL;
}

list::~list()
{
}

list * concatenate(list l1, list l2)
{
    list retlist;
    retlist = l1 + l2;
}