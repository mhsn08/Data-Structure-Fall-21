#include<iostream>
using namespace std;

struct edge;

struct node
{
    int info;
    edge * adjecent;
};

struct edge
{
    node * vertice;
    edge * next;
};

class Graph
{
    node ** adjecency;
    int size;
    int no_vertices;
public:
    Graph(int);
    void insertvert(int);
    void insertedge(int, node *);
    node * Search(int);
};

int main()
{
    Graph g(5);
    g.insertvert(1);
    g.insertvert(2);
    g.insertvert(3);
    g.insertvert(4);
    g.insertvert(5);
    node * temp = g.Search(2);
    g.insertedge(1 , temp);
    temp = g.Search(3);
    g.insertedge(2 , temp);
    temp = g.Search(4);
    g.insertedge(3 , temp);
    g.insertedge(1 , temp);
    temp = g.Search(5);
    g.insertedge(4 , temp);
    temp = g.Search(1);
    g.insertedge(5 , temp);
    cout << g.Search(5)->info << endl;
    return 0;
}

Graph::Graph(int size)
{
    this->size = size;
    adjecency = new node * [size];
    no_vertices = 0;
}

void Graph::insertvert(int info)
{
    adjecency[no_vertices] = new node;
    adjecency[no_vertices]->info = info;
    adjecency[no_vertices]->adjecent = NULL;
    no_vertices++;
}

void Graph::insertedge(int info , node * temp)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if(adjecency[i]->info == info)
            break;
    }
    edge * temp2;
    if(adjecency[i]->adjecent == NULL)
    {
        adjecency[i]->adjecent = new edge;
        temp2 = adjecency[i]->adjecent;
        temp2->vertice = temp;
        temp2->next = NULL;
        return;
    }
    temp2 = adjecency[i]->adjecent;
    while(temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = new edge;
    temp2 = temp2->next;
    temp2->vertice = temp;
    temp2->next = NULL;
}

node * Graph::Search(int info)
{
    edge * temp;
    for(int i = 0; i < no_vertices; i++)
    {
        if(adjecency[i]->info == info)
            return adjecency[i];
        else
        {
            temp = adjecency[i]->adjecent;
            while(temp != NULL)
            {
                if(temp->vertice->info == info)
                    return temp->vertice;
                temp = temp->next;
            }
        }
    }
    return NULL;
}


