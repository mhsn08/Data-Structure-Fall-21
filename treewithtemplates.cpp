#include<iostream>

using namespace std;

template <class T>
struct node
{
    T info;
    node * right , * left;
};

template <class T>
class tree{
    node<T> * root;
public:
    void insert(T , node<T> *);
    void print(node<T> *);
    tree();
    ~tree();
};

int main() 
{
    tree<int> t;
    t.insert(13);
    t.insert(12);
    t.insert(4);
    t.print();
    return 0;
}

template <class T>
tree<T>::tree()
{
    root = NULL;
}

template <class T>
tree<T>::~tree()
{
}

template <class T>
void tree<T>::insert(T info ,node<T> * temp = root)
{
    if(root == NULL)
    {
        root = new node;
        root->info = this->info;
        root->left = root->right = NULL;
        return;
    }
    if(temp->info > this->info)
    {
        if(temp->left == NULL)
        {
            temp->left = new node;
            temp = temp->left;
            temp->info = this->info;
            return;
        }
        else
        {
            insert(info , temp->left);
        }
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = new node;
            temp = temp->right;
            temp->info = this->info;
            return;
        }
        else
        {
            insert(info , temp->right);
        }
    }
}

template < class T >
void tree<T>::print(node<T> * temp = root)
{
    if(root == NULL)
    {
        cout << "Empty Tree!" << endl;
        return;
    }
    if(temp->left != NULL)
        print(temp->left);
    cout << temp->info << endl;
    if(temp->right != NULL)
        print(temp->right);
}