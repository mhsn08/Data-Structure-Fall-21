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
    void insertion(int);
    void deleteion(int);
};

int main()
{
    return 0;
}

void LinkList::insertion(int info)
{
    if(head == NULL)
    {
        head = new node;
        head->info = info;
        head->next = head->prev = NULL;
        return;
    }
    node * temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    node * temp2 = new node;
    temp2->info = info;
    temp2->prev = temp;
    temp2->next = temp->next;
    temp->next = temp2;
}

void LinkList::deleteion(int info)
{
    node * temp = head;
    if(head->info == info)
    {
        head = head->next;
        delete temp;
        if(head != NULL)
            head->prev = NULL;
        return;
    }
    while(temp->info != info)
    {
        if(temp->next == NULL)
            return;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
}

