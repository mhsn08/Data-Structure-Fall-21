#include<iostream>
using namespace std;

struct edge;

struct vertice
{
    string name;
    edge * adjecent;
};

struct edge
{
    vertice * to;
    edge * next;
};

class graph
{
    vertice ** arr;
    int size;
    int length;
public:
    graph(int);
    void insert_vertice(string);
    void insert_edge(string ,vertice *);
};

int main()
{
    return 0;
}

graph::graph(int size)
{
    arr = new vertice * [size];
    this->size = size;
    length = 0;
}

void graph::insert_vertice(string name)
{
    arr[length] = new vertice;
    arr[length]->name = name;
    arr[length]->adjecent = NULL;
    length++;
}

void graph::insert_edge(string name , vertice * dest)
{
    int i = 0;
    while (arr[i]->name != name)
    {
        i++;
        if(i == size)
            return;
    }
    if(arr[i]->adjecent == NULL)
    {
        arr[i]->adjecent = new edge;
        arr[i]->adjecent->to = dest;
        arr[i]->adjecent->next = NULL;
        return;
    }
    edge * temp = arr[i]->adjecent;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new edge;
    temp->next->to = dest;
    temp->next->next = NULL;
}




