// Find Out Maximum Sum out of all the Sub Arrays in an Array.
#include<iostream>
using namespace std;
int answer(int a[], int n)
{
    int tillnow=a[0],Max=a[0];
    for(int i=1;i<n;i++)
    {
        tillnow = max(a[i],tillnow+a[i]);
        Max = max(Max, tillnow);
    }
    return Max;
}
int main()
{
    int a[]={1,6,-3,4,5};
    cout<<answer(a,5);
}
//HW: Find The Starting and Ending Index of SubArray?
//HW: Find The Maximum Sum When Limit of the SubArray is Given?