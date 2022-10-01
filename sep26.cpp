#include<iostream>

using namespace std;

class Array
{
    int * data;
    int size;
    int length;
public:
    Array(int);
    ~Array();
    void get(int);
    void update(int);
    void length();
    void back();
    void next();
    void start();
    void remove();
    void add();
};

int main()
{

    return 0;
}