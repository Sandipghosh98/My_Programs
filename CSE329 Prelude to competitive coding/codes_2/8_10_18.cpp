#include<bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int genrate_prime(int n)
{
    int i=2;
    while(true)
    {
        if(isprime(i)==true && n%i==0)
        {
            return i;
        }
        i++;
    }
}
int main()
{
    cout<<"main"<<endl;
    int k=4,i=1,counter=0;

    while(counter<10)
    {
        cout<<"inside this "<<endl;
        int x=genrate_prime(i);
        if(x>=k)
        {
            cout<<i<<" ";
            counter++;
        }

        i++;
    }

    return 0;
}
