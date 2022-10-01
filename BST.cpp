#include<iostream>

using namespace std;

struct node
{
    int info;
    node * right , * left;
};

class BST
{
    node * root;
public:
    BST();
    ~BST();
    void insertion(int , node * = NULL);
    void removeall(node * = NULL);
    node * search(int , node * = NULL);
    void in_order_traversal(node * = NULL);
    void remove(int , node * = NULL);
};

int main()
{
    BST tree;
    tree.insertion(100);
    tree.insertion(50);
    tree.insertion(55);
    tree.insertion(70);
    tree.insertion(67);
    tree.insertion(71);
    tree.insertion(78);
    tree.in_order_traversal();
    cout << endl;
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

node * BST::search(int key , node * temp)
{
    if(root == NULL)
        return NULL;
    if(temp == NULL)
        temp = root;
    if(temp->info == key)
        return temp;
    if(temp->info > key)
    {
        if(temp->left == NULL)
            return NULL;
        else
            return search(key,temp->left);
    }
    else
    {
        if(temp->right == NULL)
            return NULL;
        else
            return search(key,temp->right);
    }
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

void BST::remove(int info,node * temp)
{
    if(root == NULL)
    {
        cout << "Empty Tree!" << endl;
        return;
    }
    node * temp1 = NULL;
    if(root->info == info)
    {
        if(root->right == NULL)
        {
            temp = root;
            root = root->left;
            delete temp;
            return;
        }
        if(root->left == NULL)
        {
            temp = root;
            root = root->right;
            delete temp;
            return;
        }
        temp = root->right;
        if(temp->left == NULL)
        {
            temp->left = root->left;
            delete root;
            root = temp;
            return;
        }
        while(temp->left->left != NULL)
            temp = temp->left;
        temp1 = temp->left;
        root->info = temp1->info;
        temp->left = temp1->right;
        delete temp1;
        return;
    }
    if(temp == NULL)
        temp = root;
    if(temp->info > info)
    {
        if(temp->left != NULL)
        {
            if(temp->left->info == info)
            {
                if(temp->left->left == NULL && temp->left->right == NULL)
                {
                    delete temp->left;
                    temp->left = NULL;
                    return;
                }
                if((temp->left->left == NULL && temp->left->right != NULL) || (temp->left->left != NULL && temp->left->right == NULL))
                {
                    temp1 = temp->left;
                    if(temp1->left == NULL)
                        temp->left = temp1->right;
                    else
                        temp->left = temp1->left;
                    delete temp1;
                    return;
                }
                else
                {
                    if(temp->left->right->left == NULL)
                    {
                        temp1 = temp->left->right;
                        temp1->left = temp->left->left;
                        delete temp->left;
                        temp->left = temp1;
                        return;
                    }
                    else
                    {
                        temp1 = temp->left->right;
                        while(temp1->left->left != NULL)
                            temp1 = temp1->left;
                        node * temp2 = temp1->left;
                        temp->left->info = temp2->info;
                        temp1->left = temp2->right;
                        delete temp2;
                        return;
                    }
                }
            }
            else
            {
                remove(info,temp->left);
                return;
            }
        }
        else
        {
            cout << "Nothing to delete!" << endl;
            return;
        }
    }
    else
    {
        if(temp->right != NULL)
        {
            if(temp->right->info == info)
            {
                if(temp->right->left == NULL && temp->right->right == NULL)
                {
                    delete temp->right;
                    temp->right = NULL;
                    return;
                }
                if((temp->right->left == NULL && temp->right->right != NULL) || (temp->right->left != NULL && temp->right->right == NULL))
                {
                    temp1 = temp->right;
                    if(temp1->left == NULL)
                        temp->right = temp1->right;
                    else
                        temp->right = temp->left;
                    delete temp1;
                    return;
                }
                else
                {
                    if(temp->right->right->left == NULL)
                    {
                        temp1 = temp->right->right;
                        temp1->left = temp->right->left;
                        delete temp->right;
                        temp->right = temp1;
                        return;
                    }
                    else
                    {
                        temp1 = temp->right->right;
                        while(temp1->left->left != NULL)
                            temp1 = temp1->left;
                        node * temp2 = temp1->left;
                        temp->right->info = temp2->info;
                        temp1->left = temp2->right;
                        delete temp2;
                        return;
                    }
                }
            }
            else
            {
                remove(info , temp->right);
                return;
            }
        }
        else
        {
            cout << "Nothing to Delete!" << endl;
            return;
        }
    }
}


