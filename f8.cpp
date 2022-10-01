#include<iostream>
using namespace std;

void BuildMinHeap(int * arr , int size)
{
    int tempinfo = 0;
    int lastPar = size / 2;
    for(int i = size / 2; i >= 1 ;i--)
    {
        if(arr[i] > arr[2*i] || arr[i] > arr[2*i + 1])
        {
            if(arr[2*i] < arr[2*i + 1])
            {
                tempinfo = arr[i];
                arr[i] = arr[2*i];
                arr[2*i] = tempinfo;
            }
            else
            {
                tempinfo = arr[i];
                arr[i] = arr[2*i + 1];
                arr[2*i + 1] = tempinfo;
            }
        }
    }
}

void checknode(int * arr , int pos)
{
    int tempinfo = arr[pos];
    if(arr[pos] > arr[pos * 2] || arr[pos] > arr[pos * 2 + 1])
    {
        if(arr[pos * 2] < arr[pos * 2 + 1])
        {
            arr[pos] = arr[pos * 2];
            arr[pos * 2] = tempinfo;
        }
        else
        {
            arr[pos] = arr[pos * 2 + 1];
            arr[pos * 2 + 1] = tempinfo;
        }
    }
}

int main()
{
    int arr[] = {0 , 65 , 31 , 32 , 26 , 21 , 19 , 68 , 13 , 24 , 15 , 14 , 16 , 5 , 70 , 12};
    for(int i = 1; i < 16; i++)
        cout << arr[i] << ' ';
    cout << endl;
    BuildMinHeap(arr , 15);
    for(int i = 1; i < 16; i++)
        cout << arr[i] << ' ';
    return 0;
}