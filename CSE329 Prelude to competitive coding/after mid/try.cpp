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
    int i=n;
    while(n>1)
    {
        if(isprime(i)==true && n%i==0)
        {
            return i;
        }
        i--;
    }
}


int main()
{
int c=genrate_prime(5);
cout<<c;
}
