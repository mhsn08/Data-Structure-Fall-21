#include<iostream>

using namespace std;

struct node
{
    char info[15];
};

class trial
{
private:
    node obj1, *temp1, *temp2, *temp3;
    int I,length;
    char *p, *q;
public:
    trial();
    ~trial();
    void startin();
};

int main()
{
    trial lnk;
    lnk.startin();
    return 0;
}

trial::trial()
{
    temp1 = temp2 = temp3 = NULL;
    q = p = NULL;
}

trial::~trial()
{
    delete temp1, temp2, temp3;
    delete [] p;
}

void trial::startin()
{
    cout << "\nUsing Delete and New" << endl;
    temp1 = new node;
    temp2 = new node;
    cout << "Enter for temp1 : ";
    cin >> temp1->info;
    cout << "Enter for temp2 : ";
    cin >> temp2->info;
    temp3 = &obj1;
    cout << "Enter for temp3 : ";
    cin >> temp3->info;
    cout << "Temp1 = " << temp1->info << endl;
    cout << "Temp2 = " << temp2->info << endl;
    cout << "Temp3 = " << temp3->info << endl;
    cout << endl << endl;
    cout << "Enter length of array : ";
    cin >> length;
    p = new char[length];
    q = p;
    cout << "Fill :" << endl;
    for(int i = 0; i < length; i++){
        cin >> *p;
        p = p + 1;
    }
    p = q;
    for(int i = 0; i < length; i++){
        cout << *p << endl;
        p = p + 1;
    }
    p = q;
}