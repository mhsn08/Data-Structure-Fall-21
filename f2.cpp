#include<iostream>
using namespace std;

struct node
{
    int info;
    node * next;
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
        head->next = head;
        return;
    }
    node * temp = head;
    while (temp->info != key)
    {
        temp = temp->next;
        if(temp == head)
            return;
    }
    node * temp2 = new node;
    temp2->info = info;
    temp2->next = temp->next;
    temp->next = temp2;
}

void LinkList::deleteion(int info)
{
    node * temp = head;
    if(head->info == info)
    {
        if(head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        temp = head->next;
        while(temp->next != head)
            temp = temp->next;
        head = head->next;
        delete temp->next;
        temp->next = head;
        return;
    }
    while(temp->next->info != info)
    {
        if(temp->next == head)
            return;
    }
    node * temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

