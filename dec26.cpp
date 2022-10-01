#include<iostream>
using namespace std;
struct node{int info;node* left; node* right;};

void Lev_prnt(node ** temp , int size)
{
    node ** temp2 = temp; int n_size = 0;
    for(int i = 0; i < size; i++)
    {   cout << (*temp2)->info << " ";
        if((*temp2)->left != NULL) n_size++;
        if((*temp2)->right != NULL) n_size++;
        temp2 = temp + 1 + i;}
    if(n_size == 0)
        return;
    node ** temp3 = new node *[n_size]; int cur_ptr = 0; temp2 = temp;
    for(int i = 0; i < size; i++)
    {
        if((*temp2)->left != NULL)
        {
            temp3[cur_ptr] = (*temp2)->left; cur_ptr++;
        }
        if((*temp2)->right != NULL)
        {
            temp3[cur_ptr] = (*temp2)->right; cur_ptr++;
        }
        temp2 = temp + 1 + i;}
    Lev_prnt(temp3 , n_size);
}

int main()
{
    node * root = new node; node * temp = root;
    root->info = 1;
    temp->left = new node; temp->left->info = 2;
    temp->right = new node; temp->right->info = 3;
    temp = temp->left;
    temp->left = new node; temp->left->info = 4;
    temp->right = new node; temp->right->info = 5;
    temp->right->left = NULL;temp->right->right = NULL;
    temp = root->right;
    temp->left = new node; temp->left->info = 6;
    temp->right = new node; temp->right->info = 7;
    temp->left->left = NULL;temp->left->right = NULL;temp->right->left = NULL;temp->right->right = NULL;
    temp = root->left->left;
    temp->left = new node; temp->left->info = 8;
    temp->right = new node; temp->right->info = 9;
    temp->left->left = NULL;temp->left->right = NULL;temp->right->left = NULL;temp->right->right = NULL;
    node ** temp1 = &root;
    Lev_prnt(temp1 , 1);
}


