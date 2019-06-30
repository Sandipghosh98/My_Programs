#include<iostream>
using namespace std;
void rotatearrayleft(int a[])
{
    int j,temp=a[0];
    for(j=0;j<5-1;j++)
        a[j]=a[j+1];
    a[j-1]=temp;
}
void printarray(int a[])
{
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    int a[]={1,2,3,4,5},n,size=sizeof(a)/sizeof(a[0]);
    cout<<"Enter Numbers of Left Rotation Required : ";
    cin>>n;
    for(int i=0;i<n;i++)
        rotatearrayleft(a);
    printarray(a);
}

// Time Complexity = O(n*l) where n = size of array, l = number of rotation.
// Space-Time Tradeof