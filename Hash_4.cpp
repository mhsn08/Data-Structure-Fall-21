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
    ~HASH();
    void insert(string);
    node * Search(string);
    void Remove(string);
};

int main()
{
    HASH t;
    t.insert("ACC");
    t.insert("Aed");
    t.insert("ADG");
    t.insert("ABC");
    t.insert("VCC");
    t.Remove("ABC");
    node * temp = t.Search("ABC");
    if(temp != NULL)
        cout << temp->name << endl;
    else
        cout << "BRUH" << endl;
    temp = t.Search("ACC");
    if(temp != NULL)
        cout << temp->name << endl;
    else
        cout << "BRUH" << endl;
    // temp = t.Search("ACC");
    // if(temp != NULL)
    //     cout << temp->name << endl;
    // temp = t.Search("VCC");
    // if(temp != NULL)
    //     cout << temp->name << endl;
    // temp = t.Search("ADG");
    // if(temp != NULL)
    //     cout << temp->name << endl;
    // temp = t.Search("Aed");
    // if(temp != NULL)
    //     cout << temp->name << endl;
    // temp = t.Search("BRUH");
    // if(temp != NULL)
    //     cout << temp->name << endl;
    // else
    //     cout << "BRUH" << endl;
    return 0;
}

HASH::HASH()
{
    arr = new node *[26];
    for(int i = 0; i < 26; i++)
    {
        arr[i] = NULL;
    }
}

HASH::~HASH()
{
    node * temp = NULL;
    node * temp2 = NULL;
    for(int i = 0; i < 26; i++)
    {
        temp = arr[i];
        while (temp != NULL)
        {
            temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
    delete [] arr;
}

void HASH::insert(string name)
{
    int i = int(name[0]);
    if( i>= 65 && i <=90)
        i = i - 65;
    else
        i = i - 97;
    if(arr[i] == NULL)
    {
        arr[i] = new node;
        arr[i]->name = name;
        arr[i]->next = NULL;
        return;
    }
    if(arr[i]->name > name)
    {
        node * temp2 = new node;
        temp2->name = name;
        temp2->next = arr[i];
        arr[i] = temp2;
        return;
    }
    node * temp = arr[i];
    while (true)
    {
        if(temp->next == NULL)
        {
            temp->next = new node;
            temp = temp->next;
            temp->name = name;
            temp->next = NULL;
            return;
        }
        if(temp->next->name > name)
        {
            node * temp2 = new node;
            temp2->name = name;
            temp2->next = temp->next;
            temp->next = temp2;
            return;
        }
        temp = temp->next;
    }
}

node * HASH::Search(string name)
{
    int i = int(name[0]);
    if( i>= 65 && i <=90)
        i = i - 65;
    else
        i = i - 97;
    node * temp = arr[i];
    while(temp != NULL)
    {
        if(temp->name == name)
            return temp;
        temp = temp->next;
    }
    return temp;
}

void HASH::Remove(string name)
{
    int i = int(name[0]);
    if( i>= 65 && i <=90)
        i = i - 65;
    else
        i = i - 97;
    if(arr[i] == NULL)
    {
        cout << "Nothing to Delete" << endl;
        return;
    }
    node * temp = arr[i];
    if(arr[i]->name == name)
    {
        arr[i] = arr[i]->next;
        delete temp;
        return;
    }
    while (temp->next != NULL)
    {
        if(temp->next->name == name)
        {
            node * temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            return;
        }
        temp = temp->next;
    }
    cout << "Nothing to Delete" << endl;
}



