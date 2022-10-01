#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    // int *ptr = new int;
    char *namee = new char[8];
    strcpy(namee,"DataStructure");
    // for(int i = 0; i < 13; i++)
    //     cout << *(namee + i);
    // cout << endl;
    cout << namee << endl;
    delete [] namee;
    return 0;
}