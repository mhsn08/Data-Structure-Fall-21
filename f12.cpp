#include<iostream>
using namespace std;

struct node
{
    int info;
    node * left , * right;
};

node * find_min(node * temp , node * cur_min)
{
    if(cur_min == NULL)
    {
        cur_min = temp;
    }
    else if(cur_min->info > temp->info)
    {
        cur_min = temp;
    }
    if(temp->left != NULL)
        cur_min = find_min(temp->left , cur_min);
    if(temp->right != NULL)
        cur_min = find_min(temp->right , cur_min);
    return cur_min;
}

void BuildHead(node * temp)
{
    node * min = find_min(temp , NULL);
    if(min != temp)
    {
        int tempinfo = temp->info;
        temp->info = min->info;
        temp->info = tempinfo;
    }
    if(temp->left != NULL)
        BuildHead(temp->left);
    if(temp->right != NULL)
        BuildHead(temp->right);
}

int main()
{
    return 0;
}