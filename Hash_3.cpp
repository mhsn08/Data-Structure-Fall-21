#include<iostream>
using namespace std;

class HASH
{
    int * arr;
    int size;
    int length;
public:
    HASH(int);
    ~HASH();
    void insert(int);
    int * Search(int);
    void remove(int);
    void REHASH();
};

int main()
{
    HASH h(3);
    h.insert(1);
    h.insert(2);
    h.insert(3);
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
    length = 0;
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
            length++;
            if((length * 100.0)/size >= 75.0)
                REHASH();
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

void HASH::REHASH()
{
    int * temp = arr;
    int prev_size = size;
    size = size * 2;
    arr = new int[size];
    length = 0;
    for(int i = 0; i < size;i++)
    {
        *(arr + i) = -1;
    }
    int j = -1;
    for(int i = 0 ; i < prev_size ; i++)
    {
        if(*(temp + i) == -1)
            continue;
        insert(*(temp + i));
    }
    delete [] temp;
}