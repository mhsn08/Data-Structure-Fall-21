#include<iostream>

using namespace std;

struct node
{
    int info;
    node * right , * left;
};

class BST
{
public:
    node * root;
    BST();
    ~BST();
    void insertion(int , node * = NULL);
    void removeall(node * = NULL);
    void in_order_traversal(node * = NULL);
    int count_nodes(node *);
    void p_middle_val();
    int traverse_upto(node * , int , int);
    void remove(int , node * = NULL);
};

int main()
{
    BST tree;
    node * r = tree.root;
    tree.insertion(40 , r);
    tree.insertion(30 , r);
    tree.insertion(20 , r);
    tree.insertion(10 , r);
    tree.insertion(5 , r);
    tree.insertion(18 , r);
    tree.insertion(17 , r);
    tree.insertion(19 , r);
    tree.insertion(28 , r);
    tree.insertion(37 , r);
    tree.insertion(50 , r);
    tree.insertion(47 , r);
    tree.insertion(48 , r);
    tree.insertion(55 , r);
    tree.insertion(57 , r);
    tree.insertion(60 , r);
    tree.insertion(64 , r);
    tree.insertion(65 , r);
    tree.insertion(66 , r);
    tree.insertion(70 , r);
    tree.insertion(80 , r);
    tree.insertion(75 , r);
    tree.insertion(82 , r);
    tree.in_order_traversal();
    cout << endl;
    cout << tree.count_nodes(tree.root) << endl;
    tree.p_middle_val();
    return 0;
}

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    removeall();
}

void BST::insertion(int key , node * temp)
{
    if(root == NULL)
    {
        root = new node;
        root->right = root->left = NULL;
        root->info = key;
        return;
    }
    if(temp == NULL)
        temp = root;
    if(temp->info == key)
    {
        cout << "Duplication Not Allowed!" << endl;
        return;
    }
    if(temp->info > key)
    {
        if(temp->left == NULL)
        {
            temp->left = new node;
            temp = temp->left;
            temp->left = temp->right = NULL;
            temp->info = key;
            return;
        }
        else
            insertion(key , temp->left);
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = new node;
            temp = temp->right;
            temp->left = temp->right = NULL;
            temp->info = key;
            return;
        }
        else
            insertion(key, temp->right);
    }
}

void BST::removeall(node * temp)
{
    if(temp == NULL)
        temp = root;
    if(temp->left != NULL)
        removeall(temp->left);
    if(temp->right != NULL)
        removeall(temp->right);
    delete temp;
}

void BST::in_order_traversal(node * temp)
{
    if(root == NULL)
    {
        cout << "[ ]" << endl;
        return;
    }
    if(temp == NULL)
        temp = root;
    if(temp->left != NULL)
        in_order_traversal(temp->left);
    cout << temp->info << ' ';
    if(temp->right != NULL)
        in_order_traversal(temp->right);
}

int BST::count_nodes(node * temp)
{
    if(root == NULL)
        return 0;
    int count = 1;
    if(temp->left != NULL)
        count += count_nodes(temp->left);
    if(temp->right != NULL)
        count += count_nodes(temp->right);
    return count;
}

void BST::p_middle_val()
{
    int count = count_nodes(root);
    if(count == 0)
    {
        cout << "Empty Tree!" << endl;
        return;
    }
    count = (count / 2) + 1;
    traverse_upto(root , count , 0);
}

int BST::traverse_upto(node * temp , int count , int current)
{
    if(temp->left != NULL)
        current = traverse_upto(temp->left , count , current);
    current++;
    if(count == current)
    {
        cout << temp->info << endl;
        return 0;
    }
    if(temp->right != NULL)
        current = traverse_upto(temp->right , count , current);
    return current;
}




