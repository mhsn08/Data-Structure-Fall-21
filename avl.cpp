#include<iostream>

using namespace std;

struct node
{
    int info;
    node * right , * left;
};

class tree{
    node * root;
    int findBalance(node *);
    int findHeight(node *);
public:
    tree();
    ~tree();
    void remove(int , node * = NULL);
    int insert(int , node * = NULL);
    bool search(int , node * = NULL);
    void print(node * = NULL);
    void removeall(node*);
};

int main() 
{
    tree t;
    t.insert(13);
    t.insert(4);
    t.insert(18);
    t.insert(16);
    t.insert(20);
    t.insert(22);
    t.insert(21);
    t.insert(23);
    t.insert(14);
    t.insert(17);
    t.insert(6);
    t.insert(5);
    t.insert(7);
    t.insert(1);
    t.insert(2);
    t.print();
    t.remove(2);
    t.remove(16);
    t.remove(20);
    t.remove(6);
    t.remove(14);
    t.remove(13);
    t.remove(1);
    t.remove(4);
    t.remove(5);
    t.remove(7);
    t.remove(17);
    t.remove(18);
    t.remove(21);
    t.remove(22);
    t.insert(16);
    t.insert(78);
    t.remove(22);
    cout << endl;
    t.print();
    // if(t.search(201))
    //     cout << "Sucess!" << endl;
    // else
    //     cout << "Here BRUH" << endl;
    return 0;
}

tree::tree()
{
    root = NULL;
}

tree::~tree()
{
    removeall(root);
}

int tree::insert(int info ,node * temp)
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
    if(temp->info > info)
    {
        if(temp->left == NULL)
        {
            temp->left = new node;
            temp = temp->left;
            temp->info = info;
            temp->left = temp->right = NULL;
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
            temp->info = info;
            temp->left = temp->right = NULL;
            return;
        }
        else
        {
            insert(info , temp->right);
        }
    }
}

bool tree::search(int info , node * temp)
{
    if(root == NULL)
        return false;
    if(temp == NULL)
        temp = root;
    if(temp->info == info)
        return true;
    if(temp->info > info)
    {
        if(temp->left != NULL)
            return search(info , temp->left);
        else
            return false;
    }
    else
    {
        if(temp->right != NULL)
            return search(info , temp->right);
        else
            return false;
    }
}

void tree::print(node * temp)
{
    if(root == NULL)
    {
        cout << "Empty Tree!" << endl;
        return;
    }
    if(temp == NULL)
        temp = root;
    if(temp->left != NULL)
        print(temp->left);
    cout << temp->info << ' ';
    if(temp->right != NULL)
        print(temp->right);
}

void tree::remove(int info,node * temp)
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

int tree::findBalance(node * temp)
{
    if(temp->left == NULL && temp->right == NULL);
        return 0;
    int right , left;
    right = left = 0;
    if(temp->left != NULL)
        left = findHeight(temp->left);
    if(temp->right != NULL)
        right = findHeight(temp->right);
    return left - right;
}

int tree::findHeight(node * temp)
{
    if(temp->left == NULL && temp->right == NULL)
        return 0;
    int left , right;
    left = right = 0;
    if(temp->left != NULL)
    {
        left += 1;
        left += findHeight(temp->left);
    }
    if(temp->right != NULL)
    {
        right += 1;
        right += findHeight(temp->right);
    }
    if(right > left)
        return right;
    else
        return left;
}

void tree::removeall(node * temp)
{
    if(root == NULL)
        return;
    if(temp->left != NULL)
        removeall(temp->left);
    if(temp->right != NULL)
        removeall(temp->right);
    delete temp;
}