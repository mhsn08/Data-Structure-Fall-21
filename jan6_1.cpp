#include<iostream>
using namespace std;

void revsent(string , int);
void revstring(string , int);

int main()
{
    string s = "";
    s+= "ABC";
    // cout << s << endl;
    revsent("It is Raining Today!" , 0);
    revstring("Hello" , 0);
    return 0;
}

void revsent(string sentence, int i)
{
    string s = "";
    while(sentence[i] != ' ')
    {
        if(sentence[i] == '\0')
            break;
        s += sentence[i];
        i++;
    }
    if(sentence[i] != '\0')
        revsent(sentence , i + 1);
    cout << s << " ";
}

void revstring(string sentence, int i)
{
    if(sentence[i] == '\0')
        return;
    revstring(sentence , i+1);
    cout << sentence[i];
}
