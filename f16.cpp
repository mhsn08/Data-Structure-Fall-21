#include<iostream>
using namespace std;

struct node
{
    int info;
    node * next;
    node * prev;
};

void reverse_list(node * head)
{
    head->prev->next = NULL;
    head->prev = NULL;
    node * temp1 = NULL;
    node * temp = head->next;
    while (temp!= NULL)
    {
        head->next = temp1;
        head->prev = temp;
        temp1 = head;
        head = temp;
        temp = temp->next;
    }
    head->next = temp1;
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    head->prev = temp;
    temp->next = head;
}

void which_pointer(node * head ,node * temp , int info, bool if_key_found , int count)
{
    if(head->info == info)
    {
        cout << "Both same";
        return;
    }
    if(temp->info == info)
        if_key_found = true;
    if(if_key_found)
        count--;
    else
        count++;
    temp = temp->next;
    if(temp == head)
    {
        if(if_key_found)
        {
            if(count == 0)
                cout << "Same";
            else if (count > 0)
            {
                cout << "Prev Fast";
            }
            else
                cout << "Forward Fast";
        }
        else
            cout << "Invalid Key";
        return;
    }
    which_pointer(head ,temp->next , info , if_key_found , count);
}

bool if_palindrome(char * a , char * b , int upto , int size)
{
    if(*a == *b)
    {
        if(upto == size)
            return true;
        else
            return if_palindrome(a+1 , b-1 , upto + 1 , size);
    }
    else
        return false;
}

void Palindrome(char * name)
{
    int size = 0;
    while (*(name + size) != '\0')
    {
        size++;
    }    
    char * a = name;
    char * b = (name + size - 1);
    if(if_palindrome(a , b , 1 , size))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

void sumseries()
{
    int n = 0;
    cout << "ENter Length of Series(We won't take input unless size is atleast 3): ";
    while (n > 3)
    {
        cin >> n;
    }
    int * series = new int[n];
    cout << "Enter 1st num: ";
    cin >> series[0];
    cout << "Enter 1st num: ";
    cin >> series[1];
    cout << "Enter 1st num: ";
    cin >> series[2];
    for(int i = 3; i < n; i++)
    {
        series[i] = series[i - 1] + series[i - 2] + series[i - 3];
    }
}

void check_even_odd(int * arr , int size)
{
    int odd = 0;
    int even = 0;
    int neither = 0;
    for(int i = 0; i < size; i++)
    {
        if((i+1) % 2 == 0)                          // 0th Index is odd in normal list
        {
            if(*(arr + i) % 2 == 0)
                even++;
            else
                neither++;
        }
        else
        {
            if(*(arr + i) % 2 != 0)
                odd++;
            else
                neither++;
        }
    }
    cout << "Odds in odd position: " << odd << endl;
    cout << "Even in even position: " << even << endl;
    cout << "Neither Fulfilling: " << neither << endl;
}

void repeated_elements(node * head)
{
    node * temp = head;
    node * temp2 = temp->next;
    node * temp3;
    int repeated = 0;
    bool already_processed = false;
    while(temp != NULL)
    {
        temp3 = head;
        while(temp3 != temp)
        {
            if(temp3->info == temp->info)
                already_processed = true;
        }
        if(already_processed)
        {
            already_processed = false;
            temp = temp->next;
            continue;
        }
        temp2 = temp->next;
        while (temp2 != NULL)
        {
            if(temp2->info == temp->info)
                repeated++;
            break;
        }
        temp = temp->next;
    }
}



int main()
{
    int arr [] = {1,2,4,7};
    check_even_odd(arr , 4);
    return 0;
}