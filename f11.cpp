#include<iostream>
using namespace std;

struct node
{
    string name;
    node * next;
};

class HASH
{
    node ** arr;
public:
    HASH();
    void insertion(string);
    void Remove(string);
};

int main()
{
    return 0;
}

HASH::HASH()
{
    arr = new node *[26];
    for(int i = 0; i < 26; i++)
        arr[i] = NULL;
}

void HASH::insertion(string name)
{
    int pos = int(name[0]) - 65;
    if(arr[pos] == NULL)
    {
        arr[pos] = new node;
        arr[pos]->name = name;
        arr[pos]->next = NULL;
        return;
    }
    node * temp = arr[pos];
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new node;
    temp->next->name = name;
    temp->next->next = NULL;
}

void HASH::Remove(string name)
{
    int pos = int(name[0]) - 65;
    if(arr[pos] == NULL)
        return;
    node * temp = arr[pos];
    if(arr[pos]->name == name)
    {
        arr[pos] = arr[pos]->next;
        delete temp;
        return;
    }
    while(temp->next->name != name)
    {
        if(temp->next == NULL)
            return;
        temp = temp->next;
    }
    node * temp2 = temp->next;
    temp = temp2->next;
    delete temp2;
    return;
}




