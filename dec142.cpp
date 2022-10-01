#include<iostream>

using namespace std;

int calculate_fib(int upto , int current = 1 , int cur_val = 0 , int next_val = 1)
{
    if(upto == current)
        return cur_val;
    else
    {
        int temp = cur_val;
        cur_val = next_val;
        next_val = next_val + temp;
        current++;
        return calculate_fib(upto , current , cur_val , next_val);
    }
}

void storefib(int * arr , int upto , int current = 0 , int cur_val = 0 , int next_val = 1)
{
    *arr = cur_val;
    if(upto == current)
        return;
    next_val = next_val + cur_val;
    cur_val = next_val - cur_val;
    arr++;
    current++;
    storefib(arr , upto , current , cur_val , next_val);
}

void fill_jugs(int * jug1 , int * jug2 , int amount_to_be_filled)
{
    jug1 = 0;
}

int main()
{
    /*
        Stack * s = new Stack(4);
        
    */
    return 0;
}