#include<iostream>
using namespace std;
int main(){
int a[6]={0,2,5,3,4,7};
	//int t[6];
	int s=6/2;
	int e=0,f=0;
	for(int i=0;i<s;i++){
		cout<<e;
		f=a[e];
		a[e]=a[e+1];
		a[e+1]=f;
		e=e+2;
		cout<<"saxdd"<<e<<"  ";
	}
	int j=0;
	for(j=0;j<6;j++){
		
		cout<<"  "<<a[j];
	}
	int l=5;
	for(int i=0;i<s;i++){
		f=a[i];
		a[i]=a[l];
		a[l]=f;
		l--;
		
		
		
	}
	cout<<endl;
		for(j=0;j<6;j++){
		
		cout<<"  "<<a[j];
	}
	

	
	
	
	
	
	
	
	
}
