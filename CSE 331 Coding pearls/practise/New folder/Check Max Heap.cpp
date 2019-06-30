#include<bits/stdc++.h>
using namespace std;
bool checkMax(int a[],int n)
{
	int i=n;
	for(i=n;i>=1;i--)
	{
		if(i/2>=1 && a[i/2]<a[i])
		{
			return false;
		}
	}
	return true;
}
bool checkMin(int a[],int n)
{
	int i=n;
	for(i=n;i>=1;i--)
	{
		if(i/2>=1 && a[i/2]>a[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	int i,a[n];
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(checkMax(a,n))
	cout<<"Max Heap"<<endl;
	else
	cout<<"Note a Max Heap"<<endl;
	if(checkMin(a,n))
	cout<<"Min Heap"<<endl;
	else
	cout<<"Note a Min Heap"<<endl;
	return 0;
}
