#include<iostream>

using namespace std;


class something
{
    public:
    int somethin()
    {
        static int t {};               // If we wrote 0, it will initiliaze again and again
        if (t != 10)
        {
            t = t++;
            somethin();

        }
        return t;
    }
};

struct node
{
    int info;
    node * left , * right;
};

class BST
{
    node * root;
    int Dublication;
    void removeall(node *);
public:
    BST();
    ~BST();
    void remove(int , node * = NULL);
    void insert(int , node * = NULL);
    void search(int , node * = NULL);
};

int main()
{
    something s1;
    cout << s1.somethin() << endl;
    return 0;
}

BST::BST()
{
    root = NULL;
    Dublication = 0;
}

BST::~BST()
{
    removeall(root);
}

void BST::removeall(node * temp)
{
    if(temp == NULL)
        return;
    if(temp->left != NULL)
        removeall(temp->left);
    if(temp->right != NULL)
        removeall(temp->right);
    delete temp;
}

void BST::insert(int info , node * temp)
{
    if(root == NULL)
    {
        root = new node;
        root->info = info;
        root->left = root->right = NULL;
        return;
    }
    if(temp == NULL)
        temp = root;
    if(temp->info == info)
    {
        Dublication += 1;
        return;
    }
    if(temp->info > info)
    {
        if(temp->left == NULL)
        {
            temp->left = new node;
            temp = temp->left;
            temp->left = temp->right = NULL;
            temp->info = info;
            return;
        }
        else
            insert(info , temp->left);
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = new node;
            temp = temp->right;
            temp->right = temp->left = NULL;
            temp->info = info;
            return;
        }
        else
            insert(info , temp->right);
    }
}

void BST::remove(int info , node * temp)
{
    if(root == NULL)
        return;
    if(root->info = info)
    {
        node * temp;
        
    }
}
