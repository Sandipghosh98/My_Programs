#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int fib[100005],t,a,b;
    fib[0]=0;
    fib[1]=1;
    for(long long int i=2;i<=100005;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<fib[__gcd(a,b)]<<endl;
    }
    
   // cout<<__gcd(5,10);
    return 0;
}
