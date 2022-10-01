#include<iostream>
using namespace std;

int checknode(int * arr , int pos , int size)
{
    int tempinfo = arr[pos];
    if(arr[pos] > arr[pos * 2] || arr[pos] > arr[pos * 2 + 1])
    {
        if(arr[pos * 2] < arr[pos * 2 + 1])
        {
            arr[pos] = arr[pos * 2];
            arr[pos * 2] = tempinfo;
            return pos * 2;
        }
        else
        {
            arr[pos] = arr[pos * 2 + 1];
            arr[pos * 2 + 1] = tempinfo;
            return (pos * 2) + 1;
        }
    }
    return size + 1;
}

void BuildMinHeap(int * arr , int size)
{
    int cur_node = size / 2;
    int chk_pos = size / 2;
    while(cur_node != 0)
    {
        chk_pos = checknode(arr , chk_pos , size);
        if(chk_pos * 2 < size)
            continue;
        else
        {
            cur_node--;
            chk_pos = cur_node;
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