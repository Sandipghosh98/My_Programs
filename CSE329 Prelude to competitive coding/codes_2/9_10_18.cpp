#include<bits/stdc++.h>
using namespace std;
//smooth number program(solved :) )
/*
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
int large_prime(int n)
{
    for(int i=n;i>=2;i--)
    {
        if(n%i==0 && isprime(i)==true)
        {
            return i;
        }
    }
    return 0;
}
int check(int n,int p)
{
    int x=large_prime(n);
   // cout<<"largest prime n in check function is   "<<x<<endl;
    if(x>=p)
        return 1;
    else
        return 0;
}
int main()
{
    int n=100,i,j,a[100],p,x,y,q;
    cout<<"enter value of P for p smooth number "<<endl;
    cin>>p;
    for(i=1;i<=100;i++)
    {
        a[i]=check(i,p);
    }
    //cout<<"array is "<<endl;
    /*for(i=1;i<=100;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;*/
    cout<<"enter number of queries "<<endl;
    cin>>q;
    while(q--)
    {
        cout<<endl<<"enter staring index and ending index"<<endl;
        cin>>x>>y;
        int counter=0;
        for(i=x;i<=y;i++)
        {
            if(a[i]==1)
            {
                cout<<i<<" ";
                counter++;
            }
        }
        cout<<"number of p smooth number is "<<counter<<endl;
    }
    return 0;
}*/
//Lemoine's conjection   any number grater than 5 can be represented as sum of prime number +semi prime number(even*odd)

int main()
{
    int n,i,j;
    cin>>n;
    vector<int>v ;
    prime(v,n);
    for(i=0;i<v.size();i++)
    {
        int m=
    }


    return 0;
}

