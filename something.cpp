#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct node
{
    string data;
    node * next;
};

struct list
{
    node * start;
    list * next;
};

class TransactionLL
{
    list * head;
    list * temp;
    list * temp1;
public:
    TransactionLL();
    ~TransactionLL();
    void insertlist();
    void insertdata(string data);
    void print();
};

void readInputFile (string inputFilePath);
void generateFirstItemSet(string LL_frequency);
void generateSecondItemSet(string frequency_outputfile);
void generateThirdItemSet(string frequency_outputfile);

int main()
{
    readInputFile("GroceryStore.txt");
    return 0;
}

TransactionLL::TransactionLL()
{
    head = temp = temp1 = NULL;
}

TransactionLL::~TransactionLL()
{
    if(head == NULL)
        return;
    while(head != NULL)
    {
        node * tempnode;
        while(head->start != NULL)
        {
            tempnode = head->start;
            head->start = head->start->next;
            delete tempnode;
        }
        temp = head;
        head = head->next;
        delete temp;
    }
    head = temp = temp1 = NULL;
}

void TransactionLL::insertlist()
{
    temp1 = new list;
    temp1->start = NULL;
    temp1->next = NULL;
    if(head == NULL)
    {
        head = temp1;
        return;
    }
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = temp1;
}

void TransactionLL::insertdata(string data)
{
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    node * tempnode;
    tempnode = temp->start;
    if(tempnode == NULL)
    {
        tempnode = new node;
        tempnode->data = data;
        tempnode->next = NULL;
        temp->start = tempnode;
        return;
    }
    while(tempnode->next != NULL)
        tempnode = tempnode->next;
    tempnode->next = new node;
    tempnode = tempnode->next;
    tempnode->data = data;
    tempnode->next = NULL;
}

void TransactionLL::print()
{
    if(head == NULL)
    {
        cout << "L1 = []" << endl;
        return;
    }
    int i = 1;
    temp = head;
    node * tempnode;
    while (temp != NULL)
    {
        cout << "L" << i << " = [ ";
        tempnode = temp->start;
        while (tempnode != NULL)
        {
            cout << tempnode->data;
            if(tempnode->next != NULL)
            {
                cout << " , ";
            }
            tempnode = tempnode->next;
        }
        cout << " ]" << endl;
        i++;
        temp = temp->next;
    }
}

void readInputFile (string inputFilePath)
{
    ifstream fin;
    fin.open(inputFilePath);
    string line;
    string data;
    TransactionLL l1;
    while(fin)
    {
        getline(fin,line);
        l1.insertlist();
        for(int i = 0;i < line.length();i++)
        {
            if(line[i] == ',')
            {
                l1.insertdata(data);
                data = "";
                continue;
            }
            data += line[i];
        }
        l1.insertdata(data);
        data = "";
    }
    l1.print();
}