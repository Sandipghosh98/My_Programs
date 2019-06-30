#include<iostream>
using namespace std;
int main(){

int a[]={1,2,3,4,5};
int b;
	cin>>b;
int c[5],d=0;
int i=0;
for(i=0;i<b;i++){
	c[i]=a[i];
}
for(i=0;i<(5-b);i++)
{
	a[i]=a[i+b];
}


for(i=b+1;i<5;i++){
	a[i]=c[i-b-1];
}
for(i=0;i<5;i++){
	cout<<"  "<<a[i];
}
/*
//i=5-b;
for(i=b;i<5;i++){
	c[d]=a[i-l];
	d++;
}
d=0;
for(i=b;i<5;i++){
	a[i]=c[i];
	d++;
}
for(i=0;i<5;i++){
	cout<<"  "<<a[i];
}*/
}
