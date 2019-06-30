3// Queue Template Class.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int>Q;
    stack<int>S;
    for(int i=1;i<=10;i++)
        Q.push(i);
    while(!Q.empty()) {
        S.push(Q.front());
        Q.pop();
    }
    while(!S.empty()) {
        Q.push(S.top());
        S.pop();
    }
    while(!Q.empty()) {
        cout<<Q.front()<<"\n";
        Q.pop();
    }
    cout<<"Size : "<<Q.size()<<endl;
}
