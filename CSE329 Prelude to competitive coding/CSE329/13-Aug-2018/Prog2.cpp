#include<iostream>
using namespace std;
void printarray(int b[],int n)
{
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<"\n";
}
bool found(int a[],int n)
{
    for(int j=0;j<6;j++)
        if(a[j]==n)
            return true;
    return false;
}
int main()
{
    int a[] = {0,2,5,3,4,7},n=6,max=7,b[8];
    for(int i=0;i<=(max+1);i++)
    {   if(found(a,i))
            b[i]=i;
        else
            b[i]=-1;
    }
    printarray(b,8);
}