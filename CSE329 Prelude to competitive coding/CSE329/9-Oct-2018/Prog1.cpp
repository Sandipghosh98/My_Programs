// WAP to print 7-Smooth or 7-Friable NUmbers. n is a p-smooth number if LargestPrimeFactor(n) <= p.
#include<bits/stdc++.h>
using namespace std;

int LPF(int num)
{
    int lpf=0;
    while(num%2==0) {
        lpf=2;
        num/=2;
    }

    for(int i=3;i*i<=num;i+=2)
    {
        while(num%i==0) {
            lpf=i;
            num/=i;
        }
    }
    if(lpf==0)  lpf=num;
    return lpf;
}

bool isSmoothNum(int num,int p)
{
    if(LPF(num)<=p) return true;
    else    return false;
}

int main()
{
    int a=1,b=100;
    for(int i=a;i<=b;i++)
    {
        //cout<<LPF(i)<<":"<<isSmoothNum(i)<<endl;
        if(isSmoothNum(i,7))  cout<<i<<" ";
    }
    cout<<endl;
}