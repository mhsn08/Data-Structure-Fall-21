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
        head->next = NULL;
        return;
    }
    node * temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new node;
    temp = temp->next;
    temp->info = info;
    temp->next = NULL;
}

void LinkList::deleteion(int info)
{
    node * temp = head;
    if(head->info == info)
    {
        head = head->next;
        delete temp;
        return;
    }
    while(temp->next->info != info)
    {
        if(temp->next == NULL)
            return;
    }
    node * temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

