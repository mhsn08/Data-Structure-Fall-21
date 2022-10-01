#include<iostream>
#include<cmath>
using namespace std;

struct node
{
    int info;
    node * left , * right;
};

class CBT
{
    int height , no_nodes;
public:
    node * root;
    CBT();
    void insert(int);
    bool insert(node *, int , int);
    void remove(int);
    bool remove(node *, int , int, node *);
    void in_ord(node *);
    node * search(node * ,int);
};

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
    CBT tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.remove(3);
    Lev_prnt(&tree.root , 1);
    cout << endl;
    tree.in_ord(tree.root);
    return 0;
}

CBT::CBT()
{
    root = NULL;
    height = no_nodes = 0;
}

void CBT::insert(int info)
{
    insert(root , 0 , info);
}

bool CBT::insert(node * temp , int l_height , int info)
{
    if(root == NULL)
    {
        root = new node;
        root->left = root->right = NULL;
        root->info = info;
        no_nodes++;
        return true;
    }
    if(temp->left == NULL)
    {
        if(pow(2,height + 1) - 1 == no_nodes)
        {
            temp->left = new node;
            temp = temp->left;
            temp->info = info;
            temp->left = temp->right = NULL;
            height++;
            no_nodes++;
            return true;
        }
        else if(l_height < height)
        {
            temp->left = new node;
            temp = temp->left;
            temp->info = info;
            temp->left = temp->right = NULL;
            no_nodes++;
            return true;
        }
    }
    if(temp->right == NULL && l_height < height)
    {
        temp->right = new node;
        temp = temp->right;
        temp->left = temp->right = NULL;
        temp->info = info;
        no_nodes++;
        return true;
    }
    if(temp->left != NULL)
    {
        if(insert(temp->left , l_height + 1 , info))
            return true;
    }
    if(temp->right != NULL)
    {
        if(insert(temp->right , l_height + 1 , info))
            return true;
    }
    return false;
}

void CBT::in_ord(node * temp)
{
    if(temp->left != NULL)
        in_ord(temp->left);
    cout << temp->info << ' ';
    if(temp->right != NULL)
        in_ord(temp->right);
}

void CBT::remove(int info)
{
    node * temp = search(root , info);
    if(temp != NULL)
        remove(root , 0 , info, temp);
}

node * CBT::search(node * temp, int info)
{
    if(temp->info == info)
        return temp;
    node * temp2 = NULL;
    if(temp->left != NULL)
        temp2 = search(temp->left , info);
    if(temp2 != NULL)
        return temp2;
    if(temp->right != NULL)
        temp2 = search(temp->right , info);
    return temp2;
}

bool CBT::remove(node * temp , int l_height , int info , node * swap)
{
    if(temp->right != NULL)
    {
        if(l_height + 1 == height)
        {
            if(swap = temp->right)
            {
                delete temp->right;
                temp->right = NULL;
                no_nodes--;
                return true;
            }
            else
            {
                swap->info = temp->right->info;
                delete temp->right;
                temp->right = NULL;
                no_nodes--;
                return true;
            }
        }
        if(remove(temp->right , l_height + 1 , info , swap))
            return true;
    }
    if(temp->left != NULL)
    {
        if(l_height + 1 == height)
        {
            if(swap == temp->left)
            {
                delete temp->left;
                temp->left = NULL;
                if(pow(2 , height) == no_nodes)
                {
                    height--;
                }
                no_nodes--;
                return true;
            }
            else
            {
                swap->info = temp->left->info;
                delete temp->left;
                temp->left = NULL;
                if(pow(2 , height) == no_nodes)
                {
                    height--;
                }
                no_nodes--;
                return true;
            }
        }
        if(remove(temp->left , l_height + 1 , info , swap))
            return true;
    }
    return false;
}