#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a==0)    return b;
    return gcd(b%a,a);
}

int main()
{
    int a[]={2,4,6}, x=sizeof(a)/sizeof(a[0]);

    int first=a[0], ans=-1;

    for(int i=0;i<x;i++)
        first = gcd(first,a[i]);

    for(int i=0;i<x;i++)
        if(first==a[i]) {
            ans = first;
            break;
        }
    cout<<ans<<endl;
}