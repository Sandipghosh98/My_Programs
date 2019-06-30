/*
    You are Given an input N and Two space Seperated 'N' Integers defines range of sub array.
    you have to reverse the sub arrays N times and print the final output.
*/
#include<iostream>
using namespace std;

void reverse_array(int a[],int start, int stop)
{
    for(int i=start;i<=stop/2;i++)
    {
        a[i] = a[i]+a[stop-i];
        a[stop-i] = a[i] - a[stop-i];
        a[i] = a[i] - a[stop-i];
    }
}
int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8}, size=8;

    int n,a,b;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        
    }
}