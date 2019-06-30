#include<bits/stdc++.h>
using namespace std;
//int t=1;
long long int recu( long long int x, int long long n,long long int p){
 	long long int t=1;
 	//int n;
 //	n=e/2;
 x=x%p;
	while(n){
	
	if(n & 1){
	
		t=(t*x)%p;
	
	}
		n=n>>1;
		x=(x*x)%p;
	//	t=t*t;
	
}

return t;	
}

bool fermat(long long int n){
	if((n<=1) || (n==4) ) return false;
	if(n<=3) return true;
	for(int i=0;i<4;i++){
		long long int a=2+ rand() %(n-4);
		if(recu(a,n-1,n)!=1)
		return false;
	}
 return true;}


int main()
{
	int x,n,re;
	cin>>n;
	cin>>x;
	
//	re=recu(x,n,100);
	cout<<fermat(27)<<"  "<<fermat(31);
	
	
}
