#include<iostream>
#include <typeinfo>
using namespace std;

class Number
{
    float num;
    int result;
public:
    bool if_float();
    bool if_positive();
    int cal_factorial();
    void display();
    void takeinp();
};

int main()
{
    float num = 1;
    num = 2;
    cout << typeid(num).name() << endl;
    return 0;
}