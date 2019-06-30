#include<bits/stdc++.h>
using namespace std;
// finding missing word using x-or operation
/*int main()
{
    int n,i,j,res,sec;
    cin>>n;
    int x;
    res=0,sec=0;
    for(i=1;i<n;i++)
    {
        cin>>x;
        res=res^x;
    }
    for(i=1;i<=n;i++)
    {
        sec=sec^i;
    }
    int rs=sec^res;
    cout<<rs<<endl;



    return 0;
}*/
// binary search related
/*
int bin_search(int a[],int low ,int high,int n,int val)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]==val)
        {
            return mid;
        }
        else if(val>a[mid])
            return bin_search(a,mid+1,high,n,val);
        else
            return bin_search(a,low,mid-1,n,val);
    }
    return -1;
}

int  main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<bin_search(a,0,n-1,n,4);
}
*/

// finding difference of number is present in array or not
/*
int bin_search(int a[],int low ,int high,int n,int val)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]==val)
        {
            return mid;
        }
        else if(val>a[mid])
            return bin_search(a,mid+1,high,n,val);
        else
            return bin_search(a,low,mid-1,n,val);
    }
    return -1;
}
int  main()
{
    int a[]={10,20,30,40,50};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        int index=bin_search(a,0,n-1,n,a[i]-40);
        if((i!=index) && (index!=-1))
        {
            cout<<a[i]<<" "<<a[index];
            break;
        }
    }
}
*/

int bin_search(int a[],int low ,int high,int n,int val)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]==val)
        {
            return mid;
        }
        else if(val>a[mid])
            return bin_search(a,mid+1,high,n,val);
        else
            return bin_search(a,low,mid-1,n,val);
    }
    return -1;
}

int  main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<bin_search(a,0,n-1,n,4);
}

