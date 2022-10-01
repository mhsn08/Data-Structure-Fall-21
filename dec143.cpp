#include<iostream>

using namespace std;

struct node
{
    int info;
    node * right , * left;
};

class BST
{
    bool if_exists;
public:
    node * root;
    BST();
    ~BST();
    void insertion(int , node * = NULL);
    void removeall(node * = NULL);
    node * search(int , node * = NULL);
    void in_order_traversal(node * = NULL);
    void remove(int , node * = NULL);
    void find_sucessor(int);
    node * finding_sucessor(node * , int , node *);
    node * parent_sucessor(node * , int);
    void find_predessor(node *);
    node * parent_predessor(node * , int);
    bool check_if_binary(node *);
    int height(node *);
    int sum_all_node(node * , int = 0);
    void least_common_sucessor(int , int);
    node * LCS(node * , int , int , node *);
    void cousins(node * , node *);
    node * parent(node * , node *);
    void sum_max_root_leaf();
    int sum_max(node *);
    void del_les(int);
    void summed_upto(node *& , int , int);
    int same_num_nodes(node *);
    int check_nums(node *);
};

int main()
{
    BST tree;
    tree.insertion(4);
    tree.insertion(3);
    tree.insertion(8);
    tree.insertion(6);
    tree.insertion(2);
    tree.insertion(1);
    tree.insertion(7);
    tree.insertion(5);
    tree.in_order_traversal();
    cout << endl;
    // node * temp = tree.search(67);
    // tree.find_sucessor(temp);
    // cout << tree.height(tree.root) << endl;
    // cout << tree.sum_all_node(tree.root) << endl;
    // tree.least_common_sucessor(67 , 120);
    // tree.find_sucessor(122);
    // node * temp1 = tree.search(70);
    // node * temp2 = tree.search(122);
    // tree.cousins(temp1 , temp2);
    // tree.sum_max_root_leaf();
    // tree.del_les(20);
    // tree.in_order_traversal();
    // cout << endl;

    return 0;
}

