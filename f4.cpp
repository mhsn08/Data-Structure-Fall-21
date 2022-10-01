#include<iostream>
using namespace std;

struct node
{
    int info;
    node * next;
    node * prev;
};

class LinkList
{
    node * head;
public:
    LinkList();
    ~LinkList();
    void insertion(int,int);
    void deleteion(int);
};

int main()
{
    return 0;
}

void LinkList::insertion(int info, int key)
{
    if(head == NULL)
    {
        head = new node;
        head->info = info;
        head->next = head->prev = head;
        return;
    }
    node * temp = head;
    while (temp->info != key)
    {
        temp = temp->next;
        if(temp->next == head)
            return;
    }
    node * temp2 = new node;
    temp2->info = info;
    temp2->prev = temp;
    temp2->next = temp->next;
    temp->next = temp2;
    temp2->next->prev = temp2;
}

void LinkList::deleteion(int info)
{
    node * temp = head;
    if(head->info == info)
    {
        while(temp->next != head)
            temp = temp->next;
        head = head->next;
        head->prev = temp;
        delete temp->next;
        temp->next = head;
        return;
    }
    while(temp->info != info)
    {
        if(temp->next == head)
            return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

