#include<iostream>
using namespace std;
void perculatedown(int *a, int p);
int main(){

int a[16] ={0 , 65 , 31 , 32 , 26 , 21 , 19 , 68 , 13 , 24 , 15 , 14 , 16 , 5 , 70 , 12}; 
int size = 16-1;


cout<<"simple cbt"<<endl;
for (int i = 1; i <= size; i++)
{
    cout<<a[i]<<" ";
}
cout<<endl;
for (int p = size/2; p > 0 ; p--)
{
    perculatedown(a,p);
}

cout<<"MIN heap"<<endl;

for (int i = 1; i <= size; i++)
{
    cout<<a[i]<<" ";
}

}
void perculatedown(int *a, int p){
    int size = 16-1;
    int l,r;
    int swap;
    l = 2*p;
    r = 2*p+1;
    if(r <= size)
        if(a[p] > a[r])
        {
             swap = a[p];
            a[p] = a[r];
            a[r] = swap;
            if( r <= size/2)
                perculatedown(a, r);

        }
    if(l <= size){
         if (a[p]> a[l])
        {
            swap = a[p];
            a[p] = a[l];
            a[l] = swap;
            if( l <= size/2)
               perculatedown(a, l);
        }
    }
    


}