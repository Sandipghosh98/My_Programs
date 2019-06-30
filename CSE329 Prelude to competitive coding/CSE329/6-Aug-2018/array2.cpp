#include<iostream>
using namespace std;

void leftrotatearray(int a[], int size)
{
    int b[5];
    for(int i=0;i<size;i++)
        b[i]=a[i];
    for(int i=size;i<5;i++)
        a[i-size] = a[i];
    for(int i=1+size;i<5;i++)
        a[i]=b[i-size-1];

    // Wrong Function.
}
void showarray(int a[],int size)
{
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    int a[5] = {1,2,3,4,5}, direction, size;

    cout<<"Enter Size for Rotation : ";
    cin>>size;
    leftrotatearray(a, size);

    showarray(a,5);
}