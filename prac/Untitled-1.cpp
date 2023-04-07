#include<iostream>
using namespace std;

int recursion(int x)
{
    while (x<10)
    {
        x=recursion(x+2);
       
        cout<<x<<" ";
    }
    
}
int main()
{
recursion(2);

}