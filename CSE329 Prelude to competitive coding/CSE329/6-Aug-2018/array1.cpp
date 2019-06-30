#include<iostream>
using namespace std;
void insertinarray(int a[], int num, int pos)
{
    for(int i=4;i>pos;i--)
        a[i]=a[i-1];
    a[pos]=num;
}
void deletefromarray(int a[],int pos)
{
    for(int i=pos;i<4;i++)
        a[i]=a[i+1];
}
void showarray(int a[],int size)
{
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void linearsearch(int a[], int findnum)
{
    for(int i=0;i<4;i++)
    {
        if(a[i]==findnum)
        {
            cout<<"Position : "<<i+1<<"\n";
            break;
        }
    }
}
int main()
{
    int a[5]={1,2,3,4};
    
    int num,pos;
    cout<<"Enter a Number : ";
    cin>>num;
    cout<<"Enter It's position : ";
    cin>>pos;
    insertinarray(a,num,pos);
    showarray(a,5);

    cout<<"Enter Position of Element to Delete : ";
    cin>>pos;
    deletefromarray(a,pos);
    showarray(a,4);

    int findnum;
    cout<<"Enter a number to find : ";
    cin>>findnum;
    linearsearch(a,findnum);
}