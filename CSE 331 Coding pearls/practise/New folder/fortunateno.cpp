#include<bits/stdc++.h>
using namespace std;

bool isprime(int fn)
{
	for(int i=2;i<=sqrt(fn);i++)
	{
		if(fn%i==0)
		{
			return false;
		}
	}
	return true;
}

int fortunate(int p[],int n)
{
	int pn=1;
	for(int i=0;i<n;i++)
	{
		pn=pn*p[i];
	}
	int fn=pn+2;
	while(1)
	{
		if(isprime(fn))
		{
			break;
		}
		else
		fn++;
	}
	return fn-pn;
}

int main()
{
	int t;
	cin>>t;
	while(t>0)
	{	
		int p[10]={2,3,5,7,11,13,17,19,23,29};
		int n;
		cin>>n;
		cout<<fortunate(p,n);
		t--; //test cases

		
	}
}
