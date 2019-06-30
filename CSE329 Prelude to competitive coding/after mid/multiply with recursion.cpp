#include<bits/stdc++.h>
using namespace std;
//int t=1;
 int recu(int x, int n){
 	int t=1;
 	//int n;
 //	n=e/2;
	if(n==1){
		return x;
	}
	if(n%2==0){
		t=recu(x,n/2)*recu(x,n/2);
	}
	else{
		t=recu(x,n/2)*recu(x,n/2)*x;
	//	t=t*t;
	}
	
	
	
}



int main()
{
	int x,n,re;
	cin>>n;
	cin>>x;
	
	re=recu(x,n);
	cout<<re;
	
	
}
