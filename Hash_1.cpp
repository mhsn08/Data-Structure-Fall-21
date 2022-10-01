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
    arr[info] = info;
}

int * HASH::Search(int info)
{
    return arr + info;
}

void HASH::remove(int info)
{
    *(arr + info) = -1;
}