#include<iostream>

using namespace std;

struct node
{
    int info;
    node * right , * left;
};

class AVL
{
    node * root;
public:
    AVL();
    ~AVL();
    void insertion(int);
    void inserting(int , node *&);                          //I wanted to make Root Private thats why I need two funs for deleting and Inserting
    void removeall(node * = NULL);
    void in_order_traversal(node * = NULL);
    void remove(int);
    int removing(int , node *&);
    int BalanceFactor(node * = NULL);
    int Height(node * = NULL);
    void RotateRight(node *&);
    void RotateLeft(node *&);
};

int main()
{
    cout << "Case 1. Parent Node Is Balanced" << endl;
    AVL tree1;
    tree1.insertion(50);
    tree1.insertion(40);
    tree1.insertion(60);
    tree1.insertion(30);
    tree1.insertion(45);
    tree1.insertion(55);
    tree1.insertion(65);
    tree1.insertion(10);
    tree1.insertion(35);
    tree1.in_order_traversal();
    cout << endl;
    tree1.remove(10);
    tree1.in_order_traversal();
    cout << endl;
    cout << "\nCase 2. Parent Node having BF of 1 or -1 and after Deletion it gets 0" << endl;
    AVL tree2;
    tree2.insertion(50);
    tree2.insertion(40);
    tree2.insertion(60);
    tree2.insertion(30);
    tree2.insertion(45);
    tree2.insertion(55);
    tree2.insertion(65);
    tree2.insertion(35);
    tree2.in_order_traversal();
    cout << endl;
    tree2.remove(35);
    tree2.in_order_traversal();
    cout << endl;
    cout << "\nCase 3. Parent Node having Balance of -1 or +1. After Deletion it gets +2 or -2. Its left or Right Subtree is Balanced" << endl;
    AVL tree3;
    tree3.insertion(70);
    tree3.insertion(40);
    tree3.insertion(85);
    tree3.insertion(30);
    tree3.insertion(50);
    tree3.insertion(75);
    tree3.insertion(86);
    tree3.insertion(45);
    tree3.insertion(55);
    tree3.in_order_traversal();
    cout << endl;
    tree3.remove(30);
    tree3.in_order_traversal();
    cout << endl;
    cout << "\nCase 4. Parent Node having Balance of -1 or +1.\nAfter Deletion it gets +2 or -2.\nIts left or Right Subtree had the balance opposite to the Parent Tree of deleted node\ne.g if Parent Had balance of +1,Its Right Subtree has balance of -1" << endl;
    AVL tree4;
    tree4.insertion(70);
    tree4.insertion(40);
    tree4.insertion(85);
    tree4.insertion(30);
    tree4.insertion(50);
    tree4.insertion(75);
    tree4.insertion(86);
    tree4.insertion(45);
    tree4.in_order_traversal();
    cout << endl;
    tree4.remove(30);
    tree4.in_order_traversal();
    cout << endl;
    cout << "\nCase 5. Parent Node having Balance of -1 or +1.\nAfter Deletion it gets +2 or -2.\nIts left or Right Subtree had the balance same to the Parent Tree of deleted node\ne.g if Parent Had balance of +1,Its Right Subtree has balance of +1" << endl;
    AVL tree5;
    tree5.insertion(70);
    tree5.insertion(40);
    tree5.insertion(85);
    tree5.insertion(30);
    tree5.insertion(50);
    tree5.insertion(75);
    tree5.insertion(86);
    tree5.insertion(55);
    tree5.in_order_traversal();
    cout << endl;
    tree5.remove(30);
    tree5.in_order_traversal();
    cout << endl;
    return 0;
}

AVL::AVL()
{
    root = NULL;
}

AVL::~AVL()
{
    removeall();
}

void AVL::insertion(int key)
{
    inserting(key , root);
}

void AVL::inserting(int key , node *& temp)
{
    if(root == NULL)
    {
        root = new node;
        root->right = root->left = NULL;
        root->info = key;
        return;
    }
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
            temp->left->left = temp->left->right = NULL;
            temp->left->info = key;
            return;
        }
        else
        {    
            inserting(key , temp->left);
        }
    }
    else
    {
        if(temp->right == NULL)
        {
            temp->right = new node;
            temp->right->left = temp->right->right = NULL;
            temp->right->info = key;
            return;
        }
        else
        {
            inserting(key, temp->right);
        }
    }
    int BF = BalanceFactor(temp);
    if(BF == 2)
    {   
        if(key < temp->left->info)
        {
            RotateRight(temp);
        }
        else
        {
            RotateLeft(temp->left);
            RotateRight(temp);
        }
    }
    if(BF == -2)
    {
        if(key > temp->right->info)
        {
            RotateLeft(temp);
        }
        else
        {
            RotateRight(temp->right);
            RotateLeft(temp);
        }
    }
}

void AVL::remove(int info)
{
    removing(info , root);
}

