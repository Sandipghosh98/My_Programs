#include<iostream>
using namespace std;

void del(int a[],int pos,int tot)
{
	int i;
	for(i=pos;i<tot;i++)
	{
		a[i]=a[i+1];
	}
	
}
void insert(int a[],int b,int c){
	for(int i=4;i>b;i--){
	a[i]=a[i-1];
	
}
a[b]=c;



}
int search(int a[],int d, int c){
	int i;
	
	for(int i=0;i<c;i++){
		if(a[i]==d){
		return 1;}
	
	}
}

int main(){

int a[5],i,b,c;
for(i=0;i<4;i++)
{
	cin>>a[i];	
}
cout<<"enter the no. u want 2 insert and the value";
cin>>b;
cin>>c;
b=b-1;
insert(a,b,c);
for(i=0;i<5;i++)
{
	cout<<a[i]<<" ";
	
}
del(a,b,5);
cout<<"\n";
for(i=0;i<4;i++)
{
	cout<<a[i]<<" ";
	
}
int e;
e=search(a,3,5);
if(e==1)
cout<<"found";
else
cout<<"not found";

}
