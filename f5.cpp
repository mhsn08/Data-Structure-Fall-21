#include<iostream>
using namespace std;

struct node
{
    int info;
    node * left , * right;
};

class AVL
{
public:
    AVL();
    node * root;
    void insert(int);
    bool insertion(node *& , int);
    void deletion(int);
    int deleting(node *& , int);
    void in_ord_trav(node *);
    int height(node *);
    int BalanceFactor(node *);
    void RotateRight(node *&);
    void RotateLeft(node *&);
    void Print_BF_All(node *);
};

bool Check_CBT(node ** temp, int size, bool no_child_flag)
{
    int n_size = 0;
    for(int i = 0; i < size; i++)
    {
        if(temp[i]->left != NULL)
        {
            if(no_child_flag)
                return false;
            n_size++;
        }
        else
        {
            no_child_flag = true;
        }
        if(temp[i]->right != NULL)
        {
            if(no_child_flag)
                return false;
            n_size++;
        }
        else
        {
            no_child_flag = true;
        }
    }
    if(n_size == 0)
        return true;
    node ** next_lev = new node *[n_size];
    int cur_index = 0;
    for(int i = 0; i < size; i++)
    {
        if(temp[i]->left!= NULL)
        {
            next_lev[cur_index] = temp[i]->left;
            cur_index++;
        }
        if(temp[i]->right != NULL)
        {
            next_lev[cur_index] = temp[i]->right;
            cur_index++;
        }
    }
    return Check_CBT(next_lev , n_size , no_child_flag);
}

void checking_CBT(node * temp)
{
    if(temp == NULL)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    if(Check_CBT(&temp , 1 , false))
        cout << "It is CBT" << endl;
    else
        cout << "It is Not CBT" << endl;
}

int main()
{
    AVL tree;
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);
    tree.insert(1);
    tree.insert(2);
    // tree.insert(5);
    tree.insert(7);
    // tree.insert(6);
    // tree.insert(9);
    tree.in_ord_trav(tree.root);
    checking_CBT(tree.root);
    // tree.deletion(8);
    // tree.deletion(3);
    // tree.deletion(5);
    // tree.deletion(2);
    // cout << endl;
    // tree.in_ord_trav(tree.root);
    // tree.Print_BF_All(tree.root);
    return 0;
}

AVL::AVL()
{
    root = NULL;
}

void AVL::insert(int info)
{
    insertion(root , info);
}

bool AVL::insertion(node *& temp , int info)
{
    if(root == NULL)
    {
        root = new node;
        root->info = info;
        root->left = root->right = NULL;
        return true;
    }
    if(temp->info > info)
    {
        if(temp->left == NULL)
        {
            temp->left = new node;
            temp->left->info = info;
            temp->left->left = temp->left->right = NULL;
            return false;
        }
        else
            if(insertion(temp->left , info))
                return true;
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = new node;
            temp->right->info = info;
            temp->right->right = temp->right->left = NULL;
            return false;
        }
        else
            if(insertion(temp->right , info))
                return true;
    }
    int BF = BalanceFactor(temp);
    if(BF <= 1 && BF >=-1)
        return true;
    if(BF == 2)
    {
        if(temp->left->info > info)
        {
            RotateRight(temp);
            return true;
        }
        else
        {
            RotateLeft(temp->left);
            RotateRight(temp);
            return true;
        }
    }
    else
    {
        if(temp->right->info < info)
        {
            RotateLeft(temp);
            return true;
        }
        else
        {
            RotateRight(temp->right);
            RotateLeft(temp);
            return true;
        }
    }
    
}

void AVL::deletion(int info)
{
    if(root == NULL)
        return;
    deleting(root , info);
}

