#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}

int main()
{
int ar[]={14,12,6};
int v,w;
v=gcd(2,4);
cout<<v;
w=gcd(v,6);
cout<<w;
//x=gcd(2)
for(int i=0;i<3;i++){
	if(w==ar[i]){
		return w;
	}
	
}
cout<<"not found";
	
}
