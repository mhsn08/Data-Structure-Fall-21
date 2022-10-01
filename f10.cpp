#include<iostream>
using namespace std;

class Hash
{
    int * arr;
    int size;
    int length;
public:
    Hash(int);
    void insertion(int);
    void remove(int);
    int * Search(int);
    void ReHash();
};

int main()
{
    return 0;
}

Hash::Hash(int size)
{
    this->size = size;
    arr = new int[size];
    length = 0;
    for(int i = 0; i < size; i++)
        arr[i] = -1;
}

void Hash::insertion(int info)
{
    int pos = info % size;
    while (true)
    {
        if(arr[pos] == -1)
        {
            arr[pos] = info;
            length++;
            if((length * 100) / size >= 70)
                ReHash();
            return;
        }
        pos++;
        if(pos == size)
            pos = 0;
    }
}

void Hash::remove(int info)
{
    int pos = info % size;
    while (true)
    {
        if(arr[pos] == info)
        {
            arr[pos] = -1;
            return;
        }
        pos++;
        if(pos == size)
            pos = 0;
        if(arr[pos] == -1)
            return;
    }
}

int * Hash::Search(int info)
{
    int pos = info % size;
    while (true)
    {
        if(arr[pos] == info)
            return (arr + pos);
        pos++;
        if(pos == size)
            pos = 0;
        if(arr[pos] == -1)
            return NULL;
    }
}

void Hash::ReHash()
{
    int prev_size = size;
    size = size * 2;
    int * prev_arr = arr;
    arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = -1;
    for(int i = 0; i < prev_size; i++)
    {
        if(prev_arr[i] != -1)
            insertion(prev_arr[i]);
    }
    delete [] prev_arr;
}