int AVL::deleting(node *& temp , int info)
{
    int prev_case = 1;
    if(root->info == info)
    {
        node * temp2 = root;
        if(root->left != NULL && root->right == NULL)
        {
            root = root->left;
            delete temp;
            return 1;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            root = root->right;
            delete temp;
            return 1;
        }
        else
        {
            int tempinfo = 0;
            temp2 = root->right;
            while(temp2->left != NULL)
                temp2 = temp2->left;
            tempinfo = temp2->info;
            prev_case = deleting(root , tempinfo);
            root->info = tempinfo;
        }
    }
    else
    {
        if(temp->info > info)
        {
            if(temp->left == NULL)
                    return 1;
            if(temp->left->info == info)
            {
                if(temp->left->left == NULL && temp->left->right == NULL)
                {
                    delete temp->left;
                    temp->left = NULL;
                }
                else if(temp->left->left == NULL && temp->left->right != NULL)
                {
                    node * temp2 = temp->left;
                    temp->left = temp2->right;
                    delete temp2;
                }
                else if(temp->left->left != NULL && temp->left->right == NULL)
                {
                    node * temp2 = temp->left;
                    temp->left = temp2->left;
                    delete temp2;
                }
                else
                {
                    int tempinfo = 0;
                    node * temp2 = temp->left->right;
                    while(temp2->left != NULL)
                        temp2 = temp2->left;
                    tempinfo = temp2->info;
                    prev_case = deleting(temp->left , tempinfo);
                    temp->left->info = tempinfo;
                }
            }
            else
            {
                prev_case = deleting(temp->left , info);
            }
        }
        else
        {
            if(temp->right->info == info)
            {
                if(temp->right == NULL)
                    return 1;
                if(temp->right->right == NULL && temp->right->left == NULL)
                {
                    delete temp->right;
                    temp->right = NULL;
                }
                else if(temp->right->right != NULL && temp->right->left == NULL)
                {
                    node * temp2 = temp->right;
                    temp->right = temp2->right;
                    delete temp2;
                }
                else if(temp->right->right == NULL && temp->right->left != NULL)
                {
                    node * temp2 = temp->right;
                    temp->right = temp2->left;
                    delete temp2;
                }
                else
                {
                    int tempinfo = 0;
                    node * temp2 = temp->right->right;
                    while(temp2->left != NULL)
                        temp2 = temp2->left;
                    tempinfo = temp2->info;
                    prev_case = deleting(temp->right , tempinfo);
                    temp->right->info = tempinfo;
                }
            }
            else
            {
                prev_case = deleting(temp->right , info);
            }
        }
    }
    if(prev_case == 1 || prev_case == 3)
        return 1;
    int BF = BalanceFactor(temp);
    if(BF == -1 || BF == 1)
        return 1;
    if(BF == 0)
        return 2;
    if(BF == -2)
    {
        int BF_Right_Subtree = BalanceFactor(temp->right);
        if(BF_Right_Subtree == 0)
        {
            RotateLeft(temp);
            return 3;
        }
        if(BF_Right_Subtree == -1)
        {
            RotateRight(temp->right);
            RotateLeft(temp);
            return 4;
        }
        else
        {
            RotateLeft(temp);
            return 5;
        }
    }
    else
    {
        int BF_Left_Subtree = BalanceFactor(temp->left);
        if(BF_Left_Subtree == 0)
        {
            RotateRight(temp);
            return 3;
        }
        if(BF_Left_Subtree == 1)
        {
            RotateLeft(temp->left);
            RotateRight(temp);
            return 4;
        }
        else
        {
            RotateRight(temp);
            return 5;
        }
    }
    return 1;
}

void AVL::in_ord_trav(node * temp)
{
    if(temp->left != NULL)
        in_ord_trav(temp->left);
    cout << temp->info << ' ';
    if(temp->right != NULL)
        in_ord_trav(temp->right);
}

int AVL::height(node * temp)
{
    int h_left = 0;
    int h_right = 0;
    if(temp->left != NULL)
    {
        h_left++;
        h_left += height(temp->left);
    }
    if(temp->right != NULL)
    {
        h_right++;
        h_right += height(temp->right);
    }
    if(h_left > h_right)
        return h_left;
    else
        return h_right;
}

int AVL::BalanceFactor(node * temp)
{
    int h_left = 0;
    int h_right = 0;
    if(temp->left != NULL)
    {
        h_left++;
        h_left += height(temp->left);
    }
    if(temp->right != NULL)
    {
        h_right++;
        h_right += height(temp->right);
    }
    return h_left - h_right;
}

void AVL::RotateLeft(node *& temp)
{
    node * temp2 = temp->right;
    temp->right = temp2->left;
    temp2->left = temp;
    temp = temp2;
}

void AVL::RotateRight(node *& temp)
{
    node * temp2 = temp->left;
    temp->left = temp2->right;
    temp2->right = temp;
    temp = temp2;
}

void AVL::Print_BF_All(node * temp)
{
    cout << "Balance Factor of" << temp->info << " is " << BalanceFactor(temp) << endl;
    if(temp->left != NULL)
        Print_BF_All(temp->left);
    if(temp->right != NULL)
        Print_BF_All(temp->right);
}




