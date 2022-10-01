#include<iostream>
using namespace std;

struct node
{
    int info;
    node * left , * right;
};

void Perpulate(node * temp)
{
    bool ifswap = false;
    int tempinfo = 0;
    while(true)
    {
        if(temp->left != NULL && temp->right != NULL)
        {
            if(temp->info > temp->left->info || temp->info > temp->right->info)
            {
                if(temp->left->info < temp->right->info)
                {
                    tempinfo = temp->info;
                    temp->info = temp->left->info;
                    temp->left->info = tempinfo;
                    temp = temp->left;
                    ifswap = true;
                }
                else
                {
                    tempinfo = temp->info;
                    temp->info = temp->right->info;
                    temp->right->info = tempinfo;
                    temp = temp->right;
                    ifswap = true;
                }
            }
        }
        else if(temp->left != NULL)
        {
            if(temp->left->info < temp->info)
            {
                tempinfo = temp->info;
                temp->info = temp->left->info;
                temp->left->info = tempinfo;
                return;
            }
        }
        if(!ifswap)
            return;
        ifswap = false;
    }
}

void BuildHeap(node * temp)
{
    if(temp->right != NULL)
        BuildHeap(temp->right);
    Perpulate(temp);
    if(temp->left != NULL)
        BuildHeap(temp->left);
}


int main()
{
    return 0;
}