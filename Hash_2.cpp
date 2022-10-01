#include<iostream>
using namespace std;

class HASH
{
    int * arr;
    int size;
public:
    HASH(int);
    ~HASH();
    void insert(int);
    int * Search(int);
    void remove(int);
};

int main()
{
    return 0;
}

HASH::HASH(int size)
{
    this->size = size;
    arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        *(arr + i) = -1;
    }
}

HASH::~HASH()
{
    delete [] arr;
    size = 0;
}

void HASH::insert(int info)
{
    int i = info;
    i = i % size;
    int j = i;
    do
    {
        if(i == size)
            i = 0;
        if(*(arr + i) == -1)
        {
            *(arr + i) = info;
            return;
        }
        i++;
    }
    while(i != j);
}

int * HASH::Search(int info)
{
    int i = info;
    i = i % size;
    int j = i;
    do
    {
        if(i == size)
            i = 0;
        if(*(arr + i) == info)
        {
            return (arr + i);
        }
        if(*(arr + i) == -1)
        {
            return NULL;
        }
        i++;
    }
    while (i != j);
    return NULL;
}

void HASH::remove(int info)
{
    int i = info;
    i = i % size;
    int j = i;
    do
    {
        if(i == size)
            i = 0;
        if(*(arr + i) == info)
        {
            *(arr + i) = -1;
        }
        if(*(arr + i) == -1)
        {
            cout << "Nothing Found" << endl;
            return;
        }
        i++;
    }
    while(i != j);
    cout << "Nothing Found" << endl;
}

