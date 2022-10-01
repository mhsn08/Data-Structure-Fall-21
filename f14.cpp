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
    int no_nodes , height;
    void removeall(node *);
    bool insert(int , node * , int);
    bool remove(node * , int);
public:
    node * root;
    CBT();
    ~CBT();
    void insert(int);
    void in_order_trav(node *);
    void remove();
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
                    // cout << "Swap " << temp->info << " with " << temp->left->info << endl;
                    temp = temp->left;
                    ifswap = true;
                }
                else
                {
                    tempinfo = temp->info;
                    temp->info = temp->right->info;
                    temp->right->info = tempinfo;
                    // cout << "Swap " << temp->info << " with " << temp->right->info << endl;
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
                // cout << "Swap " << temp->info << " with " << temp->left->info << endl;
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
    if(temp->left != NULL)
        BuildHeap(temp->left);
    // cout << "At " << temp->info << endl;
    Perpulate(temp);
}

void Lev_prnt(node ** temp , int size);

int main()
{
    CBT tree;
    tree.insert(65);
    tree.insert(31);
    tree.insert(32);
    tree.insert(26);
    tree.insert(21);
    tree.insert(19);
    tree.insert(68);
    tree.insert(13);
    tree.insert(24);
    tree.insert(15);
    tree.insert(14);
    tree.insert(16);
    tree.insert(5);
    tree.insert(70);
    tree.insert(12);
    Lev_prnt(&tree.root , 1);
    cout << endl;
    BuildHeap(tree.root);
    Lev_prnt(&tree.root , 1);
    // tree.insert(13);
    // tree.in_order_trav(NULL);
    return 0;
}

CBT::CBT()
{
    root = NULL;
    height = no_nodes = 0;
}

CBT::~CBT()
{
    if(root == NULL)
        return;
    removeall(root);
}

void CBT::removeall(node * temp)
{
    if(temp->left!= NULL)
        removeall(temp->left);
    if(temp->right != NULL)
        removeall(temp->right);
    delete temp;
    if(temp == root)
        root = NULL;
}

void CBT::insert(int info)
{
    insert(info , root , 0);
}

bool CBT::insert(int info , node * temp , int height)
{
    if(root == NULL)
    {
        root = new node;
        root->info = info;
        root->left = root->right = NULL;
        no_nodes++;
        return true;
    }
    if(temp->left == NULL)
    {
        if(no_nodes == pow(2,this->height + 1) - 1)
        {
            temp->left = new node;
            temp = temp->left;
            temp->info = info;
            temp->left = temp->right = NULL;
            no_nodes++; this->height++;
            return true;
        }
        if(this->height == height)
            return false;
        else
        {
            temp->left = new node;
            temp = temp->left;
            temp->info = info;
            temp->left = temp->right = NULL;
            no_nodes++;
            return true;
        }
    }
    if(temp->left != NULL && temp->right == NULL)
    {
        temp->right = new node;
        temp = temp->right;
        temp->info = info;
        temp->left = temp->right = NULL;
        no_nodes++;
        return true;
    }
    if(temp->left != NULL)
    {
        if(insert(info , temp->left , height + 1))
            return true;
    }
    if(temp->right != NULL)
    {
        if(insert(info , temp->right , height + 1))
            return true;
    }
    return false;
}

void CBT::in_order_trav(node * temp)
{
    if(root == NULL)
        return;
    if(temp == NULL)
        temp = root;
    if(temp->left != NULL)
        in_order_trav(temp->left);
    cout << temp->info << ' ';
    if(temp->right != NULL)
        in_order_trav(temp->right);
}

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

void CBT::remove()
{
    remove(root , 0);
}

bool CBT::remove(node * temp, int height)
{
    if(root == NULL)
        return false;
    if(root->right == NULL && root->left == NULL)
    {
        delete root;
        root = NULL;
        return true;
    }
    if(this->height == height + 1)
    {
        if(temp->right != NULL)
        {
            delete temp->right;
            temp->right = NULL;
            no_nodes--;
            return true;
        }
        if(temp->left != NULL)
        {
            delete temp->right;
            temp->left = NULL;
            if(pow(2,this->height) == no_nodes)
                this->height--;
            no_nodes--;
            return true;
        }
    }
    if(temp->right != NULL)
    {
        if(remove(temp->right, height + 1))
            return true;
    }
    if(temp->left != NULL)
    {
        if(remove(temp->left , height + 1))
            return true;
    }
    return false;
}
