#include<iostream>
using namespace std;

struct node
{
    int info;
    node * next;
};

void selectionSort(int * temp , int size);
void BubbleSort(int * temp , int size);
int * MergeSort(int *, int);
void RadixSort(int * , int);
int ** BucketSort(int * , int);

int main()
{
    int * temp = new int[8];
    temp[0] = 121;
    temp[1] = 145;
    temp[2] = 333;
    temp[3] = 655;
    temp[4] = 532;
    temp[5] = 499;
    temp[6] = 337;
    temp[7] = 212;
    // MergeSort(temp, 8);
    RadixSort(temp , 8);
    for(int i = 0; i < 8; i++)
    {
        cout << temp[i] << ",";
    }
    return 0;
}

int * MergeSort(int * temp , int size)
{
    if(size == 1)
        return temp;
    int n_size = size/2;
    int * firsthalf = new int[n_size];
    int * secondhalf = new int[n_size];
    int * current = temp;
    int * middle = NULL;
    bool if_middledone = true;
    for(int i = 0; i < n_size; i++)
    {
        *(firsthalf + i) = *current;
        current++;
    }
    if(size % 2 != 0)
    {
        middle = new int;
        *middle = *current;
        current++;
        if_middledone = false;
    }
    for(int i = 0; i < n_size; i++)
    {
        *(secondhalf + i) = *current;
        current++;
    }
    MergeSort(firsthalf , n_size);
    MergeSort(secondhalf , n_size);
    int if_first_half_done = 0;
    int if_second_half_done = 0;
    if(middle == NULL)
        if_middledone = true;
    int * current_first = firsthalf;
    int * current_second = secondhalf;
    int * tempinfo = NULL;
    current = temp;
    for(int i = 0; i < size; i++)
    {
        if(if_first_half_done < n_size)
        {
            tempinfo = current_first;
            if(!if_middledone)
            {
                if(*tempinfo > *middle)
                {    
                    tempinfo = middle;
                    if_middledone = true;
                }
            }
            if(if_second_half_done < n_size)
            {
                if(*tempinfo > *current_second)
                {
                    if(tempinfo == middle)
                        if_middledone = false;
                    tempinfo = current_second;
                    current_second++;
                    if_second_half_done++;
                }
            }
            if(tempinfo == current_first)
            {
                current_first++;
                if_first_half_done++;
            }
        }
        else if(!if_middledone)
        {
            tempinfo = middle;
            if(if_second_half_done < n_size)
            {
                if(*tempinfo > *current_second)
                {
                    tempinfo = current_second;
                    current_second++;
                    if_second_half_done++;
                }
                else
                    if_middledone = true;
            }
        }
        else
        {
            tempinfo = current_second;
            current_second++;
            if_second_half_done++;
        }
        *current = *tempinfo;
        current++;
    }
    delete [] firsthalf;
    delete [] secondhalf;
    if(middle != NULL)
        delete middle;
    return temp;
}

void RadixSort(int * temp, int size)
{
    int * current = temp;
    int forswap = *temp;
    int tempinfo = *temp;
    for(int i = 0; i < size; i++)
    {
        if(temp[i] > tempinfo)
            tempinfo = temp[i];
    }
    int max_size = 0;
    while(tempinfo != 0)
    {
        tempinfo = tempinfo / 10;
        max_size++;
    }
    for(int i = 0; i < max_size; i++)
    {
        current = temp;
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < size; k++)
            {
                tempinfo = *(current + k);
                for(int l = 0; l < i; l++)
                    tempinfo = tempinfo / 10;
                tempinfo = tempinfo % 10;
                if(tempinfo == j)
                {
                    forswap = *current;
                    *current = *(current + k);
                    *(current + k) = forswap;
                    current++;
                }
            }
        }
    }
}

int ** BucketSort(int * temp, int size)
{
    node ** arr = new node *[10];
    node * temp = arr[1];
}



