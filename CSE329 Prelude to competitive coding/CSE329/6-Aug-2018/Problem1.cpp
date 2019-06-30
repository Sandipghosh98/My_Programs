/*
    Given Two numbers, calculate the number of bits to be changed to convert first number to second?

    2   =   0010
                   2^15 =   1101(13)    =   1+1+0+1 =   3
    15  =   1111
*/
#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int x = a ^ b;
    int count=0;
    while(x)
    {
        count += x & 1;
        x >>=1;
    }
    cout<<"Count : "<<count<<"\n";
}