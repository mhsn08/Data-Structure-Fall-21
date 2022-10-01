#include<iostream>
using namespace std;

class tollbooth
{
    int num_cars;
    double amount;
public:
    void setDataMembers()
    {
        num_cars = 0;
        amount = 0;
    }
    void payingCar()
    {
        num_cars++;
        amount += 50;
    }
    void nopayCar()
    {
        num_cars++;
    }
    void display()
    {
        cout << "Number of cars that paid = " << amount / 50 << endl;
        cout << "Number of cars that didn't paid = " << num_cars - (amount / 50) << endl;
        cout << "Amount Collected = " << amount << endl;
    }
};

int main()
{
    tollbooth test;
    test.setDataMembers();
    int inp;
    while(true)
    {
        cout << "1 for Paying car" << endl;
        cout << "2 for non Paying car" << endl;
        cout << "3 for Display" << endl;
        cin >> inp;
        if(inp == 1)
            test.payingCar();
        else if(inp == 2)
            test.nopayCar();
        else if(inp == 3)
            test.display();
        else
            break;
    }
    return 0;
}