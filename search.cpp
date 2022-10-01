#include<iostream>
using namespace std;

int * BinarySearch(int , int * , int);

int main()
{
    int temp[] = {1,2,3,4,5,6,7,8,9};
    int * temp1 = BinarySearch(10 , temp , 9);
    if(temp1 != NULL)
        cout << "Found" << endl;
    else
        cout << "BRUH" << endl;
    return 0;
}

int * BinarySearch(int key ,int * temp , int size)
{
    int * start = temp;
    int * end = temp + size - 1;
    int middle = size / 2;
    int * current = temp + middle;
    while(start != end - 1)
    {
        if(*current == key)
            return current;
        if(*current > key)
            end = current;
        else
            start = current;
        middle = middle / 2;
        current = start + middle;
    }
    if(*start == key)
        return current;
    if(*end == key)
        return end;
    return NULL;
}