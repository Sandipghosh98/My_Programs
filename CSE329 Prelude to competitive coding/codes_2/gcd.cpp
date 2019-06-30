#include<bits/stdc++.h>
using namespace std;
//eculid algorithm
int main()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int temp=a[0];

    for(i=1;i<n;i++)
    {
        temp=__gcd(temp,a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(temp==a[i])
        {
            cout<<"Yes "<<a[i]

            <<endl;
            return 0;
        }
    }
    cout<<"No "<<endl;
    return 0;
}

//Extended euclid algorithm

int main()
{
    int a,b;
    cout<<"Enter two number "<<endl;
    cin>>a>>b;
    cout<<"gcd of a "<<a<<" + "<<"b "<<b<<" = "<<__gcd(a,b)<<endl;
    return 0;
}
