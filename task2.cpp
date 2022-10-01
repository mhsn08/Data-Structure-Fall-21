#include<iostream>
using namespace std;

class Laptop
{
    string Brand;
    string Model;
    int Serial;
    string Color;
    float Price;
    float ProcessorSpeed;
    int Ram;
    float ScreenSize;
public:
    void setValues()
    {
        cout << "Brand: ";
        cin >> Brand;
        cout << "Model: ";
        cin >> Model;
        cout << "Serial: ";
        cin >> Serial;
        cout << "Color: ";
        cin >> Color;
        cout << "Price: ";
        cin >> Price;
        cout << "Processor Speed: ";
        cin >> ProcessorSpeed;
        cout << "Ram: ";
        cin >> Ram;
        cout << "Screen Size: ";
        cin >> ScreenSize;
    }
    void upgradeRam()
    {
        cout << "Ram: ";
        cin >> Ram;
    }
    void Display()
    {
        cout << "Brand: " << Brand << endl;
        cout << "Model: " << Model <<  endl;
        cout << "Serial: " << Serial << endl;
        cout << "Color: " << Color << endl;
        cout << "Price: " << Price << endl;
        cout << "Processor Speed: " << ProcessorSpeed << endl;
        cout << "Ram: " << Ram << endl;
        cout << "Screen Size: " << ScreenSize << endl;
    }
};

int main()
{
    Laptop test;
    test.setValues();
    int inp;
    while(true)
    {
        cout << "1 for setting Values" << endl;
        cout << "2 for Upgrading Ram" << endl;
        cout << "3 for Display" << endl;
        cin >> inp;
        if(inp == 1)
            test.setValues();
        else if(inp == 2)
            test.upgradeRam();
        else if(inp == 3)
            test.Display();
        else
            break;
    }
    return 0;
}