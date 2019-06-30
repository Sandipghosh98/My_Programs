#include<bits/stdc++.h>
using namespace std;
void dp(int n)
{
    int a[n+1];
    a[0]=1;
    a[1]=1;
    if(n==1 || n==0)
    {
        cout<<0<<endl;
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];

    }
    cout<<a[n]<<endl;
}
int main()
{
    int n;
    cin>>n;
    dp(n);


    return 0;
}