int AVL::removing(int info,node *& temp)
{
    if(root == NULL)
    {
        cout << "Empty Tree!" << endl;
        return 0;
    }
    int prev_BF;
    int prev_case = 0;
    node * temp1 = NULL;
    if(root->info == info)
    {
        temp1 = root;
        if(root->right == NULL)
        {
            root = root->left;
            delete temp1;
            return 0;
        }
        if(root->left == NULL)
        {
            root = root->right;
            delete temp1;
            return 0;
        }
        temp1 = root->right;
        if(temp1->left == NULL)
        {
            root->right = temp1->right;
            delete temp1;
        }
        else{
            while(temp1->left != NULL)
                temp1 = temp1->left;
            root->info = temp1->info;
            prev_case = removing(temp->info , root->right);             //Because the actual node that's going to be deleted is sucessor of node
        }
    }
    else{
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
                    }
                    else if((temp->left->left == NULL && temp->left->right != NULL) || (temp->left->left != NULL && temp->left->right == NULL))
                    {
                        temp1 = temp->left;
                        if(temp1->left == NULL)
                            temp->left = temp1->right;
                        else
                            temp->left = temp1->left;
                        delete temp1;
                    }
                    else
                    {
                        temp1 = temp->left->right;
                        while(temp1->left != NULL)
                            temp1 = temp1->left;
                        int tempinfo = temp1->info;
                        prev_case = removing(temp1->info , temp->left);             //Because the actual node that's going to be deleted is sucessor of node
                        temp->left->info = tempinfo;
                    }
                }
                else
                {
                    prev_case = removing(info,temp->left);
                }
            }
            else
            {
                cout << "Nothing to delete!" << endl;
                return 1;
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
                    }
                    else if((temp->right->left == NULL && temp->right->right != NULL) || (temp->right->left != NULL && temp->right->right == NULL))
                    {
                        temp1 = temp->right;
                        if(temp1->left == NULL)
                            temp->right = temp1->right;
                        else
                            temp->right = temp->left;
                        delete temp1;
                    }
                    else
                    {
                        temp1 = temp->right->right;
                        while(temp1->left != NULL)
                            temp1 = temp1->left;
                        int tempinfo = temp1->info;
                        prev_case = removing(temp1->info , temp->right);                //Because the actual node that's going to be deleted is sucessor of node
                        temp->right->info = tempinfo;
                    }
                }
                else
                {
                    prev_case = removing(info , temp->right);
                }
            }
            else
            {
                cout << "Nothing to Delete!" << endl;
                return 1;
            }
        }
    }
    if(prev_case == 1 || prev_case == 3)
        return 1;
    int BF = BalanceFactor(temp);
    if(BF == 1 || BF == -1)
        return 1;
    if(BF == 0)
        return 2;
    if(BF == -2)
    {
        int BF_right_subtree = BalanceFactor(temp->right);
        if(BF_right_subtree == 0)
        {
            RotateLeft(temp);
            return 3;
        }
        if(BF_right_subtree == 1)
        {
            RotateRight(temp->right);
            RotateLeft(temp);
            return 4;
        }
        if(BF_right_subtree == -1)
        {
            RotateLeft(temp);
            return 5;
        }
    }
    if(BF == 2)
    {
        int BF_left_subtree = BalanceFactor(temp->left);
        if(BF_left_subtree == 0)
        {
            RotateRight(temp);
            return 3;
        }
        if(BF_left_subtree == -1)
        {
            RotateLeft(temp->left);
            RotateRight(temp);
            return 4;
        }
        if(BF_left_subtree == 1)
        {
            RotateRight(temp);
            return 5;
        }
    }
    return 0;                       //This has no meaning. There was just some warning(NOT ERROR) that it might reach here at non returning function but it won't because there are always one of these 5 cases
}

int AVL::BalanceFactor(node * temp)
{
    if(temp == NULL)
        return 0;
    int l_subtree =  0;
    int r_subtree = 0;
    if(temp->left != NULL)
    {
        l_subtree++;
        l_subtree +=  Height(temp->left);
    }
    if(temp->right != NULL)
    {
        r_subtree++;
        r_subtree +=  Height(temp->right);
    }

    return l_subtree - r_subtree;
}

int AVL::Height(node * temp)
{
    if(temp == NULL)
        return 0;
    int count_r = 0;
    int count_l = 0;
    if(temp->left != NULL)
    {
        count_l++;
        count_l += Height(temp->left);
    }
    if(temp->right != NULL)
    {
        count_r++;
        count_r += Height(temp->right);
    }
    if(count_r > count_l)
        return count_r;
    else
        return count_l;
}

void AVL::RotateRight(node *& temp)
{
    node * temp2 = temp->left;
    temp->left = temp2->right;
    temp2->right = temp;
    temp = temp2;
}

void AVL::RotateLeft(node *& temp)
{
    node * temp2 = temp->right;
    temp->right = temp2->left;
    temp2->left = temp;
    temp = temp2;
}

void AVL::removeall(node * temp)
{
    if(temp == NULL)
        temp = root;
    if(temp->left != NULL)
        removeall(temp->left);
    if(temp->right != NULL)
        removeall(temp->right);
    delete temp;
}

void AVL::in_order_traversal(node * temp)
{
    if(root == NULL)
    {
        cout << "Empty List" << endl;
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


