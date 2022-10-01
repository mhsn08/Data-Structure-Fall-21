#include<iostream>

using namespace std;

struct node
{
    int info;
    node * left ,* right;
    bool left_thread , right_thread;
};

class TBT
{
    node * root;
    node * dummy;
    void inserting(int , node *);                   //I want to keep root Null that's why I am makinf two insert function
    void deleting(int , node *);
    int findingheight(node *);
public:
    TBT();
    void insertion(int);                            //This insert function will be called from main and this will call other insert funtion
    void in_order_traversal();
    node * find_sucessor(node *);
    void deletion(int);
    void height();
};

int main()
{
    TBT tree;
    tree.insertion(14);
    tree.insertion(4);
    tree.insertion(3);
    tree.insertion(9);
    tree.insertion(7);
    tree.insertion(5);
    tree.insertion(15);
    tree.insertion(18);
    tree.insertion(16);
    tree.insertion(20);
    tree.in_order_traversal();
    tree.height();
    return 0;
}

TBT::TBT()
{
    root = NULL;
    dummy = new node;
    dummy->left = dummy;
    dummy->right = dummy;
    dummy->left_thread = true;
    dummy->right_thread = false;
}

void TBT::insertion(int info)
{
    inserting(info , root);
}

void TBT::inserting(int info , node * temp)
{
    if(root == NULL)
    {
        root = new node;
        root->info = info;
        root->right = root->left = dummy;
        root->left_thread =  root->right_thread = true;
        dummy->left = root;
        dummy->left_thread = false;
        return;
    }
    while(true)
    {
        if(temp->info == info)
        {
            cout << "Duplication" << endl;
            return;
        }
        if(temp->info > info)
        {
            if(temp->left_thread == true)
            {
                node * temp2 = new node;
                temp2->info = info;
                temp2->left = temp->left;
                temp2->right = temp;
                temp->left = temp2;
                temp->left_thread = false;
                temp2->left_thread = temp2->right_thread = true;
                return;
            }
            else
                temp = temp->left;
        }
        else
        {
            if(temp->right_thread == true)
            {
                node * temp2 = new node;
                temp2->info = info;
                temp2->right = temp->right;
                temp2->left = temp;
                temp->right = temp2;
                temp->right_thread = false;
                temp2->left_thread = temp2->right_thread = true;
                return;
            }
            else
                temp = temp->right;
        }
    }
}

// void TBT::in_order_traversal()
// {
//     if(root == NULL)
//     {
//         cout << "Empty Tree!" << endl;
//         return;
//     }
//     node * temp = root;
//     while(temp->left != dummy)
//         temp = temp->left;
//     while (temp != dummy)
//     {
//         cout << temp->info << " ";
//         if(temp->right_thread == true)
//         {
//             temp = temp->right;
//             continue;
//         }
//         temp = temp->right;
//         while(temp->left_thread == false)
//             temp = temp->left;
//     }
// }

void TBT::in_order_traversal()
{
    if(root == NULL)
    {
        cout << "Empty tree" << endl;
        return;
    }
    node * temp = dummy->left;
    while (temp->left_thread == false)
        temp = temp->left;
    while(temp != dummy)
    {
        cout << temp->info << ' ';
        temp = find_sucessor(temp);
    }
}

node * TBT::find_sucessor(node * temp)
{
    if(temp->right_thread == true)
        return temp->right;
    temp = temp->right;
    while(temp->left_thread == false)
        temp = temp->left;
    return temp;
}

void TBT::deletion(int key)
{
    deleting(key , root);
}

void TBT::deleting(int key , node * temp)
{
    if(temp->info > key)
    {
        if(temp->left_thread == false)
        {
            if(temp->left->left_thread == true && temp->left->right_thread == true)
            {
                node * temp2 = temp->left->left;
                delete temp->left;
                temp->left = temp2;
                temp->left_thread = true;
                return;
            }
            else if((temp->left->left_thread == true && temp->left->right_thread == false) || (temp->left->left_thread == false && temp->left->right_thread == true))
            {
                if(temp->left->right_thread == true)
                {
                    node * temp2 = temp->left;
                }
            }
        }
        else
        {
            cout << "Invalid Key" << endl;
            return;
        }
    }
}

void TBT::height()
{
    cout << endl << findingheight(root) << endl;
}

int TBT::findingheight(node * temp)
{
    int h_left = 0;
    int h_right = 0;
    if(temp->left_thread == false)
    {
        h_left++;
        h_left += findingheight(temp->left);
    }
    if(temp->right_thread == false)
    {
        h_right++;
        h_right += findingheight(temp->right);
    }
    if(h_left > h_right)
        return h_left;
    else
        return h_right;
}



