#include<iostream>
using namespace std;

struct node
{
    int info;
    node * left , * right;
};

void checking_CBT(node * temp)
{
    if(temp == NULL)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    if(Check_CBT(&temp , 1 , false))
        cout << "It is CBT" << endl;
    else
        cout << "It is Not CBT" << endl;
}

bool Check_CBT(node ** temp, int size, bool no_child_flag)
{
    int n_size = 0;
    for(int i = 0; i < size; i++)
    {
        if(temp[i]->left != NULL)
        {
            if(no_child_flag)
                return false;
            n_size++;
        }
        else
        {
            no_child_flag = true;
        }
        if(temp[i]->right != NULL)
        {
            if(no_child_flag)
                return false;
            n_size++;
        }
        else
        {
            no_child_flag = true;
        }
    }
    if(n_size == 0)
        return true;
    node ** next_lev = new node *[n_size];
    int cur_index = 0;
    for(int i = 0; i < size; i++)
    {
        if(temp[i]->left!= NULL)
        {
            next_lev[cur_index] = temp[i]->left;
            cur_index++;
        }
        if(temp[i]->right != NULL)
        {
            next_lev[cur_index] = temp[i]->right;
            cur_index++;
        }
    }
    return Check_CBT(next_lev , n_size , no_child_flag);
}

int main()
{
    return 0;
}