BST::BST()
{
    if_exists = false;
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

// void BST::find_sucessor(node * temp)
// {
//     node * temp1 = temp->right;
//     if(temp->right != NULL)
//     {
//         while(temp1->left != NULL)
//             temp1 = temp1->left;
//         cout << temp1->info << endl;
//     }
//     else
//     {
//         temp1 = parent_sucessor(root , temp->info);
//         if(temp1 != NULL)
//             cout << temp1->info << endl;
//         else
//             cout << "No Sucessor" << endl;
//     }
// }

// node * BST::parent_sucessor(node * temp , int key)
// {
//     if(temp == NULL)
//         return NULL;
//     if(temp->info == key)
//         return NULL;
//     node * temp1 = NULL;
//     if(temp->info > key)
//     {
//         temp1 = parent_sucessor(temp->left , key);
//         if(temp1 != NULL)
//             temp = temp1;
//     }
//     else
//     {
//         temp1 = parent_sucessor(temp->right , key);
//         if(temp1 != NULL)
//             temp = temp1;
//     }
//     if(temp->info > key)
//         return temp;
//     else
//         return NULL;
// }

bool BST::check_if_binary(node * temp)
{
    bool binary = true;
    if(temp->left != NULL)
    {
        if(temp->left->info < temp->info)
        {
            binary = check_if_binary(temp->left);
        }
        else
            return false;
    }
    if(temp->right != NULL)
    {
        if(temp->right->info > temp->info)
            binary = check_if_binary(temp->right);
        else
            return false;
    }
    return binary;
}

void BST::find_predessor(node * temp)
{
    node * temp2 = NULL;
    if(temp->left != NULL)
    {
        temp2 = temp->left;
        while(temp2->right != NULL)
            temp2 = temp2->right;
        cout << temp2->info << endl;
        return;
    }
    temp2 = parent_predessor(root , temp->info);
    if(temp2 != NULL)
        cout << temp2->info << endl;
    else
        cout << "No Predessor" << endl;
}

node * BST::parent_predessor(node * temp , int key)
{
    if(temp->info == key)
        return NULL;
    node * temp2 = NULL;
    if(temp->info > key)
    {
        temp2 = parent_predessor(temp->left , key);
        if(temp2 != NULL)
            temp = temp2;
    }
    else
    {
        temp2 = parent_predessor(temp->right , key);
        if(temp2 != NULL)
            temp = temp2;
    }
    if(temp->info < key)
        return temp;
    else
        return NULL;
}

int BST::height(node * temp)
{
    int count_l = 0;
    int count_r = 0;
    if(temp->left != NULL)
    {
        count_l++;
        count_l += height(temp->left);
    }
    if(temp->right != NULL)
    {
        count_r++;
        count_r += height(temp->right);
    }
    if(count_l > count_r)
        return count_l;
    else
        return count_r;
}

int BST::sum_all_node(node * temp , int sum)
{
    sum += temp->info;
    if(temp->left != NULL)
        sum = sum_all_node(temp->left , sum);
    if(temp->right != NULL)
        sum = sum_all_node(temp->right , sum);
    return sum;
}

void BST::least_common_sucessor(int key1 , int key2)
{
    node * temp = LCS(root , key1 , key2 , NULL);
    if(temp != NULL)
        cout << temp->info << endl;
    else
        cout << "No Least Sucessor" << endl;
}

node * BST::LCS(node * temp , int key1 , int key2 , node * current)
{
    if(temp->info > key1 && temp->info > key2)
    {
        if(current != NULL)
        {
            if(current->info > temp->info)
                current = temp;
        }
        else
            current = temp;
    }
    node * temp2 = NULL;
    if(temp->left != NULL)
    {
        temp2 = LCS(temp->left , key1 , key2 , current);
        if(temp2 != NULL)
            current = temp2;
    }
    if(temp->right != NULL)
    {
        temp2 = LCS(temp->right , key1 , key2 , current);
        if(temp2 != NULL)
            current = temp2;
    }
    return current;
}

void BST::find_sucessor(int key)
{
    if(root == NULL)
    {
        cout << "Empty tree" << endl;
        return;
    }
    if_exists = false;
    node * temp = finding_sucessor(root , key , NULL);
    if(if_exists)
    {
        if(temp != NULL)
           cout << temp->info << endl;
        else
            cout << "No sucessor";
    }
    else
        cout << "Invalid Key" << endl;
}

node * BST::finding_sucessor(node * temp , int key , node * current)
{
    if(temp->info > key)
    {
        if(current != NULL)
        {   
            if(current->info > temp->info)
                current = temp;
        }
        else
            current = temp;
    }
    if(key == temp->info)
    {
        if_exists = true;
    }
    node * temp2 = NULL;
    if(temp->left != NULL)
    {
        temp2 = finding_sucessor(temp->left , key , current);
        if(temp2 != NULL)
            current = temp2;
    }
    if(temp->right != NULL)
    {
        temp2 = finding_sucessor(temp->right , key , current);
        if(temp2 != NULL)
            current = temp2;
    }
    return current;
}

void BST::cousins(node * temp1 , node * temp2)
{
    if(temp1 == root || temp2 == root)
    {
        cout << "No" << endl;
        return;
    }
    node * temp1_parent = parent(root , temp1);
    node * temp2_parent = parent(root , temp2);
    if(temp1_parent == temp2_parent)
    {
        cout << "No" << endl;
        return;
    }
    node * temp1_parent_grandparent = parent (root , temp1_parent);
    node * temp2_parent_grandparent = parent (root , temp2_parent);
    if(temp1_parent_grandparent == temp2_parent_grandparent)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

node * BST::parent(node * temp , node * child)
{
    if(temp->left == child || temp->right == child)
        return temp;
    node * temp2 = NULL;
    if(temp->left != NULL)
    {
        temp2 = parent(temp->left , child);
        if(temp2 != NULL)
            return temp2;
    }
    if(temp->right != NULL)
    {
        temp2 = parent(temp->right , child);
    }
    return temp2;
}

void BST::sum_max_root_leaf()
{
    int sum = sum_max(root);
    cout << sum << endl;
}

int BST::sum_max(node * temp)
{
    int sum = temp->info;
    int s_left = 0;
    int s_right = 0;
    if(temp->left != NULL)
    {
        s_left += sum_max(temp->left);
    }
    if(temp->right != NULL)
    {
        s_right = sum_max(temp->right);
    }
    if(s_left > s_right)
        return sum + s_left;
    else
        return sum + s_right;
}

void BST::del_les(int key)
{
    summed_upto(root , key , 0);
}

void BST::summed_upto(node *& temp , int key , int summed)
{
    summed += temp->info;
    if(temp->left != NULL)
    {
        summed_upto(temp->left , key , summed);
    }
    if(temp->right != NULL)
    {
        summed_upto(temp->right , key , summed);
    }
    if(temp->left == NULL && temp->right == NULL)
    {
        if(summed <= key)
        {
            delete temp;
            temp = NULL;
        }
    }
}

int BST::same_num_nodes(node * temp)
{
    
}











