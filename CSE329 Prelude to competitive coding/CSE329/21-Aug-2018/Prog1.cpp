// Stack Using Stadard Template Library.

#include<iostream>
#include<stack> // STL
using namespace std;

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()) {
        cout<<s.top()<<"\n";
        s.pop();
    }
}