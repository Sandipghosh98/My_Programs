#include<iostream>
using namespace std;
int main(){

int a[]={1,2,3,4,5};
int b,c;
int n=sizeof(a)/sizeof(a[0]);
int i=0,k=0,j=0;
cin>>b;
cout<<b;
for(k=0;k<b;k++){
	c=a[0];
	cout<<"sd";
	for(j=0;j<5;j++){
		a[j]=a[j+1];
		cout<<"8521"<<endl;
	}
	a[4]=c;
}
for(j=0;j<5;j++){
	cout<<a[j]<<"  ";
}


}
