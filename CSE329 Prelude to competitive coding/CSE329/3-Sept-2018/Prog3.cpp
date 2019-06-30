// WAP to reverse a queue using recursion.
#include<bits/stdc++.h>
using namespace std;
int dequeuerec(queue<int>&Q)
{
    int temp = Q.front();
    Q.pop();
    if(Q.empty()) {
        Q.push(temp);
        return 0;
    }
    else {
        dequeuerec(Q);
        Q.push(temp);
    }
}
int main()
{
    queue<int>Q;
    for(int i=1;i<=10;i++) {
        Q.push(i);
    }

    dequeuerec(Q);
    
    while(!Q.empty()) {
        cout<<Q.front()<<"\n";
        Q.pop();
    }
}