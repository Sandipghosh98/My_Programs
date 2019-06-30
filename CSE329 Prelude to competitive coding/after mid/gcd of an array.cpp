#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}

int main()
{
int a[]={2,4,6};
int first=a[0],ans=-1;

for(int i=0;i<3;i++)
	first=gcd(first,a[i]);
	for(int i=0;i<3;i++)
	if(first==a[i]){
		ans=first;
		return ans;
		break;
	}
	cout<<ans;

//cout<<"not found";
	
}

