#include<iostream>
using namespace std;
void printarray(int b[],int n)
{
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<"\n";
}
int main()
{
    int a[]={0,2,5,3,9}, b[10], max=9, size=5;
    for(int i=0;i<max+1;i++)
        b[i]=0;
    for(int i=0;i<size;i++)
        b[a[i]] = 1;
    for(int i=0;i<max+1;i++)
    {
        if(b[i]==1)
            b[i]=i;
        else
            b[i]=-1;
    }
    printarray(b,max+1);
}